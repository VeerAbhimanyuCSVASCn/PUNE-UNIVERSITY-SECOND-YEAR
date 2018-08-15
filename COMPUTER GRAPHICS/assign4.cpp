
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
using namespace std;

int putpixel(int x,int y)
{
    glColor3f(0,0,0);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    return 0;
}

int bresalham(int x1,int y1,int x2,int y2)
{
    cout<<"ENTERD";
    int dx = abs(x2-x1);
    int dy = abs(y2-y1);

    int signx,signy;
    if(x2>=x1)
    signx =1;
    else
        signx =-1;

    if(y2>=y1)
    signy =1;
    else
        signy =-1;
    int s=0;
    if(dx>=dy)
    {
        s = 2*dy-dx;
        putpixel(x1,y1);
        for(int i=0;i<dx;i++)
        {
            if(s>=0)
            {
                x1=x1+signx;
                y1 = y1+signy;
                s = s+2*(dy-dx);
            }

            else
            {

                x1=x1+signx;
                s = s+2*(dy);
            }
            putpixel(x1,y1);
        }
    }

 if(dx<dy)
    {
        s = 2*dx-dy;
        putpixel(x1,y1);
        for(int i=0;i<dy;i++)
        {
            if(s>=0)
            {
                y1=y1+signy;
                x1 = x1+signx;
                s = s+2*(dx-dy);
            }

            else
            {

                y1=y1+signy;
                s = s+2*(dx);
            }
            putpixel(x1,y1);
        }
    }
    return 0;
}

int color[3];
int floodfiller(int x,int y)
{

    glReadPixels(x,y,1,1,GL_RGB,GL_INT,color);
    if(color[0]==color[1]&&color[1]==color[2]&&color[2]==0)
        return 0;
        putpixel(x,y);
 cout<<color[0]<<endl;
    floodfiller(x+1,y);
    floodfiller(x-2,y);
    floodfiller(x,y+1);
    floodfiller(x,y-2);
    return 0;

}


void abhimanyu()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    int a=0;

    for(int i=0;i<=4;i++)
    {
        bresalham(75*i*cos(45*3.14/180)-a*sin(45*3.14/180)+250,75*i*cos(45*3.14/180)+a*sin(45*3.14/180),75*i*cos(45*3.14/180)-75*4*sin(45*3.14/180)+250,75*i*cos(45*3.14/180)+75*4*sin(45*3.14/180));
        bresalham(a*cos(45*3.14/180)-75*i*sin(45*3.14/180)+250,a*cos(45*3.14/180)+75*i*sin(45*3.14/180),75*4*cos(45*3.14/180)-75*i*sin(45*3.14/180)+250,75*4*cos(45*3.14/180)+75*i*sin(45*3.14/180));
    }

   
        floodfiller(250,250);
        floodfiller(350,250);

        floodfiller(150,250);
        floodfiller(250,150);

        floodfiller(250,50);
        floodfiller(350,250);

        floodfiller(250,350);
        floodfiller(150,150);
        floodfiller(350,150);


    glutSwapBuffers();

}





void inti()
{
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,720,0,720);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,720,720);
}

int main(int a,char*b[])
{
    system("color f0");
    glutInit(&a,b);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(720,720);
    glutInitWindowPosition(1,1);
    glutCreateWindow("abhimanyu");
    inti();
    glutDisplayFunc(abhimanyu);
    glutMainLoop();
    return 0;
}
