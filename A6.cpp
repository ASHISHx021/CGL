#include<iostream>
#include<GL/glut.h>
#include<cmath>

using namespace std;
int n,i,j,k;
float A[3][10];
float R[3][10];
float T[3][10];




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

void getdata(float A[3][10])
{
       cout<<"Enter the Number of Co-ordinates:-"<<endl;
       cin>>n;
 
       cout<<"Enter the values for matrix"<<endl;
       for (  i = 0; i<n; i++)
       {
	 for (  j = 0; j< 2; j++)
	 { 
	    cin>>A[j][i];
	  }

        }
     
}

void drawShape()
{  
    glBegin(GL_POLYGON);
    for (  i = 0; i<n; i++)
     {
	 glVertex2f(A[0][i],A[1][i]);
		
     }
    glEnd();

}
void multiply()
{
  for(i=0; j<3; i++)
   {
     for(j=0; i<n; j++)
      {
        R[j][i]=0;
        for(k=0; k<2; k++)
         {
          R[j][i]+=A[j][k]*T[k][i];
          }
        }
     }
}

void scale(){
	float sx;
	
	float sy;
	cout<<"Enter the value of sx: ";
	cin>>sx;
	
	cout<<"Enter the value of sy: ";
	cin>>sy;

	for ( int i = 0; i < 3; i++){
	
		for ( int j = 0; j < 3; j++){
		
			T[j][i] = 0;
		
		}
	
	}
	
	T[0][0] = sx;
	T[1][1] = sy;
	T[2][2] = 1;


	multiply();
	
	cout<<"Final product of multiplication"<<endl;
	for ( int i = 0; j < 3; i++){
	
		for ( int j = 0; i < 3; j++){
		
			cout<<R[j][i]<<endl;
		
		}
	
	}
	


}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	drawQuadrants();
	drawShape();

	glFlush(); 	
}

int main(int argc,char **argv)
{
        getdata(A);
        scale();
       
	glutInit(&argc,argv);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Transformation");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
} 
