#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string>
#include<string.h>
#include<stdlib.h>

using namespace std;

class data
{ protected:
    string name;
    string dob;
    char bgroup;

  public:

      data()
      {
          name="XXXXX";
          dob="00-00-0000";
          bgroup='x';
      }

      data(string a,string b,char c)
      {
          name=a;
          dob=b;
          bgroup=c;
      }
};


class data2
{  protected:
    int weight;
    int height;
public:

    data2()
    {
        weight=0;
        height=0;
    }
    data2(int a,int b)
    {
        weight=a;
        height=b;
    }
};


class data3
{   protected:

    int policy;
    char address[100];
  public:

      data3()
      {
          policy=0;
          strcpy(address,"       ");
      }

      data3(int a,char b[])
      {
          policy=a;
          strcpy(address,b);
      }


};




    class data4:protected data,protected data2,protected data3
    {
    string telephone;
    int licence;

public:

    void displayed()
    {
        cout<<endl<<"\t\t"<<name<<"\t"<<dob<<"\t"<<bgroup<<"\t"<<weight<<"\t"<< height<<"\t"<<policy<<"\t"<<address<<"\t"<<telephone<<"\t"<<licence;
    }



    string searches()
    {
        return name;
    }


    string searchess()
    {
        return telephone;
    }


    data4(string a,string b,char c,int d,int e,int f,char g[],string h,int i):
        data(a,b,c),data2(d,e),data3(f,g)
        {
            telephone=h;
            licence=i;
        }

    void entry()
    {
        cout<<"\n\n\nENTER THE NAME OF CANDIDATE - ";
    cin>>name;
    cout<<"\nENTER THE DATE OF BIRTH ";
    cin>>dob;
    cout<<"\nENTER THE BLOOD GROUP ";
    cin>>bgroup;
    cout<<"\nENTER THE WEIGHT OF CANDIDATE ";
    cin>>weight;
    cout<<"\nENTER THE HEIGHT OF CANDIDATE ";
    cin>>height;
    cout<<"\nENTER THE POLICY NUMBER ";
    cin>>policy;
    cout<<"\nENTER TE ADDRESS ";
    scanf("%s",address);
    cout<<"\nENTER THE TELEPHONE NUMBER ";
    cin>>telephone;
    cout<<"\nENTER THE DRIVING LICENCE NUMBER ";
    cin>>licence;
    }

         data4 *node;

 ~data4()
 {
     cout<<"daat deleted";
 }
    };




data4 * create()
{

    string a;string b;char c;int d;int e;int f;
    char g[100];
    string h;
    int i;

    cout<<"\n\n\nENTER THE NAME OF CANDIDATE - ";
    cin>>a;
    cout<<"\nENTER THE DATE OF BIRTH ";
    cin>>b;
    cout<<"\nENTER THE BLOOD GROUP ";
    cin>>c;
    cout<<"\nENTER THE WEIGHT OF CANDIDATE ";
    cin>>d;
    cout<<"\nENTER THE HEIGHT OF CANDIDATE ";
    cin>>e;
    cout<<"\nENTER THE POLICY NUMBER ";
    cin>>f;
    cout<<"\nENTER TE ADDRESS ";
    scanf("%s",g);
    cout<<"\nENTER THE TELEPHONE NUMBER ";
    cin>>h;
    cout<<"\nENTER THE DRIVING LICENCE NUMBER ";
    cin>>i;

     data4 * abc;
    abc=new data4(a,b,c,d,e,f,g,h,i);
    return abc;

}



void display(data4 * p,int i)
{
    printf("\n\n\n\nNAME\tDOB\tBGROUP\tWEIGHT\tHEIGHT\tPOLICY\tADDRESS\tTELEPHONE\tDRIVE");
   if(i==0)
   {
    while(p!=NULL)
    {
        p->displayed();
        p=p->node;
    }
   }
   string ser;
   if(i==1)
   {
       cout<<"\n\nENRER THE NAME OF CANDIDATE TO BE SEARCHED ";
       cin>>ser;
       cout<<endl<<endl;
       while(p!=NULL)

    {  if(p->searches()==ser)
       {
        p->displayed();}
        p=p->node;
    }

   }
}


data4 * deletes(data4 * f)
{   int i,j;
    struct data4 *q=f,*r=f,*p=NULL;

    if(f==NULL)
       {
        printf(" \n\n\tNO DATA FURTHER DELETION NOT POSSIBLE ");
        return 0;
       }

    printf("\n\nENTER THE RECORD NUMBER TO BE DELETED start from 1");
    scanf("%d",&i);

    i=i-1;

    if(i==0)
    {
        r=r->node;
        free(f);
        f=r;
        return f;
    }
    for(j=1;j<i;j++)
    {
    q=q->node;
    r=r->node;
    }
    r=r->node;
    r=r->node;
    p=q->node;
    q->node=r;
    free(p);

return f;
}


int edit(data4 * q)
{   string qq,rr;
    cout<<"\n\n\n ENTER THE NAME OF DATA TO BE EDITED ";
    cin>>qq;
    cout<<"\n\nENTER THE TELEPHONE NUMBER TO BE EDITED ";
    cin>>rr;

    data4 *a=q;
    int o=0;
    while(a!=NULL)
    {   if(qq==a->searches()&&rr==a->searchess())
        {
            a->entry();

            return 0;
        }

        a=a->node;
    }

    if(o==0)
        printf("\n\n\n\t\t\t.. SORRY NO DATA FOUND ");
return 0;
}

int main()
{   data4 *p=NULL , *starts=NULL;
    char a;
    ab:
    system("color f0");
    do
    {printf(" \n\n\n\t\t\t<<  MENU  >>\n\n1.CREATE AND INSERT\n2.DELETE \n3.EDIT\n4.DISPLAY\n5.DISPLAY ALL\n\t\t");
    a=getch();

    switch(a)
    {

    case '1':
        p=create();
        if(starts==NULL)
        {starts=p;}
        else
        {
            p->node=starts;
            starts=p;
        }

        break;



    case '2':
        display(starts,0);
       starts= deletes(starts);
        break;


    case '3':
         edit(starts);
        break;


    case '4':
         display(starts,1);
         break;
    case '5':
         display(starts,0);
        break;


    }}while(a<'6');

    return 0;
}
