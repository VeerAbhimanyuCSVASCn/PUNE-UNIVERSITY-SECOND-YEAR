#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

//int a,b;
class shape
{

protected:
double a;
double b;


public:


shape()
{a=0;b=0;}


virtual void area()=0;
virtual void getdata()
{

}


};




class triangle:public shape
{

public:

    void getdata()
    {
        cout<<"ENTER THE HEIGHT - ";
        cin>>a;
        cout<<"\n\nENTER THE BASE _ ";
        cin>>b;
    }

    void area()
    {
        cout<<"AREA OF THE TRIANGLE _ ";
        cout<<0.5*a*b;
    }
};




class rectangle:public shape
{
public:
    void getdata()
    {
        cout<<"ENTER THE HEIGHT - ";
        cin>>a;
        cout<<"\n\nENTER THE width - ";
        cin>>b;
    }

    void area()
    {
        cout<<"AREA OF THE RECTANGLE - ";
        cout<<a*b;
    }
};


class circle:public shape
{
public:
    void getdata()
    {
        cout<<"ENTER THE RADIUS - ";
        cin>>a;
    }

    void area()
    {
        cout<<"AREA OF THE CIRCLE - ";
        cout<<3.14*a*a;
    }
};



class square:public shape
{
public:
    void getdata()
    {
        cout<<"ENTER THE side - ";
        cin>>a;
    }

    void area()
    {
        cout<<"AREA OF THE CIRCLE - ";
        cout<<a*a;
    }
};


int main()
{   char a='1';
system("color f0");
   shape *r;

   circle s;
   triangle t;
   rectangle u;
   square v;

while(a<='4')
{
    cout<<"\n\n\n\t\t\t..::MENU::..\n1.RECTANGLE\n2.TRIANGLE\n3.CIRCLE\n4.SQUARE\n\n\n\n\t\t\t";
    a=getch();


    switch(a)
    {

    case '1':

         r=&u;
         r->getdata();
         r->area();
        break;

        case '2':

         r=&t;
        r->getdata();
         r->area();
        break;

        case '3':

         r=&s;
         r->getdata();
         r->area();
        break;

        case'4':

         r=&v;
         r->getdata();
         r->area();
        break;
    }
}
    return 0;
}
