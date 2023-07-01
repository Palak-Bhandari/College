#include<iostream>
using namespace std;
class sparse{
	int arr[10][10];
	int row;
	int col;
	int n;
	int sp[20][3];
	public:
		sparse(){     
			n=0;
		}
		void accept();
		void convert_sparse();
		void display();
		sparse addition(sparse s2);
		sparse transpose();
		sparse multiplication(sparse s2);
};
void sparse :: accept(){
	int i,j;
	cout<<"Enter no of row and cols: ";
	cin>>row>>col;
	cout<<"Enter the elements: \n";
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			cin>>arr[i][j];
		}
	}
}
void sparse :: display(){
	int i,j;
	cout<<"\nDisplay:-\n";
	for(i=0;i<=n;i++){  // n is the no of non zero values(1 row of details ie why =n)
		for(j=0;j<3;j++){ // there are only 3 cols
			cout<<sp[i][j]<<" ";
        }
        cout<<"\n";
    } 
}
void sparse :: convert_sparse(){
	sp[0][0]=row; 
	sp[0][1]=col;
	int k=1,i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(arr[i][j]!=0){ // non zero values are added in sparse matrix
				sp[k][0]=i;
				sp[k][1]=j;
				sp[k][2]=arr[i][j];
				k++;n++;
			}
		}
	}
	sp[0][2]=n;
}
sparse sparse :: addition(sparse s2){    
    sparse s3;
	int i=1,j=1,k=1; 
	if(row!=s2.row || col!=s2.col){ // no of rows and col of s1 and s2 sparse do not match
		cout<<"Rows and cols do not match!!\n";
		return s3;
	}
	s3.sp[0][0]=row;
	s3.sp[0][1]=col;
	while(i<=n && j<=s2.n){
		if(sp[i][0]==s2.sp[j][0] && sp[i][1]==s2.sp[j][1]){ // row and col of s1 and s2 match then add values
			s3.sp[k][0]=sp[i][0];
			s3.sp[k][1]=sp[i][1];
			s3.sp[k][2]=sp[i][2]+s2.sp[j][2];
			i++;j++;k++;
		}
		else if(sp[i][0] == s2.sp[j][0]){ // rows match but col do not match
			if(sp[i][1]<s2.sp[j][1]){    // col of s1 is smaller than of s2
				s3.sp[k][0]=sp[i][0];
				s3.sp[k][1]=sp[i][1];
				s3.sp[k][2]=sp[i][2];
				i++;k++;
			}
			else{                       // col of s2 is smaller than of s1
				s3.sp[k][0]=s2.sp[j][0];
				s3.sp[k][1]=s2.sp[j][1];
				s3.sp[k][2]=s2.sp[j][2];
				j++;k++;
			}
		}
		else{                            // col match but row do not match
			if(sp[i][0] < s2.sp[j][0]){ // row of s1 is smaller than of s2
				s3.sp[k][0]=sp[i][0];
				s3.sp[k][1]=sp[i][1];
				s3.sp[k][2]=sp[i][2];
				i++;k++;
			}
			else{                      // row of s2 is smaller than of s1
				s3.sp[k][0]=s2.sp[j][0];
				s3.sp[k][1]=s2.sp[j][1];
				s3.sp[k][2]=s2.sp[j][2];
				j++;k++;
		    }
	    }
    }
	while(i<=n){  // add remaining non zero elements of s1 sparse matrix in s3
		s3.sp[k][0]=sp[i][0];
		s3.sp[k][1]=sp[i][1];
		s3.sp[k][2]=sp[i][2];
	    i++;k++;
	}
	while(j<=s2.n){ // add remaining non zero elements of s2 sparse matrix in s3
		s3.sp[k][0]=s2.sp[j][0];
		s3.sp[k][1]=s2.sp[j][1];
		s3.sp[k][2]=s2.sp[j][2];
		j++;k++;
	}
	s3.sp[0][2]=k-1; // for no of non zero elements of s3 sparse matrix
	s3.n=k-1;
	cout<<"\nAddition is :- ";
	return s3;	
}
sparse sparse :: transpose(){
	sparse s2;
	s2.sp[0][0] = col;
	s2.sp[0][1] = row;
	s2.sp[0][2] = sp[0][2];
	s2.row = col;          // exchange row and col 
	s2.col = row; 
	s2.n = n;
	int i,j,k = 1;
	for(i=0 ; i<col ; i++){
		for(j=1;j<=n;j++){
			if(sp[j][1] == i){
				s2.sp[k][0] = sp[j][1];  // exchange row and col values
				s2.sp[k][1] = sp[j][0];
				s2.sp[k][2] = sp[j][2];
				k++;
			}
		}
	}
	return s2;
}
sparse sparse :: multiplication(sparse s2){
	sparse s3;
	int i,j,t1,t2,t3 = 1,sum;
	if(sp[0][1]!=s2.sp[0][0]){ // col of 1st and row of 2nd must match
		cout<<"\n Cannot Multiply!\n";
		return s3;
	}
	s3.sp[0][0]=sp[0][0];    // row will be row of 1st matrix
	s3.sp[0][1]=s2.sp[0][1]; // col will be col of 2nd matrix
	s2 = s2.transpose();     
	for(i=0;i<s3.sp[0][0];i++){  // i is less than row of 1st matrix
		for(j=0;j<s3.sp[0][1];j++){  // j is less than col of 2nd matrix
			t1 = 1; //for 1st matrix 
			t2 = 1; //for 2nd matrix transpose
			sum = 0;
			int flag1=0,flag2=0;
			while(t1<=n){      
				if(sp[t1][0]==i){  //row value = to i 
					flag1=1;
					break;
				} t1++;
			}
			while(t2<=s2.n){
				if(s2.sp[t2][0] == j){ //row value = to j 
					flag2=1;
					break;
				} t2++;
			}
			if(flag1 == 1 && flag2 == 1){
				while(sp[t1][0]==i && s2.sp[t2][0]==j){ 
					if(sp[t1][1] == s2.sp[t2][1]){ //cols match
						sum = sum + sp[t1][2]*s2.sp[t2][2];
						t1++; 
						t2++;
					}
					else if(sp[t1][1]<s2.sp[t2][1]){ //col 2nd matrix greater than 1st matrix
						t1++;
					}
					else{   //col 1st matrix grater than 2nd matrix
						t2++;
					}
				}
				if(sum > 0){ 
					s3.sp[t3][0]=i;
					s3.sp[t3][1]=j;
					s3.sp[t3][2]=sum;
					t3++; // for answer matrix
				}
			}
		}
	}
	s3.sp[0][2] = t3 - 1;
	s3.n = t3 - 1;
	cout<<"\nMultiplication is :-";
	return s3;
}
int main(){
    sparse s1,s2,s3;
    int x,ch;
    do{
    	cout<<"\nEnter your choice:\n1.Accept Matrix\n2.Convert to Triplet form\n3.Display in triplet form\n4.Addition\n5.Transpose\n6.Multiplication\n7.Exit ";
    	cin>>ch;
    	switch(ch){
    		case 1: s1.accept();
    		        s2.accept();
    				break;
    		case 2: s1.convert_sparse();
    				s2.convert_sparse();
    				break;
    		case 3: s1.display();
    				s2.display();
    				break;
    		case 4: s3 = s1.addition(s2);
    				s3.display();
    				break;
    		case 5: cout << "\nTranspose is :- ";
					s3 = s2.transpose();
    				s3.display();
    				break;
    		case 6: s3 = s1.multiplication(s2);
    				s3.display();
    				break;
    		case 7: exit(0);
    				break;
    		default: cout<<"Invalid choice!";
		}
		cout<<"Press 1 to continue";
		cin>>x;	
	}while(x==1);
	return 0;
}
/*Enter your choice:
1.Accept Matrix
2.Convert to Triplet form
3.Display in triplet form
4.Addition
5.Transpose
6.Multiplication
7.Exit 1
Enter no of row and cols: 4 4
Enter the elements:
3 0 0 0
0 0 6 0
5 0 0 0
0 8 0 0
Enter no of row and cols: 4 4
Enter the elements:
0 0 0 1
8 0 0 0
0 0 4 0
7 0 0 0
Press 1 to continue1

Enter your choice:
1.Accept Matrix
2.Convert to Triplet form
3.Display in triplet form
4.Addition
5.Transpose
6.Multiplication
7.Exit 2
Press 1 to continue1

Enter your choice:
1.Accept Matrix
2.Convert to Triplet form
3.Display in triplet form
4.Addition
5.Transpose
6.Multiplication
7.Exit 3

Display:-
4 4 4
0 0 3
1 2 6
2 0 5
3 1 8

Display:-
4 4 4
0 3 1
1 0 8
2 2 4
3 0 7
Press 1 to continue1

Enter your choice:
1.Accept Matrix
2.Convert to Triplet form
3.Display in triplet form
4.Addition
5.Transpose
6.Multiplication
7.Exit 4

Addition is :-
Display:-
4 4 8
0 0 3
0 3 1
1 0 8
1 2 6
2 0 5
2 2 4
3 0 7
3 1 8
Press 1 to continue1

Enter your choice:
1.Accept Matrix
2.Convert to Triplet form
3.Display in triplet form
4.Addition
5.Transpose
6.Multiplication
7.Exit 5

Transpose is :-
Display:-
4 4 4
0 1 8
0 3 7
2 2 4
3 0 1
Press 1 to continue1

Enter your choice:
1.Accept Matrix
2.Convert to Triplet form
3.Display in triplet form
4.Addition
5.Transpose
6.Multiplication
7.Exit 6

Multiplication is :-
Display:-
4 4 4
0 3 3
1 2 24
2 3 5
3 0 64
Press 1 to continue1

Enter your choice:
1.Accept Matrix
2.Convert to Triplet form
3.Display in triplet form
4.Addition
5.Transpose
6.Multiplication
7.Exit 7

--------------------------------
Process exited after 87.06 seconds with return value 0
Press any key to continue . . .*/
