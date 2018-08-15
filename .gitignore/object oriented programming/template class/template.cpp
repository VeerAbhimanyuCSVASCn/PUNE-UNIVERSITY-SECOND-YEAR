#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;


template <class A>
class matrix
{
A **b;
A **a;
int c,d,e,f;

public:


    void create()
    {
        cout<<"\n\nENTER THE SIZE OF MATRIX 1 - ";
        cin>>c>>d;
        b=new A* [c];
        for(int i=0;i<c;i++)
            b[i]=new A [d];


        cout<<"\n\nENTER THE SIZE OF MATRIX 2 - ";
        cin>>e>>f;
        a=new A* [e];
        for(int i=0;i<e;i++)
            a[i]=new A [f];

    }


    void dataentry()
    {   cout<<"\n\n\nENTER THE MATRIX 1:- ";
        for(int i=0;i<c;i++)
        {
            for(int j=0;j<d;j++)
            {
                cin>>b[i][j];
            }
        }
        cout<<"\n\n\nENTER THE MATRIX 2:- ";
        for(int i=0;i<e;i++)
        {
            for(int j=0;j<f;j++)
            {
                cin>>a[i][j];
            }
        }
    }




    void display(int q)
    {
        if(q==1)
        {
             for(int i=0;i<e;i++)
            {
                for(int j=0;j<f;j++)
                    {
                        cout<<b[i][j];
                    }
            }
        }

        else
        {
             for(int i=0;i<e;i++)
                {
                for(int j=0;j<f;j++)
                    {
                        cout<<a[i][j];
                    }
                }
        }
    }





void addition()
{
    int i,j;
        if(c==e&&d==f)
        {
            for( i=0;i<c;i++)
                {  printf("\n");
                    for( j=0;j<d;j++)
                    {cout<<a[i][j]+b[i][j];}
                }
        }

else
printf("..::SORRY! NO ADDITION POSSIBLE ::..");


}


void subtraction()
{
    int i,j;
        if(c==e&&d==f)
        {
            for( i=0;i<c;i++)
                {  printf("\n");
                    for( j=0;j<d;j++)
                    {cout<<a[i][j]-b[i][j];}
                }
        }

else
printf("..::SORRY! NO SUBTRACTION POSSIBLE ::..");


}



int multi()
{

   int i,j,k;
   float temp,abg=0;


   if(e!=d)
   {
   printf("SORRY! no multiplication possible : ");
   }


   for(i=0;i<c;i++)
   {
   printf("\n");
   for(j=0;j<d;j++)
   {  abg=0;

   for(k=0;k<f;k++)

   {    abg=abg+ (a[i][k] * b[k][j]);

   }

   cout<<abg;
   }

   }
 return 0;
}
};







template <class QWER>
void INTEGER( QWER cd)
{

matrix <QWER > aa;

aa.create();
aa.dataentry();

char a;
ab:
    do
{cout<<"\n\n\n\t\t\tMENU\n\n\n1.ADDITION\n2.MULTIPLICATION\n3.SUBTRACTION\n\n";
printf("\n\n\n\t\tNOW ENTER YOUR CHOICE : ");
a=getch();
switch(a)
{
   case '1':
   aa.addition();
   break;
   case '2':
   aa.multi();
   break;
   case'3':
   aa.subtraction();
   break;

}}while(a<'4');
getch();
}








int main()
{   ab:
    cout<<"\n\n\n\t\t\t..:: MENU ::..\n\n1. INTERGER MATRIX MANIPULATION\n2. FLOAT MATRIX MANIPULATION\n\n\t\t";
    char c;
    c=getch();
system("color f0");
        switch(c)
        {
        case '1':
           INTEGER(1);
            goto ab;
        case '2':
            INTEGER(1.1f);
            goto ab;
        }

return 0;
}


