#include<iostream> 
#include<conio.h>
#include<graphics.h>
#include<math.h>
using namespace std; 
void display(int n, float c[][3]){
	float maxx,maxy;
	int i;
	maxx=getmaxx();
	maxy=getmaxy();
	maxx=maxx/2;
	maxy=maxy/2;
	i=0;
	while(i<n-1){
		line(maxx+c[i][0],maxy-c[i][1],maxx+c[i+1][0],maxy-c[i+1][1]);
		i++;
	}
	i=n-1;
	line(maxx+c[i][0],maxy-c[i][1],maxx+c[0][0],maxy-c[0][1]);
	setcolor(RED);
	line(0,maxy,maxx*2,maxy);
	line(maxx,0,maxx,maxy*2);
	setcolor(WHITE);
}
void mul(int n,float b[][3],float c[][3],float a[][3]){
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<3;j++)
			a[i][j]=0;
	for(i=0;i<n;i++)
		for(j=0;j<3;j++)
			for(k=0;k<3;k++)
				a[i][j]=a[i][j]+(c[i][k]*b[k][j]);
}
void translation(int n,float c[][3],float tx,float ty){
	int i;
	for(i=0;i<n;i++){
 		c[i][0]=c[i][0]+tx;
 		c[i][1]=c[i][1]+ty;
 	}
}
void scaling(int n,float c[][3], float sx,float sy){
	float b[10][3],a[10][3];
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			b[i][j]=0;
	b[0][0]=sx;
	b[1][1]=sy;
	b[2][2]=1;
	mul(n,b,c,a);
	setcolor(GREEN);
	display(n,a);
}
void rotation(int n,float c[][3],float ra){
	int i=0,j;
	float b[10][3],xp,yp,a[10][3];
	xp=c[0][0];
	yp=c[0][1];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			b[i][j]=0;
	b[0][0]=b[1][1]=cos(ra*3.14/180);
	b[0][1]=sin(ra*3.14/180);
	b[1][0]=-sin(ra*3.14/180);
	b[2][0]=(-xp*cos(ra*3.14/180))+(yp*sin(ra*3.14/180))+xp;
	b[2][1]=(-xp*sin(ra*3.14/180))-(yp*cos(ra*3.14/180))+yp;
	b[2][2]=1;
	mul(n,b,c,a);
	setcolor(GREEN);
	display(n,a);
}
void reflectx(int n,float c[][3]){
	int i=0,j;
	float b[10][3],a[10][3];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			b[i][j]=0;
	b[0][0]=b[2][2]=1;
	b[1][1]=-1;
	mul(n,b,c,a);
	setcolor(GREEN);
	display(n,a);
}
void reflecty(int n, float c[][3]){
	int i=0,j;
	float b[10][3],a[10][3];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			b[i][j]=0;
	b[1][1]=b[2][2]=1;
	b[0][0]=-1;
	mul(n,b,c,a);
	setcolor(GREEN);
	display(n,a);
}
void reflectorg(int n,float c[][3]){
	int i=0,j;
	float b[10][3],a[10][3];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			b[i][j]=0;
	b[0][0]=b[1][1]=-1;
	b[2][2]=1;
	mul(n,b,c,a);
	setcolor(GREEN);
	display(n,a);
}
void reflectyx(int n,float c[][3]){
	int i=0,j;
	float b[10][3],a[10][3];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			b[i][j]=0;
	b[0][1]=b[1][0]=b[2][2]=1;
	mul(n,b,c,a);
	setcolor(GREEN);
	display(n,a);
}
void reflectynegx(int n,float c[][3]){
	int i=0,j;
	float b[10][3],a[10][3];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			b[i][j]=0;
	b[0][1]=b[1][0]=-1;
	b[2][2]=1;
	mul(n,b,c,a);
	setcolor(GREEN);
	display(n,a);
}
void shearx(int n,float c[][3],float srx){
	int i=0,j;
	float b[10][3],a[10][3];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			b[i][j]=0;
	b[0][0]=b[1][1]=b[2][2]=1;
	b[1][0]=srx;
	mul(n,b,c,a);
	setcolor(GREEN);
	display(n,a);
}
void sheary(int n,float c[][3],float sry){
	int i=0,j;
	float b[10][3],a[10][3];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			b[i][j]=0;
	b[0][0]=b[1][1]=b[2][2]=1;
	b[0][1]=sry;
	mul(n,b,c,a);
	setcolor(GREEN);
	display(n,a);
}
int main(){
 	int i,j,ch,n,gd=DETECT,gm,p,z,choice;
 	float c[10][3],tx,ty,sx,sy,ra,srx,sry;
 	initgraph(&gd,&gm,(char*)""); 
 	cout<<"Enter number of vertices : \n";cin>>n;	
	for(i=0;i<n;i++){
		cout<<"\nEnter the co-ordinates "<<i<<" : ";
		cin>>c[i][0];
		cin>>c[i][1];
		c[i][2]=1;
 	}
	cleardevice();
	cout<<"\n1]Translation\n2]Scaling\n3]Rotation\n4]Reflection\n5]Shearing: ";cin>>ch;
	switch(ch){
		case 1: cout<<"\nEnter translation factor tx & ty :";
				cin>>tx>>ty;
				cleardevice();
				setcolor(WHITE);
				display(n,c);
				translation(n,c,tx,ty);
				setcolor(GREEN);
				display(n,c);
				getch();
				break;
		case 2: cout<<"\nEnter scaling factor sx & sy : ";
				cin>>sx>>sy;
			 	cleardevice();
			 	setcolor(WHITE);
			 	display(n,c);
			 	scaling(n,c,sx,sy);
			 	getch();
			 	break;
		case 3: cout<<"\nEnter the angle of rotation : ";
				cin>>ra;
				cleardevice();
				display(n,c);
				rotation(n,c,ra);
				getch();
				break;
		case 4: cleardevice();
				cout<<"\n1]Reflection about x axis\n2]Reflection about y axis\n3]Reflection about origin";
				cout<<"\n4]Reflection about a line y=x\n5]Reflection about a line y=-x: ";cin>>choice;
				switch(choice){
					case 1:	cleardevice();
							setcolor(WHITE);
							display(n,c);
							reflectx(n,c);
							getch();
							break;				 
					case 2: cleardevice();
							setcolor(WHITE);
							display(n,c);
							reflecty(n,c);
							getch();
							break;				 
					case 3: cleardevice();
							setcolor(WHITE);
							display(n,c);
							reflectorg(n,c);
							getch();
							break;				 
					case 4: cleardevice();
							setcolor(WHITE);
							display(n,c);
							reflectyx(n,c);
							getch();
							break;
					case 5:	cleardevice();
							setcolor(WHITE);
							display(n,c);
							reflectynegx(n,c);
							getch();
							break;
					default:cout<<"Wrong choice!";
				}
				break;
		case 5: int z;
				cleardevice();
				cout<<"\n1]Shearing about x axis\n2]Shearing about y axis: ";cin>>z;
				switch(z){
					case 1: cout<<"Enter the shearing factor about x axis: ";
							cin>>srx;
							cleardevice();
							setcolor(WHITE);
							display(n,c);
							shearx(n,c,srx);
							getch();
							break;						
					case 2: cout<<"Enter the shearing factor about y axis: ";
							cin>>sry;
							cleardevice();
							setcolor(WHITE);
							display(n,c);
							sheary(n,c,sry);
							getch();
							break;
					default:cout<<"Wrong choice!";
				}
			break;
		case 6: exit(0);
		default:cout<<"Invalid Choice!";
	}	
	getch();
 	closegraph();
 	return 0;
}
