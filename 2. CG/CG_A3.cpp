//Develop a program for polygon filling 
#include<iostream>
#include<conio.h>
#include<graphics.h>
using namespace std;
struct edge{            //Define the structure to store the edges
	int x1,y1,x2,y2,flag;
};
void scan_line(){
	int n,i,j,k,x[10],y[10],ymax=0,ymin=480,yy,temp;
	struct edge ed[10],temped;
	float dx,dy,m[10],x_int[10],inter_x[10];
	cout<<"Enter the number of vertices of the graph: "; 
	cin>>n; 
	cout<<"Enter the vertices\n";
	for(i=0;i<n;i++) {
		cout<<"x"<<i<<": "; 
		cin>>x[i];
		cout<<"y"<<i<<": "; 
		cin>>y[i];
		if(y[i]>ymax)
			ymax = y[i];
		if(y[i]<ymin)
			ymin=y[i];
		ed[i].x1=x[i];
		ed[i].y1=y[i];
	}
	for(i=0;i<n-1;i++) {       //store the edge information
		ed[i].x2=ed[i+1].x1;
		ed[i].y2=ed[i+1].y1;
		ed[i].flag=0;
	}
	ed[i].x2=ed[0].x1;
	ed[i].y2=ed[0].y1;
	ed[i].flag=0;
	for(i=0;i<n-1;i++) {        //Check for y1>y2, if not interchnge y1 and y2
		if(ed[i].y1 < ed[i].y2){
			temp=ed[i].x1;
			ed[i].x1=ed[i].x2;
			ed[i].x2=temp;
			temp=ed[i].y1;
			ed[i].y1=ed[i].y2;
			ed[i].y2=temp;
		}
	}
	for(i=0;i<n;i++) {           //Draw the polygon
		line(ed[i].x1,ed[i].y1,ed[i].x2,ed[i].y2);
	}
	for(i=0;i<n-1;i++) {        //sorting of edges in the order of y1,y2,x1
		for(j=0;j<n-1;j++){
			if(ed[j].y1<ed[j+1].y1) {
				temped=ed[j];
				ed[j]=ed[j+1];
				ed[j+1]=temped;
			}
			if(ed[j].y1 == ed[j+1].y1) {
				if(ed[j].y2<ed[j+1].y2) {
					temped=ed[j];
					ed[j]=ed[j+1];
					ed[j+1]=temped;
				}
				if(ed[j].y2==ed[j+1].y2) {
					if(ed[j].x1<ed[j+1].x1) {
						temped=ed[j];
						ed[j]=ed[j+1];
						ed[j+1]=temped;
					}
				}
			}
		}
	}
	for(i=0;i<n;i++) {          //calculating 1/slope of each edge and storing top
		dx=ed[i].x2-ed[i].x1;
		dy=ed[i].y2-ed[i].y1;
		if(dy==0)
			m[i]=0;
		else
			m[i]=dx/dy;
		inter_x[i]=ed[i].x1;
	}                          //making the Actual edges
	yy=ymax;
	while(yy > ymin){
		for(i=0;i<n;i++) {
			if(yy > ed[i].y2 && yy <= ed[i].y1) {
				ed[i].flag=1; 
			}
			else
				ed[i].flag=0;
		}
		j=0;
		for(i=0;i<n;i++) {
			if(ed[i].flag==1) {
				if(yy == ed[i].y1) {
					x_int[j] = ed[i].x1;         //x_int[j] == ed[i].x1;
					j++; 
					if(ed[i-1].y1 == yy && ed[i-1].y1<yy) {
						x_int[j]=ed[i].x1;
						j++; 
					}
					if(ed[i+1].y1==yy && ed[i+1].y1<yy){
						x_int[j]=ed[i].x1;
						j++; 
					}
				}
				else {
					x_int[j]=inter_x[i]+(-m[i]);
					inter_x[i]=x_int[j];
					j++; 
				} 
			}
		}
		for(i=0;i<j;i++) {                 //sorting the x intersaction
			for(k=0;k<j-1;k++) {
				if(x_int[k]>x_int[k+1]) {
					temp=(int)x_int[k];
					x_int[k]=x_int[k+1];
					x_int[k+1]=temp;
				}	
			}
		}
		for(i=0;i<j;i=i+2) {               //extracting pairs of values to draw lilnes
			line((int)x_int[i],yy,(int)x_int[i+1],yy);
		}
		yy--;
		delay(20);
	}	
}
void flood_fill(int x,int y,int fillColor, int defaultColor) {
    if(getpixel(x,y) == defaultColor)  {  
        putpixel(x,y,fillColor);  
        flood_fill(x+1,y,fillColor,defaultColor);  
        flood_fill(x-1,y,fillColor,defaultColor);  
        flood_fill(x,y+1,fillColor,defaultColor);  
        flood_fill(x,y-1,fillColor,defaultColor);  
    }  
}
void boundary_fill(int x, int y, int fill_color,int boundary_color){
    if(getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color){
        putpixel(x, y, fill_color);
        boundary_fill(x + 1, y, fill_color, boundary_color);
        boundary_fill(x, y + 1, fill_color, boundary_color);
        boundary_fill(x - 1, y, fill_color, boundary_color);
        boundary_fill(x, y - 1, fill_color, boundary_color);
    }
}
int main(){
	int gd = DETECT,gm,ch;
	int n,x1,x2,y1,y2,r;
	cout<<"Enter Choice:\n1.Scan Line Algorithm\n2.Flood Fill Algorithm\n3.Boundary Fill Algorithm\n4.Exit\n";
	cin>>ch;
	switch(ch) {
		case 1: initgraph(&gd, &gm, (char*)"");
				scan_line();
				break;
		case 2: initgraph(&gd,&gm,NULL); 
				cout<<"Enter the coordinates for rectangle: \n";
				cin>>x1>>y1>>x2>>y2;
				rectangle(x1,y1,x2,y2);  
				flood_fill(x1+5,y1+5,BLUE,0); 
				break;
		case 3: initgraph(&gd, &gm, (char*)"");
				cout<<"Enter the coordinates for circle center and radius: \n";
				cin>>x1>>y1>>r;
		        circle(x1, y1, r);
    			boundary_fill(x1, y1, BLUE, 15);
    			delay(100);
				break;
		case 4: exit(0);
				break;
		default:cout<<"Invalid choice!";
	}
	getch();
	closegraph();
	return 0;
}
