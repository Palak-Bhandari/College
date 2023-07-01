#include<graphics.h> 
#include<conio.h> 
#include<dos.h> 
#include<process.h> 
int cx=300,cy=100,r=300;
int x=0,y,p;
int path(int dtn) {
    int x1,y1;
    setcolor(15);
    if(x>=y) {
        return 0;
    }
    cleardevice();
    circle(300,100,100);
    circle(300,100,105);
    circle(300,100,7);
    line(300,100,250,50);
    line(300,100,350,100);
    outtextxy(210,100,"9");
    outtextxy(380,100,"3");
    outtextxy(290,10,"12");
    outtextxy(300,180,"6");
    if(dtn==1) {
        circle(cx+x,cy+y,20);
        line(cx,cy,cx+x,cy+y);
    } else {
        circle(cx-x,cy+y,20);
        line(cx,cy,cx-x,cy+y);
    }
    delay(10);
    if(kbhit()) 
            exit(0);
    x++;
    if(p<0) 
            p+=2*x+1; 
	else {
        y--;
        p+=2*(x-y)+1;
    }
    x1=x;
    y1=y;
    path(dtn);
    cleardevice();
    circle(300,100,100);
    circle(300,100,105);
    circle(300,100,7);
    line(300,100,250,50);
    line(300,100,350,100);
    outtextxy(210,100,"9");
    outtextxy(380,100,"3");
    outtextxy(290,10,"12");
    outtextxy(300,180,"6");
    if(dtn==1) {
        circle(cx+x1,cy+y1,20);
        line(cx,cy,cx+x1,cy+y1);
    } else {
        circle(cx-x1,cy+y1,20);
        line(cx,cy,cx-x1,cy+y1);
    }
    delay(10);
    if(kbhit()) 
            exit(0);
    return(0);
}
int main() {
    int gd=DETECT,gm=DETECT;
    initgraph(&gd,&gm,NULL);   
    putpixel(300,100,4);
    while(1) {
        x=0;
        y=r;
        p=1-r;
        path(1);
        x=0;
        y=r;
        p=1-r;
        path(0);
    }
}
