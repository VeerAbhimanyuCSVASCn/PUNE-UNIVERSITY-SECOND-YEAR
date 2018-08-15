/*


//_______________________________________FILE 1 _______________________________________________



#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>

using namespace std;

void init()
{
    glClearColor(0,0.7,1,1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(1,720,1,720);
    glMatrixMode(GL_MODELVIEW);
}
 float inc=0.041;

float angle=0;
void abhimanyu()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glColor3f(1,0.6,0);
    glBegin(GL_POLYGON);
    glVertex2f(270,480-70);
    glVertex2f(270,190-70);
    glVertex2f(360,100-70);
    glVertex2f(450,190-70);
    glVertex2f(450,480-70);
    glEnd();


    glColor3f(0,0,0);
    glLineWidth(10);
    glBegin(GL_LINE_LOOP);
    glVertex2f(270,480-70);
    glVertex2f(270,190-70);
    glVertex2f(360,100-70);
    glVertex2f(450,190-70);
    glVertex2f(450,480-70);
    glEnd();

   glLoadIdentity();
 if(angle>225)
      {
        angle=225;
        inc=-inc;
      }
      if(angle<135)
      {
        angle=135;
        inc=-inc;
      }
      angle+=inc;




     double radian=angle*3.14/180;
      float y2=75*cos((double) radian);
      float x2=75*sin((double) radian);
//      midPoint(x2,y2,30);
      glColor3f(0.0,0.0,0.0);
      glLineWidth(2);
      glBegin(GL_POLYGON);
      {
           glVertex2f((720/2)-5,(720/2)+(720/4)-25);

            glVertex2f((720/2)-5+x2,(720/2)+(720/4)-450+y2);

            glVertex2f((720/2)+5+x2,(720/2)+(720/4)-450+y2);
            glVertex2f((720/2)+5,(720/2)+(720/4)-25);

      }
      glEnd();


      glBegin(GL_POLYGON);

            for (int i=0; i <= 360; i++)
   {
      float degInRad = i*(3.14/180);
      glVertex2f(cos(degInRad)*15+ 360+x2,sin(degInRad)*15+110-25+y2);
   }
    glEnd();


        glLoadIdentity();
    glColor3f(0.5,0.0,0.1);
    glBegin(GL_POLYGON);
   glVertex2f(360,690-150);

    glVertex2f(200,590);
    glVertex2f(200,420);
   glVertex2f(360,340);

 glVertex2f(360+160,420);
glVertex2f(360+160,590);

    glEnd();
    glBegin(GL_POLYGON);
glColor3f(1,1,0.99);
   for (int i=0; i <= 360; i++)
   {
      float degInRad = i*(3.14/180);
      glVertex2f(cos(degInRad)*150+ (720/2),sin(degInRad)*150+(720/2)+(720/4)-25);
   }
   glEnd();

    glLineWidth(10);

    glBegin(GL_LINE_LOOP);
    glColor3f(1,0.51,0.99);
   for (int i=0; i <= 360; i++)
   { glColor3f(0,0,0);
      float degInRad = i*(3.14/180);
      glVertex2f(cos(degInRad)*148+ (720/2),sin(degInRad)*148+(720/2)+(720/4)-25);
   }
   glEnd();



   glBegin(GL_LINES);
    glVertex2i(720/2,(720/2)+(720/4)-25);
    glVertex2i((720*3)/4.6,(720/2)+(720/4)-25);

   glEnd();




   glBegin(GL_LINE_LOOP);
       glVertex2i(720/2,(720/2)+(720/4)-25);
    glVertex2i((720*3)/4.6,(720/1.58));

   glEnd();


   glBegin(GL_LINE_LOOP);
    glColor3f(1,1,0.99);
   for (int i=0; i <= 360; i++)
   { glColor3f(0,0,0);
      float degInRad = i*(3.14/180);
      glVertex2f(cos(degInRad)*128+ (720/2),sin(degInRad)*128+(720/2)+(720/4)-25);
   }
   glEnd();


   glBegin(GL_LINES);
      glVertex2f(150+ (720/2),(720/2)+(720/4)-25);

   for (int i=0; i <= 360; i++)
   {
      float degInRad = i*(3.14/180);
      glVertex2f(cos(degInRad)*130+ (720/2),sin(degInRad)*130+(720/2)+(720/4)-25);
   }
    glEnd();




    glutSwapBuffers();
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

*/






//__________________________________________________FILE 2______________________________________________________________________






#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;


int init()
{
    glClearColor(0.4,0.7,0.9,1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,720,0,720);
    glMatrixMode(GL_MODELVIEW);
return 0;
}

float ir=0;
float p=67,s=-1,check=1;
void abhimanyu()
{
glClear(GL_COLOR_BUFFER_BIT);




glLoadIdentity();
glColor3f(0.3,0.2,0.1);
glBegin(GL_POLYGON);
glVertex2f(300-30,460);
glVertex2f(300-30,76);
glVertex2f(340,26);
glVertex2f(380+30,76);
glVertex2f(380+30,460);

glEnd();



glLoadIdentity();
glColor3f(0.3,0.3,0.3);
glBegin(GL_POLYGON);
glVertex2f(300-20,460);
glVertex2f(300-20,76);
glVertex2f(340,42);
glVertex2f(380+20,76);
glVertex2f(380+20,460);

glEnd();

if(p>120)
check=-1;
else
    if(p<50)
    check=1;


    if(check==1)
    p=p+0.06;
    else
        p=p-0.06;

glLoadIdentity();
glColor3f(0,0,0);
glLineWidth(3);
glBegin(GL_LINE_LOOP);
glVertex2f(340,490);
glVertex2f(400*cos((p*s)*3.14/180)+340,400*sin((p*s)*3.14/180)+490);
glEnd();

glLoadIdentity();
glBegin(GL_POLYGON);
glColor3f(0,0.1,0.1);
for(int i=0;i<=360;i++)
{
glVertex2f(20*cos((i)*3.14/180)+400*cos((p*s)*3.14/180)+340,20*sin((i)*3.14/180)+400*sin((p*s)*3.14/180)+490);
}
glEnd();












glLoadIdentity();
glBegin(GL_POLYGON);
glColor3f(0.5,0.2,0.1);
for(int i=0;i<=360;i++)
{
glVertex2f(120*cos(i*3.14/180)+340,120*sin(i*3.14/180)+490);
}
glEnd();

glLoadIdentity();
glBegin(GL_LINE_LOOP);
glColor3f(0,0,0);
for(int i=0;i<=360;i++)
{
glVertex2f(121*cos(i*3.14/180)+340,121*sin(i*3.14/180)+490);
}
glEnd();


glColor3f(0.9,0.9,0.9);

glBegin(GL_POLYGON);
for(int i=0;i<=360;i++)
{
glVertex2f(110*cos(i*3.14/180)+340,110*sin(i*3.14/180)+490);
}
glEnd();










glLoadIdentity();
glColor3f(0,0,0);
glBegin(GL_LINES);
for(int i=0;i<=360;i=i+6)
{

glVertex2f(110*cos(i*3.14/180)+340,110*sin(i*3.14/180)+490);
if(i%30==0)
{glLineWidth(3);
    glVertex2f(90*cos(i*3.14/180)+340,90*sin(i*3.14/180)+490);}
else
glVertex2f(100*cos(i*3.14/180)+340,100*sin(i*3.14/180)+490);

}
glEnd();

glLoadIdentity();
glColor3f(0,0,0);
glLineWidth(2);
glBegin(GL_LINE_LOOP);
for(int i=0;i<=360;i=i+1)
{glVertex2f(100*cos(i*3.14/180)+340,100*sin(i*3.14/180)+490);}
glEnd();


glLoadIdentity();
glColor3f(0,0,0);
glLineWidth(3);
glBegin(GL_LINES);
glVertex2f(340,490);
glVertex2f(95*cos(-ir*3.14/180)+340,95*sin(-ir*3.14/180)+490);
glEnd();

glLoadIdentity();
glColor3f(0,0,0);
glLineWidth(5);
glBegin(GL_LINES);
glVertex2f(340,490);
glVertex2f(45*cos(-(ir/60)*3.14/180)+340,45*sin(-(ir/60)*3.14/180)+490);
glEnd();

glLoadIdentity();
glColor3f(0,0,0);
glLineWidth(2);
glBegin(GL_LINES);
glVertex2f(340,490);
glVertex2f(103*cos(-(ir*60)*3.14/180)+340,103*sin(-(ir*60)*3.14/180)+490);
glEnd();





ir=ir+0.0006;
if(ir==360)
    ir=0;
glutSwapBuffers();
glutPostRedisplay();
}

int main(int b,char **c)
{
    glutInit(&b,c);
    glutInitWindowSize(720,720);
    glutInitWindowPosition(140,1);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutCreateWindow("ABHIMANYU");

        init();
        glutDisplayFunc(abhimanyu);
    glutMainLoop();
return 0;
}









