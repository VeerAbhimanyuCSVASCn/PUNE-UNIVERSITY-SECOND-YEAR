#include<iostream>
#include<string>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

    class complexes
    {

        int real,comp;

        public:

        friend istream &operator >>(istream &a, complexes &b);
        friend ostream &operator <<(ostream &a, complexes &b);
        friend void operator +(complexes a,complexes b);
        friend void operator -(complexes a,complexes b);



void operator <(complexes a)
{
 if(a.real<a.comp)
    cout<<"its true REAL IS LESS THAN IMAGINARY ";
 else
    cout<<" FALSE ";
}

void operator >(complexes a)
{
 if(a.real>a.comp)
    cout<<"its true REAL IS GREATER THAN IMAGINARY ";
 else
    cout<<" FALSE ";
}

void operator ==(complexes a)
{
 if(a.real==a.comp)
    cout<<"its true REAL IS EQUAL TO IMAGINARY ";
 else
    cout<<" FALSE ";
}

void operator !=(complexes a)
{
 if(a.real!=a.comp)
    cout<<"its true REAL IS NOT EQUAL IMAGINARY ";
 else
    cout<<" FALSE ";
}



        void operator -()
        {
            cout<<-real;
            if(-comp>0)
                cout<<"+"<<-comp;
            else
                cout<<-comp;

                cout<<" i \n\n\n\n";
        }



        void operator  * (complexes a)
        {
            cout<<(real*a.real-comp*a.comp)<<"  +  "<<real*a.comp+comp*a.real<<" i ";
        }


        void operator  / (complexes a)
        {
            a.comp=-a.comp;
            cout<<(real*a.real-comp*a.comp)<<"  +  "<<real*a.comp+comp*a.real<<" i ";
        }

};



istream &operator >>(istream &a, complexes &b)
{
    a>>b.real;
    a>>b.comp;
}



ostream &operator <<(ostream &a, complexes &b)
{   cout<<"\n\n";
    a<<b.real;
    cout<<"  +  ";
    a<<b.comp;
    cout<<" i ";
}


void operator -(complexes a,complexes b)
{
    cout<<" YOUR ANSWER IS ";
    cout<<a.real-b.real<<"  +  "<<a.comp-b.comp;

}



void operator +(complexes a,complexes b)
{
    cout<<" YOUR ANSWER IS ";
    cout<<a.real+b.real<<"  +  "<<a.comp+b.comp;

}



void unary()
{
    complexes a;
    cout<<"\n\n\n ENTER THE DATA REAL AND THE IMAGINARY PART RESPECTIVELY : "   ;

    cin>>a;
    cout<<"\n\n\nYOUR DATA IS ";
    cout<<a;
    cout<<" \n\nNEW DATA IS ";
    -a;
}


void binary()
{
    complexes a,b;
    cout<<"\n\n\n ENTER THE DATA REAL AND THE IMAGINARY PART RESPECTIVELY : ";
    cin>>a;
    cout<<"\n\n\nYOUR DATA 1 IS ";
    cout<<a;
    cout<<"\n\n\n ENTER THE DATA REAL AND THE IMAGINARY PART RESPECTIVELY : ";
    cin>>b;
    cout<<"\n\n\nYOUR DATA 2 IS ";
    cout<<b;


    cout<<"\n\n\n 1. TO ADD \n2. TO SUBTRACT \n3. TO MULTIPLY \n4. TO DIVIDE\n\n\n";
    char s;
    s=getch();

    switch(s)
    {
        case '1':
            a+b;
            break;
        case '2':
            operator - (a,b);
            break;
        case '3':
            a*b;
            break;
        case '4':
            a/b;
            break;
    }
}





void relational()
{
complexes a,b;
cout<<"\n\n\n ENTER THE DATA REAL AND THE IMAGINARY PART RESPECTIVELY : ";
cin>>a;
cout<<"\n\n\nYOUR DATA  IS ";
cout<<a;


cout<<"\n\n\n 1. GREATER THAN \n2. LESS THAN \n3. EQUAL \n4. NOT EQUAL\n\n\n";
char s;
s=getch();

switch(s)
{
case '1':
    a<a;
    break;
case '2':
    a>a;
    break;
case '3':
    a==a;
    break;
case '4':
    a!=a;
    break;
}
}





int main()
{
    char c;
    do
   {

    system("color f0");
    cout<<"\n\n\n\t\t\t\t\t..:: MENU ::..\n\n";
    cout<<"1.UNARY\n2.BINARY \n3. RElaTIONAL\n\n\n\t\t\t";


    c=getch();

    switch(c)
    {
case'1':

    unary(); break;

case '2':
     binary(); break;

case '3':

    relational();
  break;
    }}while(c<'4');

return 0;
}
