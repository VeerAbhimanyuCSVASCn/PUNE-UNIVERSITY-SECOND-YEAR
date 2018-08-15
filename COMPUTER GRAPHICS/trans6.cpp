#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>

using namespace std;

int triangle =1;
int quad     =0;
int active=0;
int input=0;

int xaxis[4],yaxis[4];
int xax[4],yax[4];

void shear(int x,int y)
{

    for(int i=0;i<input;i++)
    {
        xax[i] = xaxis[i] + x*yaxis[i];
        yax[i] = yaxis[i];


        xax[i]=xax[i];
        yax[i] =xax[i]*y +yax[i];

    }

}
void resize(int x,int y)
{

    for(int i=0;i<input;i++)
    {
        xax[i] = xaxis[i]*x;
        yax[i] = yaxis[i]*y;
        cout<<xax[i]<<endl;

    }
}

void tran(int x,int y)
{

    for(int i=0;i<input;i++)
    {
        xax[i] = xaxis[i]+x;
        yax[i] = yaxis[i]+y;

    }

}
void rota(int angle)
{

float r = (angle*3.14)/180;
    for(int i=0;i<input;i++)
    {
        xax[i] = xaxis[i]*cos(r) - yaxis[i]*sin(r) ;
        yax[i] = xaxis[i]*cos(r) + yaxis[i]*sin(r) ;
    }
}

void init()
{
    cout<<"\n\n\n..:: MENU::..\n\n1.TRIANGLE \n2.QUADRRILATERAL\n\n";
    switch(getch())
    {
    case '1':
        triangle=1;
        break;
    case'2':
        triangle=0;
        quad=1;
        break;
    }


    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,720,0,720);
    glMatrixMode(GL_MODELVIEW);

}




void menu()
{
    cout<<"1. TRANSLATE\n2.ROTATE\n3.SHEAR\n4.RESIZE";
    switch(getch())
    {
    case'1':
        cout<<"ENTER X ,y TO TRANSLATE - ";
        int xx,yy;
        cin>>xx>>yy;
        tran(xx,yy);
        break;
    case'2':
        cout<<"ENTER ANGLE OF ROTATION - ";
        int r;
        cin>>r;
        rota(r);
        break;
    case'3':
        cout<<"ENTER X ,y TO SHEAR - ";
        int xx2,yy2;
        cin>>xx2>>yy2;
        shear(xx2,yy2);
        break;
    case'4':
        cout<<"ENTER X ,y TO RESIZE - ";
        int xx22,yy22;
        cin>>xx22>>yy22;

        resize(xx22,yy22);
        break;
break;
    }
    cout<<endl;
}

void abhimanyu()
{
    glClear(GL_COLOR_BUFFER_BIT);


    if((quad==1 && input==4) || (input==3 &&triangle==1))
    {glBegin(GL_LINE_LOOP);
    for(int i=0;i<input;i++)
        glVertex2i(xaxis[i],yaxis[i]);
    glEnd();

    if(active==0)
    {menu();
    active=1;
    }
    }

    if(active==1)
    {glColor3f(1,0,0);
    glLineWidth(3);
        glBegin(GL_LINE_LOOP);
    for(int i=0;i<input;i++)
        {glVertex2i(xax[i],yax[i]);}
    glEnd();
    }


glFlush();
}


void mouse(int button,int state,int x,int y)
{
    y=720-y;

    if(input==3 && triangle==1)
    {
        goto ab;
    }

    if(input==4 && quad==1)
    {
        goto ab;
    }

    if(button==GLUT_RIGHT_BUTTON && state==GLUT_UP)
    {
        xaxis[input]=x;
        yaxis[input++]=y;
    }


    ab:
cout<<endl;

}

int main(int b,char* arg[])
{
    system("color f0");
    glutInit(&b,arg);
    glutInitWindowSize(720,720);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
    glutInitWindowPosition(150,1);
    glutCreateWindow("DISPLAY CHART");
    init();

    glutMouseFunc(mouse);
    glutDisplayFunc(abhimanyu);


    glutMainLoop();

    return 0;
}
