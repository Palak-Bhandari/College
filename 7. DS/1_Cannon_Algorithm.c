#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
int main(int argc,char *argv[])
{
   int rank,size,row=0,column=0,count=0,i=0,j=0,k=0;
   char ch;
   float *A,*B,*C,a=0,b=0,c=0,n;
   FILE *fp;
   MPI_Init(NULL,NULL);
   MPI_Comm_size(MPI_COMM_WORLD,&size); // total no of processes in specified communicator - mpi_comm_world
   MPI_Comm_rank(MPI_COMM_WORLD,&rank); // get rank of the calling process
   if(rank==0)
   {
    fp=fopen("A.txt","r");
    while(fscanf(fp,"%f",&n)!=-1)
    { 
      ch=fgetc(fp);
      if(ch=='\n'){ row=row+1; }
      count++;
    }
    column=count/row; 
    if(count!=size) { printf("No of Proc must be equal to %d\nCode terminated",count); exit(0); }
    fseek( fp, 0, SEEK_SET );
    A=(float*)calloc(sizeof(float),row*column);
    B=(float*)calloc(sizeof(float),row*column);
    k=0;
    printf("A matrix:\n");
    for(i=0;i<row;i++) 
    {
       for(j=0;j<column;j++)
       {
          fscanf(fp,"%f",&n);
          A[k]=n;
          printf("%f\t",A[k]);
          k++; 
       } 
       printf("\n"); 
    }
    fclose(fp);
    k=0;
    printf("\nB matrix:\n");
    fp=fopen("B.txt","r");
    for(i=0;i<row;i++) 
    {
       for(j=0;j<column;j++)
       {
          fscanf(fp,"%f",&n);
          B[k]=n; 
          printf("%f\t",B[k]);
          k++; 
       }
       printf("\n");  
    } 
    fclose(fp);
   }
   // If the process is rank 0, read matrices A and B from files A.txt and B.txt, and print their values.
   MPI_Bcast(&row,1,MPI_INT,0,MPI_COMM_WORLD); // Broadcast the number of rows to all processes.
   int periods[]={1,1}; // Both vertical and horizontal movement; 
   int dims[]={row,row};
   int coords[2]; /* 2 Dimension topology so 2 coordinates */
   int right=0, left=0, down=0, up=0;    // neighbor ranks
   /*
   Create a 2D Cartesian topology using MPI_Cart_create. Scatter rows of matrices A and B 
   to different processes. Set up the Cartesian coordinates and find neighbors for each process. 
   Perform communication to exchange boundary values (a and b) between neighboring processes.
   */
   MPI_Comm cart_comm; // Declare an MPI communicator cart_comm for the Cartesian topology.
   MPI_Cart_create(MPI_COMM_WORLD,2,dims,periods,1,&cart_comm ); // Create a 2D Cartesian communicator
   MPI_Scatter(A,1,MPI_FLOAT,&a,1,MPI_FLOAT,0,cart_comm);
   MPI_Scatter(B,1,MPI_FLOAT,&b,1,MPI_FLOAT,0,cart_comm);
   // Scatter the rows of matrices A and B among the processes in the Cartesian communicator. 
   // Each process receives a single element 
   MPI_Comm_rank(cart_comm,&rank);
   // Get the rank of the current process in the Cartesian communicator.
   MPI_Cart_coords(cart_comm,rank,2,coords);
   // Get the Cartesian coordinates of the current process. 
   MPI_Cart_shift(cart_comm, 1, coords[0], &left,&right);
   MPI_Cart_shift(cart_comm, 0, coords[1], &up,&down);
   /* Find the ranks of the neighboring processes in both dimensions (left, right, up, down) 
   in the Cartesian communicator. MPI_Cart_shift is used to find the ranks of the source and 
   destination processes for communication along the specified dimension. */
   MPI_Sendrecv_replace(&a,1,MPI_FLOAT,left,11,right,11,cart_comm,MPI_STATUS_IGNORE);
   MPI_Sendrecv_replace(&b,1,MPI_FLOAT,up,11,down,11,cart_comm,MPI_STATUS_IGNORE);
   /*Perform communication to exchange boundary values (a and b) between neighboring processes. 
   MPI_Sendrecv_replace is used to simultaneously send a value to one neighbor and receive a value 
   from another neighbor.*/
   c = c + a*b;
   // Loop over the rows to perform the matrix multiplication using the scattered rows and boundary values
   for(i=1;i<row;i++)
   {
     MPI_Cart_shift(cart_comm, 1, 1, &left,&right);
     MPI_Cart_shift(cart_comm, 0, 1, &up,&down);
     MPI_Sendrecv_replace(&a,1,MPI_FLOAT,left,11,right,11,cart_comm,MPI_STATUS_IGNORE);
     MPI_Sendrecv_replace(&b,1,MPI_FLOAT,up,11,down,11,cart_comm,MPI_STATUS_IGNORE);
     c = c + a*b;
   }
   // Allocate memory for the result matrix C and gather the calculated values from all processes to process 0.
   C=(float*)calloc(sizeof(float),row*row);
   MPI_Gather(&c,1,MPI_FLOAT,C,1,MPI_FLOAT,0,cart_comm);
   if(rank==0) // If the process is rank 0, print the resulting matrix C.
   {
      k=0; 
      printf("\nA * B:\n");
      for(i=0;i<row;i++)
      {
         for(j=0;j<row;j++)
         {
            printf("%f\t",C[k]);
            k++;
         }    
         printf("\n");
      }
   }
   MPI_Finalize();
   return 0;
}
/*
Install MPI:
https://rantahar.github.io/introduction-to-mpi/setup.html#:~:text=On%20Ubuntu%2C%20open%20a%20terminal%20and%20run%3A%20sudo,you%20Open%20MPI%20is%20properly%20installed%20by%20running%3A
Ref:
https://github.com/suraj-deshmukh/cannon-algorithm-in-c-using-mpi
Compile : mpicc cannon.c -o cannon (only for C file)
Execute : mpirun -np 16 ./cannon OR mpiexec -np 16 ./cannon (Works for both C and C++)
For CPP:
Compile : mpic++ cannon.c -o cannon(Runs for C file too)
*/