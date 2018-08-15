#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>

using namespace std;
   float p=-100,flag=0;
void init()
{
    glClearColor(0,0.7,1,1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(1,720,1,720);
    glMatrixMode(GL_MODELVIEW);
}

void abhimanyu()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(0,0.5,0);
/*
    glBegin(GL_POLYGON);

        for(int i=0;i<360;i++)
            {glVertex2f(i*3,sin((i*((3.14)/180)))*450);}
    glEnd();
*/



    glBegin(GL_POLYGON);
glColor3f(0,0,0);
   glVertex2f(139+35,0);
    glVertex2f(139+35,354);
     glVertex2f(142+35,357);
      glVertex2f(142+35,0);

   glEnd();


glLoadIdentity();
   glTranslatef(0,p,0);

   glBegin(GL_POLYGON);
   glColor3f(0.9,0.59,0);
   glVertex2f(100+74,200+p);
   glVertex2f(100+74,230+p);
   glVertex2f(250+74,230+p);
   glVertex2f(250+74,200+p);
    glEnd();

    glBegin(GL_POLYGON);
   glColor3f(1,1,1);
   glVertex2f(100+74,200-30+p);
   glVertex2f(100+74,230-30+p);
   glVertex2f(250+74,230-30+p);
   glVertex2f(250+74,200-30+p);
    glEnd();

    glBegin(GL_POLYGON);
   glColor3f(0,1,0);
   glVertex2f(100+74,200-30*2+p);
   glVertex2f(100+74,230-30*2+p);
   glVertex2f(250+74,230-30*2+p);
   glVertex2f(250+74,200-30*2+p);
    glEnd();



    glBegin(GL_LINE_LOOP);
glColor3f(0,0,1);
   for (int i=0; i <= 360; i++)
   {
      float degInRad = i*(3.14/180);
      glVertex2f(cos(degInRad)*15+245,sin(degInRad)*15+185+p);
   }
glEnd();


glBegin(GL_LINES);

   glVertex2i(230,185+p);
   glVertex2i(260,185+p);
   glVertex2i(245,170+p);
   glVertex2i(245,200+p);

   glVertex2i(236,174+p);
   glVertex2i(256,198+p);

    glVertex2i(255,174+p);
   glVertex2i(236,198+p);

glEnd();


     if(230+p >=286)
    flag=1;

if(flag==0)
 p=p+0.1;


    glutSwapBuffers();
    glutPostRedisplay();
}

int main(int a,char *b[])
{
    system("color f0");
    glutInit(&a,b);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
    glutInitWindowSize(720,720);
    glutInitWindowPosition(1,1);
    glutCreateWindow("ABHIMANYU");
    init();
    glutDisplayFunc(abhimanyu);
    glutIdleFunc(abhimanyu);

    glutMainLoop();
    return 0;
}
