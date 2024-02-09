#include <GL/glut.h>
#include <iostream>
using namespace std;
	int first=0;
	int x1,x2,y01,y02;
	int pt=0;
	float dx,dy, length;
void drawQuadrants()//for display 4 quadrants
{        glPointSize(6);
	 glBegin(GL_POINTS);
	 glVertex2i(-320,0);
	 glVertex2i(320,0);
	 glVertex2i(0,-240);
	 glVertex2i(0,240);
	 glVertex2i(0,0);
	 glEnd();
}

void DDA()
{ 
 if(abs(x2-x1)>=abs(y02-y01))
 {
   length=abs(x2-x1);
 }
 else
 {
   length=abs(y02-y01);
  }
  dx=(x2-x1)/length;
  dy=(y02-y01)/length;
 float x=x1+0.5;
  float y=y01+0.5; 
  int i=0;
  while(i<=length)
  {
    if (int(x)%2==0)
    {
    glPointSize(3);
   glBegin(GL_POINTS);
    glVertex2i(x,y);
   glEnd();
   }
     x=x+dx;
     y=y+dy;
     i=i+1;
  }
  glFlush();
}
void drawLine(int x1,int y01,int x2,int y02)
	{
	 glBegin(GL_LINES);
	 glVertex2i(x1,y01);
	 glVertex2i(x2,y02);
	 glEnd();
	}
void display()
	{
	glClear(GL_COLOR_BUFFER_BIT);
	drawQuadrants();
	DDA();
	}
void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{

		x1 = 0;
		y01 = 0;
		x2 = x-320;
		y02 = 240-y;
		drawLine(x1, y01, x2, y02);
       }

	else if(btn== GLUT_RIGHT_BUTTON)

	{
		exit;
		
	}

glFlush();
}
void myinit()
{
	glClearColor(0,0,0,0);
	gluOrtho2D(-320,320,-240,240);
}


int main(int argc,char** argv)
{
        cout<<"ENTER THE VERTICES :"<<endl;
cin>>x1;
cin>>y01;
cin>>x2;
cin>>y02;

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutCreateWindow("Draw Line With Mouse Click");
	myinit();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
} 
