#include<graphics.h> 
#include<conio.h>
#include<iostream>
using namespace std;
// 1) simple CG program using inbuilt function display A,E,F,H,I,K,L,M,N,T,X,Y,Z
// 2) display concentric circles, decorate hut - Hut drawing
int main() {
  int gd = DETECT,gm;
  initgraph(&gd, &gm, (char*)"");  // Draw Hut  
  setcolor(WHITE);
  rectangle(150,180,250,300);  //rectangle(left,top,right,bottom)
  rectangle(250,180,420,300); 
  rectangle(180,250,220,300);
  line(200,100,150,180);      //line(x1,y1,x2,y2)
  line(200,100,250,180);
  line(200,100,370,100);
  line(370,100,420,180);
  getch();
  closegraph(); 
  return 0;
}
// gm is Graphics mode which is a computer display mode that generates image using pixels.
// DETECT is a macro defined in "graphics.h" header file
// initgraph initializes the graphics system by loading a graphics driver from disk
// closegraph function closes the graphics mode and deallocate all memory allocated by graphics system.
