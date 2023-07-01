#include<conio.h>
#include<graphics.h>
void car(int x, int c, int f, int r){
	setcolor(c);
	line(x + 150, 100 + r, x + 242, 100 + f);
	line(x + 150, 100 + r, x + 120, 150 + r);
	line(x + 242, 100 + f, x + 280, 150 + f);
	line(x + 196, 100 + f, x + 196, 150 + f);
	line(x + 100, 150 + r, x + 320, 150 + f);
	line(x + 100, 150 + r, x + 100, 200 + r);
	line(x + 320, 150 + f, x + 320, 200 + f);
	line(x + 100, 200 + r, x + 110, 200 + r);
	line(x + 320, 200 + f, x + 310, 200 + f);
	line(x + 270, 200 + f, x + 150, 200 + r);
	circle(x + 130, 200 + r, 17);
	circle(x + 290, 200 + f, 17);
}
int main(){
	int gd = DETECT, gm = DETECT, i = -200;
	int y=0,p=0,r=0;
	initgraph(&gd, &gm, NULL);
	line(0,220,640,220);
	line(0,225,640,225);
	setfillstyle(SOLID_FILL,8);
	floodfill(0,222,15);
	car(i,15,0,0);
	while(!kbhit()) {
		car(i++,0,p,r);
		if(i>0 && i<50){
			car(i,15,y,0);
			p = y;
		}
		else{
			p = 0;
			r = 0;
			y = 0;
			car(i, 15,0,0);
		}
		delay(20); 
	}
}

/*
#include<conio.h>
#include<dos.h>
#include<graphics.h>
void car(int x, int c, int f, int r){
	setcolor(c);
	line(x + 150, 100 + r, x + 242, 100 + f);
	ellipse(x + 242, 105 + f, 0, 90, 10, 5);
	line(x + 150, 100 + r, x + 120, 150 + r);
	line(x + 252, 105 + f, x + 280, 150 + f);
	line(x + 100, 150 + r, x + 320, 150 + f);
	line(x + 100, 150 + r, x + 100, 200 + r);
	line(x + 320, 150 + f, x + 320, 200 + f);
	line(x + 100, 200 + r, x + 110, 200 + r);
	line(x + 320, 200 + f, x + 310, 200 + f);
	arc(x + 130, 200 + r, 0, 180, 20);
	arc(x + 290, 200 + f, 0, 180, 20);
	line(x + 270, 200 + f, x + 150, 200 + r);
	circle(x + 130, 200 + r, 17);
	circle(x + 290, 200 + f, 17);
}
int main(){
	int gd = DETECT, gm = DETECT, i = -200;
	int iy=0, prv_iy=0, prv_iry=0;
	initgraph(&gd, &gm, NULL);
	ellipse(318, 220, 0, 180, 15, 8);
	line(0,220,640,220);
	setfillstyle(SOLID_FILL,RED);
	floodfill(318,215,15);
	car(i,15,0,0);
	while(!kbhit()) {
		car(i++, 0,prv_iy,prv_iry);
		if(i>0 && i<50){
			car(i,15,iy,0);
			prv_iy = iy;
			if(i>25){
				if(i%2==0)
					iy++; 
				}
			else{
				if(i%2==0)
					iy--; 
			} 
		}
		else if(i>160 && i<210) {
			car(i,15,0,iy);
			prv_iry = iy;
			if(i>185) {
				if(i%2==0)
					iy++; 
			}
			else {
				if(i%2==0)
					iy--; 
			}
		}
		else if(i>500){
			break;
		}
		else{
			prv_iy = 0;
			prv_iry = 0;
			iy = 0;
			car(i, 15,0,0);
		}
		delay(20); 
	}
}
*/
