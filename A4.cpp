#include<iostream>
#include<GL/glut.h>
using namespace std;


int x1, Y1, x2, y2;
float color[3];
float bgcolor[3]={1,1,1};
float fillcolor[3]={1, 1, 1};



void init()
{
	glClearColor(0.5,0.5,0,0);
	gluOrtho2D(0,640,0,480);
}


void drawHollowPolygon()
{
  glColor3f(1,1,1);
	glBegin(GL_LINE_LOOP);
	
    		glVertex2i(x1,Y1);
   		glVertex2i(x1,y2);
   		glVertex2i(x2,y2);
   		glVertex2i(x2,Y1);
   		
   	 glEnd();
    	glFlush();
}

void setpixel(int x,int y,float fillcolor[3])
{
	
	glBegin(GL_POINT);
	glColor3fv(fillcolor);
		glVertex2i(x,y);
	glEnd();
	glFlush();
}

void getpixel(int x, int y, float color[3])
{
  glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);
  
    
  }
    
    
 void Boundaryfill(int x,int y,float fillcolor[3],float bgcolor[3])
{
	
	getpixel(x,y,color);
	if(color[0]!=bgcolor[0]&&color[1]!=bgcolor[1]&&color[2]!=bgcolor[2])
	{ 
		setpixel(x,y,fillcolor);
		Boundaryfill(x,y+1,fillcolor,bgcolor );
		Boundaryfill(x+1,y,fillcolor,bgcolor);
		Boundaryfill(x,y-1,fillcolor,bgcolor);
		Boundaryfill(x-1,y,fillcolor,bgcolor);
		Boundaryfill(x+1,y+1,fillcolor,bgcolor);
		Boundaryfill(x-1,y+1,fillcolor,bgcolor);
		Boundaryfill(x-1,y-1,fillcolor,bgcolor);
		Boundaryfill(x+1,y-1,fillcolor,bgcolor);
		
		
	}
	

}
   


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawHollowPolygon();
	Boundaryfill(60,80,fillcolor, bgcolor);
	
	glFlush();
}



int main(int argc ,char **argv)
{
        cout<<"Enter the value of X1, Y1:-";
	cin>>x1>>Y1;
	cout<<"Enter the value of X2, Y2:-";
	cin>>x2>>y2;

	glutInit(&argc,argv);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Polygon");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}










