#include <GL/glut.h>
#include<unistd.h>
#include<iostream>

using namespace std;

int xmax,xmin,ymax,ymin;
float x[15],y[15], m[30], xx[25],yy[25];


int i,n;


void init()
{
	glClearColor(1,1,1,1);
	gluOrtho2D(0,640,0,480);
}

void getdata()
{
  cout<<"Enter the Co-ordinates of Window:-"<<" ";
  cin>>xmin>>ymin>>xmax>>ymax;
  
  cout<<"Enter the Number of vertices:"<<" ";
  cin>>n;
  
  if(n<3)
  {
    cout<<"Enter the No. of vertices greater than 2";
    exit(0);
  }

  for(i=0; i<n; i++)
  {
   cout<<"Enter the Vertex:"<<i+1<<" ";
   cin>>x[i]>>y[i];
  }
   x[i]=x[0];y[i]=y[0];
 }


/*void drawClippingWindo()  
{
	glColor3f(1,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex2i(100,100);
		glVertex2i(300,100);
		glVertex2i(300,300);
		glVertex2i(100,300);
	glEnd();
	glFlush();
}


void drawPolygon()
{
  
  glBegin(GL_POLYGON);
    glVertex2i(x1,Y1);
    glVertex2i(x1,y2);
    glVertex2i(x2,Y1);
    glVertex2i(x2,y2);
   glEnd();
   glFlush();
 }*/  
   
void display1()
{ 
 
   
  glColor3f(1.0,0.0,0.0);
   glBegin(GL_POLYGON);
     for(i=0;i<n;i++)
      {
         glVertex2i(x[i],y[i]);
      }
    glEnd(); 
    
     glColor3f(1.0,1.0,1.0);
   glBegin(GL_LINE_LOOP);
     glVertex2i(xmin,ymin);
     glVertex2i(xmax,ymin);
     glVertex2i(xmax,ymax);
     glVertex2i(xmin,ymax);
    
   glEnd();
    glFlush(); 
 }
 
  void clearScreen()
  {
   //usleep(2000);
   glClearColor(0.0,0.0,0.0,1.0);
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   }
 
 void slope()
 {
    for(i=0;i<n;i++)
   {
     if((x[i+1]-x[i])==0)
     
        m[i]=0;
       
    else 
     {
      m[i]=(y[i+1]-y[i])/(x[i+1]-x[i]);
     }
   }
 } 
 
void lclip()
{
  int k=0;
    slope();
  for(i=0;i<n;i++)
    {
     if(xmin<x[i]&&xmin<x[i+1])
      {
         xx[k]=x[i+1];
         yy[k]=y[i+1];
         k++;
      }
     else if(x[i]>xmin&&x[i+1]<xmin)
      {
           xx[k]=xmin;
           yy[k]=y[i]+m[i]*(xmin-x[i]);
           k++;
       }  
      else if(x[i]<xmin&&x[i+1]>xmin)
       {
             xx[k]=xmin;
           yy[k]=y[i]+m[i]*(xmin-x[i]);
           k++;
           
           xx[k]=x[i+1];
          yy[k]=y[i+1];
          k++;
       }
     }
         n=k;
    for(i=0;i<n;i++)
      {
        x[i]=xx[i];
        y[i]=yy[i];
    }
 }
 
/*void rclip()
{
  int k=0;
    slope();
  for(i=0;i<n;i++)
    {
     if(xmin>x[i]&&xmin>x[i+1])
      {
         xx[k]=x[i+1];
         yy[k]=y[i+1];
         k++;
      }
     else if(x[i]<xmin&&x[i+1]>xmin)
      {
           xx[k]=xmin;
           yy[k]=y[i]+m[i]*(xmin-x[i]);
           k++;
       }  
      else if(x[i]>xmin&&x[i+1]<xmin)
       {
             xx[k]=xmin;
           yy[k]=y[i]+m[i]*(xmin-x[i]);
           k++;
           
           xx[k]=x[i+1];
          yy[k]=y[i+1];
          k++;
       }
     }
         n=k;
    for(i=0;i<n;i++)
      {
        x[i]=xx[i];
        y[i]=yy[i];
    }
 }
 */
void display()
{
	//display1();
	//clearScreen();
	lclip();
	//rclip();
	display1();
	//ClearScreen();
	//glFlush();
	
}
  int main(int argc,char**argv)
    {
        getdata();
      glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
       glutInitWindowSize(640,480);
        glutInitWindowPosition(100,100);
     glutCreateWindow("Clipping");
      glutDisplayFunc(display);
       init();
       glutMainLoop();
      return 0;
  }

