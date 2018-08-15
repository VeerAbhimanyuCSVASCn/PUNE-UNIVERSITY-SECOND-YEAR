#include<iostream>
#include<GL/glut.h>
using namespace std;

int c=100,d=100,a=10,b=10;
int term =1;
void inti()
{
    glPointSize(2);
    cout<<"\n\n\n..::MENU::..";
    cout<<"\n\n1. BRESALHAM's ALGORITHM\n2.DDA ALGORITHM\n\n";
    cin>>term;
    cout<<"ENTER THE BOTTOM MOST POINT ";
    cin>>a>>b;
    cout<<"ENTER THE TOP MOST POINT ";
    cin>>c>>d;

    glClearColor(0.5f,0.5,0,1);
    glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}


int maximum(int a,int b)
{
    if(a>b)
        return a;
    return b;
}


void pixelizer(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void line2(int x1,int y1,int x2,int y2)
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



void line(int x1,int y1,int x2,int y2)
{
    int x = x1;
    int y = y1;

    int dx = abs(x2-x1);
    int dy = abs(y2 - y1);

    int sx=1,sy=1;
    if(x2-x1 < 0 )
        sx=-1;
    if(y2-y1 < 0)
        sy = -1;

    int g =0,i=1;

    if(dx > dy)
    {
        pixelizer(x,y);
        g = (2*dy) - dx;

        while(i<dx)
        {
            if(g>=0)
            {
                x=x+sx;
                y=y+sy;
                g=g+ 2*(dy-dx);
            }
            else
            {
                x=x+sx;
                g=g+(2*dy);
            }
            i++;
            pixelizer(x,y);
        }
    }



    else
    {
        pixelizer(x,y);
        g = (2*dx) - dy;

        while(i<dy)
        {
            if(g>=0)
            {
                y=y+sy;
                x=x+sx;
                g=g+ 2*(dx-dy);
            }
            else
            {
                y=y+sy;
                g=g+(2*dx);
            }
            i++;
            pixelizer(x,y);
        }
    }

}





void rectangled(int a,int b,int c,int d)
{system("color f0");

if(term==1)
{
    line(a,b,a,d);
    line(a,d,c,d);
    line(c,d,c,b);
    line(c,b,a,b);

    line(a,(b+d)/2,(a+c)/2,d);
    line((a+c)/2,d,c,(d+b)/2);
    line(c,(d+b)/2,(c+a)/2,b);
    line((c+a)/2,b,a,(b+d)/2);

    line((3*a+c)/4 , (3*d+b)/4 ,(3*c+a)/4 , (3*d+b)/4);
    line((3*c+a)/4 , (3*d+b)/4 , (3*c+a)/4 , (3*b+d)/4);
    line( (3*c+a)/4 ,(3*b+d)/4 , (3*a+c)/4 , (3*b+d)/4);
    line ((3*a+c)/4 , (3*b+d)/4 ,(3*a+c)/4 , (3*d+b)/4);

}

if(term==2)
    {line2(a,b,a,d);
    line2(a,d,c,d);
    line2(c,d,c,b);
    line2(c,b,a,b);

    line2(a,(b+d)/2,(a+c)/2,d);
    line2((a+c)/2,d,c,(d+b)/2);
    line2(c,(d+b)/2,(c+a)/2,b);
    line2((c+a)/2,b,a,(b+d)/2);

    line2((3*a+c)/4 , (3*d+b)/4 ,(3*c+a)/4 , (3*d+b)/4);
    line2((3*c+a)/4 , (3*d+b)/4 , (3*c+a)/4 , (3*b+d)/4);
    line2( (3*c+a)/4 ,(3*b+d)/4 , (3*a+c)/4 , (3*b+d)/4);
    line2 ((3*a+c)/4 , (3*b+d)/4 ,(3*a+c)/4 , (3*d+b)/4);
    }
}

void abhimanyu()
{
    glClear(GL_COLOR_BUFFER_BIT);
    rectangled(a,b,c,d);
glFlush();
}

int main(int a,char *b[])
{
    system("Color f0");
    glutInit(&a,b);
    glutInitWindowSize(720,720);
    glutInitWindowPosition(1,1);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutCreateWindow("ASSIGNMENT 1");

    inti();
    glutDisplayFunc(abhimanyu);

    glutMainLoop();
    return 0;
}
