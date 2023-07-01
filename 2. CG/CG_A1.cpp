#include<graphics.h>
#include<conio.h>
#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int gd = DETECT, gm,choice;
	int x,y,xinc,yinc;
	int xa,ya,xb,yb,steps,dx,dy,i,t,xend,p;
	int wy,wx,x1,y1,x2,y2;
	cout<<"Enter your choice:\n1.DDA Thin Line\n2.DDA dotted line\n3.DDA dashed line\n4.Bresenham thin line\n5.Bresenham dotted line\n6.Bresenham dashed line\n7.Thick line\n8.Exit: ";
	cin>>choice;
	switch(choice){
		case 1: cout<<"DDA Thin Line:-\n";
				cout<<"Enter value of xa ya xb yb: ";
			    cin>>xa>>ya>>xb>>yb;
			    initgraph(&gd, &gm, (char*)"");
				dx = xb-xa;
				dy = yb-ya;
				if(abs(dx)>=abs(dy)){
					steps = abs(dx);
				}
				else{
					steps = abs(dy);
				}
				xinc = dx/steps;
				yinc = dy/steps;
				x = xa;
				y = ya;
				for(i=0;i<steps;i++){
					putpixel(x,y,WHITE);
					x = x + xinc;
					y = y + yinc;	
				}
				break;
		case 2: cout<<"DDA Dotted Line:-\n";
				cout<<"Enter value of xa ya xb yb: ";
				cin>>xa>>ya>>xb>>yb;
				initgraph(&gd, &gm, (char*)"");
				dx = xb-xa;
				dy = yb-ya;
				if(abs(dx)>=abs(dy)){
					steps = abs(dx);
				}
				else{
					steps = abs(dy);
				}
				xinc = dx/steps;
				yinc = dy/steps;
				x = xa;
				y = ya;
				for(i=0;i<steps;i++){
					if(i%2==0){
					putpixel(x,y,BLACK);
					x = x + xinc;
					y = y + yinc;		
					}
					else{
					putpixel(x,y,WHITE);
					x = x + xinc;
					y = y + yinc;
					}	
				}
				break;
		case 3: cout<<"DDA Dashed Line:-\n";
				cout<<"Enter value of xa ya xb yb: ";
				cin>>xa>>ya>>xb>>yb;
				initgraph(&gd, &gm, (char*)"");
				dx = xb-xa;
				dy = yb-ya;
				if(abs(dx)>=abs(dy)){
					steps = abs(dx);
				}
				else{
					steps = abs(dy);
				}
				xinc = dx/steps;
				yinc = dy/steps;
				x = xa;
				y = ya;
				for(i=0;i<steps;i++){
					if(i%7==0){
						putpixel(x,y,BLACK);
						x = x + xinc;
						y = y + yinc;		
					}
					else{
						putpixel(x,y,WHITE);
						x = x + xinc;
						y = y + yinc;
					}	
				}
				break;
		case 4: cout<<"Bresenham Thin Line:-\n";
				cout<<"Enter value of xa ya xb yb: ";
	    		cin>>xa>>ya>>xb>>yb;
	    		initgraph(&gd, &gm, (char*)"");
	    		dx = abs(xb-xa);
				dy = abs(yb-ya);
				p = 2*dy - dx;
				if(xa > xb) {
					x = xb;
					y = yb;
					xend = xa;
				}
				else {
					x = xa;
					y = ya;
					xend = xb;
				}
				putpixel(x,y,WHITE);
				while(x < xend){
					x = x+1;
					if(p<0){
						p = p + 2*dy;
					}
					else{
						y=y+1;
						p = p + 2*(dy-dx);
					}
					putpixel(x,y,WHITE);	
				}
				break;
		case 5: cout<<"Bresenham Dotted Line:-\n";
				cout<<"Enter value of xa ya xb yb: ";
				cin>>xa>>ya>>xb>>yb;
				initgraph(&gd, &gm, (char*)"");
				dx = abs(xb-xa);
				dy = abs(yb-ya);
				p = 2*dy - dx;
				if(xa > xb) {
					x = xb;
					y = yb;
					xend = xa;
				}
				else {
					x = xa;
					y = ya;
					xend = xb;
				}
				putpixel(x,y,WHITE);
				while(x < xend){
					x = x+1;
					if(p<0){
						p = p + 2*dy;
					}
					else{
						y=y+1;
						p = p + 2*(dy-dx);
					}
					if(x%2 != 0) {
					putpixel(x,y,WHITE);
				    }
				}
				break;
		case 6: cout<<"Bresenham Dashed Line:-\n";
				cout<<"Enter value of xa ya xb yb: ";
			    cin>>xa>>ya>>xb>>yb;
			    initgraph(&gd, &gm, (char*)"");
			    dx = abs(xb-xa);
				dy = abs(yb-ya);
				p = 2*dy - dx;
				if(xa > xb) {
					x = xb;
					y = yb;
					xend = xa;
				}
				else {
					x = xa;
					y = ya;
					xend = xb;
				}
				putpixel(x,y,WHITE);
				while(x < xend){
					x = x+1;
					if(p<0){
						p = p + 2*dy;
					}
					else{
						y=y+1;
						p = p + 2*(dy-dx);
					}
					if(x%7 != 0) {
					putpixel(x,y,WHITE);
				    }
				}
				break;
		case 7: cout<<"Thick Line:-\n";
				cout<<"Enter value of xa ya xb yb: ";
				cin>>x1>>y1>>x2>>y2;
				cout<<"Enter the required thickness: ";
			    cin>>t;
				initgraph(&gd, &gm, (char*)"");
				line(x1,y1,x2,y2);
				if((y2-y1)/(x2-x1) < 1) {
					wy = (t-1)*sqrt(pow((x2-x1),2)+pow((y2-y1),2))/(2*fabs(x2-x1));
					for(i=0;i<wy;i++){
						line(x1,y1-i,x2,y2-i);
						line(x1,y1+i,x2,y2+i);
					}
				}
				else{
					wx = (t-1)*sqrt(pow((x2-x1),2)+pow((y2-y1),2))/(2*fabs(y2-y1));
					for(i=0;i<wx;i++){
						line(x1-i,y1,x2-i,y2);
						line(x1+i,y1,x2+i,y2);
					}
				}
				break;
		case 8: exit(0);
		        break;
		default: cout<<"Invalid Choice!"<<endl; 
	}
	getch();
	closegraph();
	return 0;
}
