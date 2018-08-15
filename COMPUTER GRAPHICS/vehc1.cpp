#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;

void reshape(int w,int h)
{
     glViewport(0,0,w,h);
    glutPostRedisplay();
}

void init()
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glMatrixMode(GL_PROJECTION);

    gluOrtho2D(0,720,0,720);
    glMatrixMode(GL_MODELVIEW);
}
float x=-80;
float p=720,Q=50;
float P=720,q=30;
float n=-80,r=0;
float j=0;
void abhimanyu()
{
     glClearColor(0,0.8-j/250,1-j/250,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glColor3f(0,1-j/450,0);
        glLoadIdentity();
        glBegin(GL_POLYGON);

        for(float i=0;i<180;i=i+0.1)
        {
            x=x+0.6;
            glVertex3f(x,sin(i*3.14/180)*200,0);
        }

        glEnd();

        glLoadIdentity();

        r=r+0.1;
        n=n+0.6;
      glTranslatef(-n,sin(r*3.14/180)*200,0);




        glColor3f(1,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(15+P,4+Q,0);
         glVertex3f(15+P,33+Q,0);
         glVertex3f(16+P,33+Q,0);
         glVertex3f(17+P,33.5+Q,0);
         glVertex3f(18+P,34+Q,0);glVertex3f(19+P,34.5+Q,0);glVertex3f(20+P,35+Q,0);
         glVertex3f(55+P,35+Q,0);
         glVertex3f(85+p,63+q,0);
          glVertex3f(145+p,63+q,0);
          glColor3f(0.6,0.6,0.6);
          glVertex3f(195+p,35+q,0);
        glVertex3f(222+p,34.5+q,0);
         glVertex3f(223+p,34+q,0);
         glVertex3f(224+p,33.5+q,0);

        glVertex3f(225+p,33+q,0);
        glColor3f(1,0,0);
          glVertex3f(226+p,4+q,0);
        glEnd();

        glColor3f(0,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(56+p,30+Q-8,0);
        glVertex3f(136+p-5,30+q-1,0);
        glVertex3f(136+p-5,57+q+3,0);
        glColor3f(1,1,1);
        glVertex3f(86+p,57+q+3,0);
        glEnd();

        glColor3f(0,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(141+P,30+Q+6,0);
        glVertex3f(141+p,57+q-25,0);
        glColor3f(1,1,1);
        glVertex3f(188+p,30+q-3,0);
        glEnd();


        glBegin(GL_POLYGON);
      for (int i=0; i <= 360; i++)
   {
      float degInRad = i*(3.14/180);
      glColor3f(0,0,0);
      glVertex3f(cos(degInRad)*20+ p+75,sin(degInRad)*20+q+5,0);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(cos(degInRad)*14+ p+75,sin(degInRad)*14+q+5,0);
   }
        glEnd();

          glBegin(GL_POLYGON);
      for (int i=0; i <= 360; i++)
   {
      float degInRad = i*(3.14/180);
      glColor3f(0,0,0);
      glVertex3f(cos(degInRad)*20+ p+158,sin(degInRad)*20+q+5,0);
      glColor3f(0.3,0.3,0.4);
      glVertex3f(cos(degInRad)*14+ p+158,sin(degInRad)*14+q+5,0);
   }
        glEnd();


        glLoadIdentity();

        glTranslatef(j,-j-50,0);
        glBegin(GL_POLYGON);
              for (int i=0; i <= 360; i++)
   {
      float degInRad = i*(3.14/180);
      glColor3f(1,1,0);
      glVertex3f(cos(degInRad)*30+j+358,sin(degInRad)*30+350,-0.5);
   }
        glEnd();

        j=j+0.03;

x=-80;
    glutSwapBuffers();
    glutPostRedisplay();

}

int main(int b,char *c[])
{
    glutInit(&b,c);
    glutInitWindowSize(720,720);
    glutInitWindowPosition(1,1);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("abhimanyu'animation");
    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(abhimanyu);
    glutMainLoop();
    return 0;
}

