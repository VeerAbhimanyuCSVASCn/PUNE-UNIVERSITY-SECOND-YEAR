#include<iostream>
#include<list>
#include<GL/glut.h>
using namespace std;
list <int>newaxis;
int a=-1,b=-1,c=-1,d=-1,e=-1,f=-1;
int r=0;
float color[3] = {1,1,1};
void inti()
{
    glPointSize(2);

    glClearColor(0.5f,0.5,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 720, 0, 720);
}



void pixelizer(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

int maximum(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

void line(int x1,int y1,int x2,int y2)
{
    int dx = x2-x1;
    int dy = y2-y1;
    float xinc = (float)dx / maximum(abs(dx),abs(dy));
    float yinc = (float)dy / maximum(abs(dx),abs(dy));

    float x = x1;
    float y = y1;
    pixelizer(x1,y1);
    for(int i=1 ; i < maximum(abs(dx),abs(dy)) ; i++)
    {
        x=x+xinc;
        y=y+yinc;
        x1=x+0.5;
        y1=y+0.5;
        pixelizer(x1,y1);
    }
}



void abhimanyu()
{

    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0);
    glVertex2i(0,0);
    glColor3f(0,1,0);
    glVertex2i(50,50);

    glColor3f(0,0,1);
    glVertex2i(100,0);
    glEnd();

glColor3f(color[0],color[1],color[2]);
    if(r==1)
    {
         a=newaxis.front();
        newaxis.pop_front();
        b=newaxis.front();
        newaxis.pop_front();
        system("cls");
        cout<<a<<"  "<<b<<endl;
        e=a;
        f=b;

            while(!newaxis.empty())
            {
               c= newaxis.front();
                 newaxis.pop_front();

                d=newaxis.front();
                    newaxis.pop_front();
                cout<<c<<"  "<<d<<endl;

                line(a,b,c,d);
                a=c;
                b=d;
            }
            line(a,b,e,f);
    }

    glFlush();

}

void colorchoser(int x,int y)
{
glReadPixels(x,720-y,1,1,GL_RGB,GL_FLOAT,color);
cout<<x<<"  "<<y<<"  "<<color[0]<<"  "<<color[1]<<"   "<<color[2];
}

void clickings(int ButtonNo , int ON_OR_OFF ,int xaxis , int yaxis )
{
    if(ON_OR_OFF == GLUT_DOWN )
    {

        if( ButtonNo == GLUT_RIGHT_BUTTON)
       {
           if(xaxis<=100 && 720-yaxis <=100)
           {

               colorchoser(xaxis,yaxis);
               goto ab;
           }


           r=0;
      a=xaxis;
      b=yaxis;
        cout<<"ENTER - "<<a<<"  "<<720-b<<endl;
        pixelizer(a,720-b);
        c=a;
        d=720-b;
        newaxis.push_back(a);
        newaxis.push_back(720-b);
        cout<<newaxis.size();
       }
    }


    if(ON_OR_OFF == GLUT_DOWN )
    {
         if(ButtonNo == GLUT_LEFT_BUTTON)
        r=1;

    }
ab:
    glutPostRedisplay();

}

int main(int a,char *b[])
{
    system("Color f0");
    glutInit(&a,b);
    glutInitWindowSize(720,720);
    glutInitWindowPosition(1,1);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutCreateWindow("ASSIGNMENT 3");

    inti();
    glutDisplayFunc(abhimanyu);


    glutMouseFunc  (clickings);
    glutMainLoop();
    return 0;
}
