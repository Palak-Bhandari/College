/*
NAME: Palak Vikas Bhandari
Seat No: S214072
Problem Statement: Write a C++ program for the following pattern using Bresenham’s Line drawing algorithm
				   The alphabets(H, I, K)
*/
#include<graphics.h>
#include<math.h>
int sign(int x) 
{
	if(x>0)
	 return 1;
	else if(x<0)
	 return -1;
	else
	 return 0;
}
void Bresenham_line(int x1,int y1, int x2, int y2) // Bresenham line drawing 
{
	int x,y,dx,dy,swap,temp,s1,s2,p,i;
	x=x1;
	y=y1;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	s1=sign(x2-x1);
	s2=sign(y2-y1);
	swap=0;
	putpixel(x1,y1,WHITE);
	if(dy>dx)  
	{
		temp=dx;
		dx=dy;
		dy=temp;
		swap=1;
	}
	p=2*dy-dx; // initial decision parameter
	for(i=0;i<dx;i++)
	{
		putpixel(x,y,WHITE);
		while(p>=0)  // if decision parameter is greater than or equaal to 0
		{
			p=p-2*dx;
			if(swap)
				x+=s1;
			else
				y+=s2;
		}  
		p=p+2*dy;   // if decision parameter is less than 0
		if(swap)
			y+=s2;
		else
			x+=s1;
	}
	putpixel(x2,y2,WHITE);
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
	//H
	Bresenham_line(50,100,50,300);
	Bresenham_line(50,200,150,200);
	Bresenham_line(150,100,150,300);
	
	//I
	Bresenham_line(250,100,300,100);
	Bresenham_line(250,300,300,300);
	Bresenham_line(275,100,275,300);
	
	//K
	Bresenham_line(400,100,400,300);
	Bresenham_line(400,200,500,100);
	Bresenham_line(400,200,500,300);
	
	getch();
	closegraph();
	return 0;
}
