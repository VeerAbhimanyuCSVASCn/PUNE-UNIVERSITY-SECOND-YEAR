#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
/*PRIORITY*/


int initial[10];
int data[10];
int next[10];


int insert(int a)
{
    int key  = a%10;

    if(data[key]==-1)
    {initial[key]=key;
     data[key]=a;
     next[key]=-1;
     return 0;
    }

int t;
    if(initial[key]!=-1)
        t=initial[key];

   else
   {int m=key;
       while(1)
       {
           if(data[m]==-1)
            break;
           m=(m+1)%10;
       }
    data[m]=a;
    initial[key]=m;
    next[key]=-1;
return 0;
   }

    while(next[t]!=-1)
    {
        t=next[t];

    }


    int r=t;
    int s=0;

    while(s<10)
    {
        ++s;
        if(s==9)
            return 0;


        if(data[r]!=-1)
        {
            r=(r+1)%10;
            continue;
        }
      break;
    }
    data[r] = a;
    next[t]=r;
    return 0;
}

void display()
{
    for(int i=0;i<10;i++)
        if(data[i]!=-1)
        cout<<initial[i]<<"  "<<data[i]<<"  "<<next[i]<<endl<<endl<<endl;
}

int main()
{
    system("color f0");
    for(int i=0;i<10;i++)
        initial[i]=data[i]=next[i]=-1;

    ab:
    int a;
    cin>>a;
    insert(a);
    display();
    goto ab;
    return 0;
}
