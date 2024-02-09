#include<iostream>
#include<GL/glut.h>
using namespace std;
int first=0;
float x2,x1,y2,Y1,length,dx,dy;
float x,y;
float e;
int pt=0;

void init()
{
glClearColor(0,0,0,0);
gluOrtho2D(-320,320,-240,240);
}

void drawQuadrants()
{
glBegin(GL_LINES);
glVertex2i(-320,0);
glVertex2i(320,0);

glVertex2i(0,-240);
glVertex2i(0,240);
glEnd();
}

void DDA()
{
 if(abs(x2-x1)>=abs(y2-Y1))
 {
   length=abs(x2-x1);
 }
 else
 {
   length=abs(y2-Y1);
  }
  dx=(x2-x1)/length;
  dy=(y2-Y1)/length;
  x=x1+0.5;
  y=Y1+0.5; 
  int i=0;
  while(i<=length)
  {
    if (int(x)%2==0)
    {
   glBegin(GL_POINTS);
    glVertex2i(x,y);
   glEnd();
   }
     x=x+dx;
     y=y+dy;
     i=i+2;
  }
  glFlush();
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
drawQuadrants();
DDA();
}

int main(int argc,char **argv)
{
cout<<"ENTER THE VERTICES :"<<endl;
cin>>x1;
cin>>Y1;
cin>>x2;
cin>>y2;

glutInit(&argc,argv);
glutInitWindowSize(640,480);
glutInitWindowPosition(100,100);
glutCreateWindow("DDA");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
