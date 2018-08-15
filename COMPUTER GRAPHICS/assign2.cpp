#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>

using namespace std;
int tx,ty,angle,length;

int init()
{
    cout<<"ENTER THE INITAL POINT x - ";
    cin>>tx;
    cout<<"\nENTER THE INITAL POINT Y - ";
    cin>>ty;
    cout<<"\nENTER THE LENGTH OF TRRIANGLE's SIDE - ";
    cin>>length;
     cout<<"\nENTER THE ANGLE OF ROTATED TRIANGLE - ";
    cin>>angle;

    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,720,0,720);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,720,720);
    return 0;
}

int pixelizer(int x,int y)
{
    glColor3f(0,0,0);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    return 0;
}


int DDA(int x1,int y1,int x2,int y2)
{
    float dx = x2-x1;
    float dy = y2-y1;
    float step = max (abs(dx),abs(dy));
    dx=dx/step;
    dy=dy/step;

    for(int i=0;i<=step;i++)
    {
        pixelizer(x1+(dx)*i,y1+(dy)*i);
    }
    return 0;
}

int breselham(int radius,int cx,int cy)
{
    int x=0;
    int y=radius;
    int s = 3 - (2*radius);
    while(y>x)
    {
        if(s>=0)
        {
             x=x+1;
            s = s+(4*(x-y))+10;
            y=y-1;
        }

        else
        {
             x=x+1;
            s = s+(4*x)+6;
        }


            pixelizer(x+cx,y+cy);
            pixelizer(-x+cx,y+cy);
            pixelizer(-x+cx,-y+cy);
            pixelizer(x+cx,-y+cy);

            pixelizer(y+cx,x+cy);
            pixelizer(y+cx,-x+cy);
            pixelizer(-y+cx,-x+cy);
            pixelizer(-y+cx,x+cy);


    }
return 0;
}

void abhimanyu()
{
    glClear(GL_COLOR_BUFFER_BIT);

    DDA(tx,ty,(length)*(cos(angle*3.14/180))+tx,length*(sin(angle*3.14/180))+ty);
    DDA((length)*(cos(angle*3.14/180))+tx,length*(sin(angle*3.14/180))+ty,(length)*(cos((60+angle)*3.14/180))+tx,length*(sin((angle+60)*3.14/180))+ty);
    DDA((length)*(cos((60+angle)*3.14/180))+tx,length*(sin((angle+60)*3.14/180))+ty,tx,ty);
   int centerx,centery;

   centerx = ((length/2)/(cos(30*3.14/180)))*(cos((angle+30)*3.14/180))+tx;
    centery = ((length/2)/(cos(30*3.14/180)))*(sin((angle+30)*3.14/180))+ty;
    breselham((length/2)/(cos(30*3.14/180)),centerx,centery);
    breselham((length/4)/(cos(30*3.14/180)),centerx,centery);
    glutSwapBuffers();

}
int main(int b,char *c[])
{
    system("color f0");
    glutInit(&b,c);
   glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
    glutInitWindowSize(720,720);
    glutInitWindowPosition(1,1);
    glutCreateWindow("Abhimanyu' window");
    init();
    glutDisplayFunc(abhimanyu);
    glutMainLoop();
return 0;
}
