#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>

using namespace std;
class bookshop;
void accounts(bookshop **a,int i);

class bookshop
{
    string title;
    string author;
    string publisher;
    double price;
    int available;

public:
     static int transaction;
     static int untransaction;


   bookshop ()
   {
   }

    bookshop(int iop)
    {

    bookshop p;
    int i=-1;
    char a;
    int aw;
        cout<<" ENTER THE NUMBER OF DATA YOU WANT TO ENTER - ";
        cin>>aw;
        bookshop **qw=new bookshop*[aw];
    ab:
do
   {
     printf(" \n\n\n\t\t\t<<  MENU  >>\n\n1.CREATE AND INSERT\n2.DISPALY ALL \n3.DISPLAY PARTICULAR\n4.MODIFY\n5.DELETE\n6.ACCOUNT SECTION\t\t");
    a=getch();
    string h;
    int r;
    switch(a)
    {

    case '1':

       /* if(i==aw-1)
           {
            cout<<"NO MORE DATA CAN BE CREATED ";
            goto ab;
           }
        */
        ++i;
        qw[i]=p.create();

        for(int o=0;o<i;o++)
        {
            if(qw[o]->title==qw[i]->title && qw[o]->author==qw[i]->author && qw[o]->publisher==qw[i]->publisher)
            {
                cout<<"\n\n\n\t\t\t DATA ALREADY EXIST NOT CREATED NEW DATA available stock updated ";
                qw[o]->available+=qw[i]->available;
                qw[o]->price=qw[i]->price;
                delete qw[i];
                --i;
            }
        }
       break;

    case '2':
    {
        for(int j=0;j<=i;j++)
        {
            qw[j]->display();
        }
    }

        goto ab;



    case '3':
        cout<<"ENTER DISPLAY BY TITLE  - ";
        cin>>h;

        for(int iq=0;iq<=i;iq++)
        {
            if(qw[iq]->searches(h))
            {
                qw[iq]->display();
               break;
            }
        }
        cout<<"\n\n\n\t\t\t DATA NOT FOUND ...!!! ";
      break;



    case '4':
        cout<<"ENTER DATA TO BE MODIFIED BY TITLE  - ";
         cin>>h;

        for(int iq=0;iq<=i;iq++)
        {
            if(qw[iq]->searches(h))
            {
                delete qw[iq];
                qw[iq]=qw[iq]->create();
                qw[iq]->display();
                goto ab;
            }
        }
        cout<<"\n\n\n\t\t\t DATA NOT FOUND ...!!! ";
        break;



    case '5':
        cout<<"ENTER DATA TO BE DELETED BY TITLE  - ";
        cin>>h;
        int r;


          for( int iq=0;iq<=i;iq++)
        {
            if(qw[iq]->searches(h))
            {
                for(r=iq;r<=i;r++)
                    {
                        qw[r]=qw[r+1];
                    }

                delete qw[i];
                --i;
                 break;

            }
        }


        cout<<"\n\n\n\t\t\t DATA NOT FOUND ...!!! ";

        break;



    case '6':
        accounts(qw,i);
        break;
    }}while(a<'7');
    }



    bookshop * create()
    {
        bookshop * abc;
        abc=new bookshop;
        cout<<"\n\n\nENTER THE TITLE - ";
        cin>>abc->title;
        cout<<"\nENTER THE AUTHOR ";
        cin>>abc->author;
        cout<<"\nENTER THE PUBLISHER ";
        cin>>abc->publisher;
        cout<<"\nENTER THE PRICE ";
        cin>>abc->price;
        cout<<"\nENTER THE AVAILABLE STOCK ";
        cin>>abc->available;
        return abc;

    }


  int searches(string a)
  {
      if(a==title)
        {return 1;}

        return 0;
  }


    void display()
    {
        cout<<"\n\n\nTITLE - ";
        cout<<title;
        cout<<"\nAUTHOR ";
        cout<<author;
        cout<<"\nPUBLISHER ";
        cout<<publisher;
        cout<<"\nPRICE ";
        cout<<price;
        cout<<"\nAVAILABLE STOCK ";
        cout<<available;

    }


    double cost(int n)
    {
        if(available<n)
            return 0;

        if(available>=n)
        {available-=n;}
        return price*n;
    }
};

 int  bookshop::transaction=0;
 int  bookshop::untransaction=0;


void accounts(bookshop **a,int i)
{
    cout<<"\n\n\nENTER THE BOOK TITLE TO TO BE PURCHASED ";
    string fg;
    cin>>fg;
    int q=0;
    for(q=0;q<=i;q++)
    {
        if(a[q]->searches(fg))
        {
            a[q]->display();
            goto ab;
        }
    }
    ab:
        cout<<"\n\n\nENTER THE NUMBER OF COPIES YOU WANT TO PURCHASE  - ";
        int n;
        cin>>n;
        double r=a[q]->cost(n);
            if(r==0)
                {cout<<  ++bookshop::untransaction<<" TRANSACTION FAILED NOT SUFFICIENT STOCK ";


                }
            else
            {    bookshop ::transaction++;
                cout<<" TRANSACTION SUCCESSFULL \nTRANSACTION NUMBER  : "<<bookshop::transaction<<endl;
                cout<<" YOU HAVE TO PAY "<<r<<" RUPEES ";

            }
}



int main()
{
system("color f0");
bookshop programme_starter_obcect(1);

    return 0;
}

