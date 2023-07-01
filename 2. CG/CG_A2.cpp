#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;
void PlotPoints1(int xc,int x,int yc,int y,int c){
	putpixel(xc + x, yc + y, c);
	putpixel(xc + y, yc + x, c);
	putpixel(xc - y, yc + x, c);
	putpixel(xc - x, yc + y, c);
	putpixel(xc - x, yc - y, c);
	putpixel(xc - y, yc - x, c);
	putpixel(xc + y, yc - x, c);
	putpixel(xc + x, yc - y, c);
}
void BresenhamCircle(int xc, int yc, int radius) {
	int x = 0;
	int y = radius;
	int d = 3 - (2*radius);  
    PlotPoints1(xc, x, yc, y, 7);   
    while(x <= y) {  
        if(d<=0)  
        	d=d+(4*x)+6;    
    else {  
        d=d+(4*x)-(4*y)+10;  
        y=y-1;  
    }  
    x=x+1;  
    PlotPoints1(xc, x, yc, y, 7);    
    }	
}
void MidptCircle(int xc, int yc, int radius,int c) {
    int x = radius;
    int y = 0;
    int err = 0;
    while (x >= y)	{
		PlotPoints1(xc, x, yc, y, c);
		if (err <= 0) {
    		y += 1;
    		err += 2*y + 1;
		}
		if (err > 0) {
    		x -= 1;
    		err -= 2*x + 1;
		}
    }
}
void oc(){
	MidptCircle(150, 150, 50, 1);  //circle(300, 300, 100); blue
	MidptCircle(200, 200, 50, 14); //circle(400, 400, 100); yellow
	MidptCircle(260, 150, 50, 0);  //circle(520, 300, 100); black
	MidptCircle(310, 200, 50, 2);  //circle(620, 400, 100); green
	MidptCircle(370, 150, 50, 4);  //circle(740, 300, 100); red
}
void fig_1(){
	float x=200,y=200,r=100;
	MidptCircle(x,y,r,7);
	line(x,y-r,x-2*r/3,y+2*r/3);
	line(x,y-r,x+2*r/3,y+2*r/3);
	line(x+2*r/3,y+2*r/3,x-2*r/3,y+2*r/3);
}
int main()
{
	int gd = DETECT, gm,choice;
	cout<<"Enter your choice:\n1.Bresenham Circle\n2.Mid Point Circle\n3.Olympic Symbol\n4.Geometrical Figure\n5.Exit\n";
	cin>>choice;
	int x,y,r,xc,yc;
	switch(choice) {
		case 1: cout<<"Enter radius of circle: ";
				cin>>r;
				cout<<"Enter co-ordinates x and y: ";
				cin>>x>>y;
				initgraph(&gd, &gm,NULL);
				outtextxy(10,10," Bresenham Circle ");  
				BresenhamCircle(x, y, r);
				break;
		case 2: cout<<"Enter radius of circle: ";
				cin>>r;
				cout<<"Enter co-ordinates x and y: ";
				cin>>x>>y;
				initgraph(&gd, &gm,NULL);
				outtextxy(10,10," Mid Point Circle ");
				MidptCircle(x, y, r, 7);
				break;
		case 3: initgraph(&gd, &gm, NULL);
				setbkcolor(LIGHTGRAY);
				cleardevice();
				oc();
				break;
		case 4: initgraph(&gd, &gm, NULL);
		        fig_1();
				break;
		case 5: exit(0);
				break;
		default: cout<<"Invalid Choice!";
	}
	getch();
	closegraph();
	return 0;	
}
