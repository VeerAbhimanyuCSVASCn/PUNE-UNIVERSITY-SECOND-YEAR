#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

void doub(double &c,double &d)
{
    cin>>c>>d;
}

double fun(double b)
{
    if(b==0)
        throw b;
    else
        return b;
}


int main()
{
double a,b;
system("color f0");
cout<<"\n\n\nENTER TWO NUMBERS TO FIND DIVISION ";
doub(a,b);
a=a/b;

cout<<a;
try
{
    if(b==0)
        fun(b);
}

catch(double a)
{
    cout<<"\n\n\n\t\t\tSECOND VALUE IS "<<a;
    cout<<"\n\nEXECUTION NOT COMPLETED \n\nPRESS ANY KEY TO EXIT";
    getch();
   // return 0;

}

catch(...)
{
    cout<<"executed";
}


return 0;
}
