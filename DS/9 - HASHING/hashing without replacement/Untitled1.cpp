#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

class hashing
{
    long telephone;
    string name;

public:
      int next_index;

    long tele()
    {
        return telephone;
    }


    string nam()
    {
        return name;
    }

    void display()
    {
        cout<<tele()<<"  "<<nam()<<endl;
    }

   hashing(string naam, long tell)
   {

        telephone = tell;
        name = naam;
        next_index=-1;
   }

    void getdata(string naam, long tell)
    {
        telephone = tell;
        name = naam;
        next_index=-1;
    }

} *phonebook[50];

int hashed(string name , long telephone)
{
    int key = telephone%50;

    if(phonebook[key]==NULL)
    {
        phonebook[key] = new hashing(name,telephone);
        cout<<key;
        return key;
    }



    else
    {
        int t = key;

        while(phonebook[t]->next_index!=-1)
        {

            t=phonebook[t]->next_index;

        }
        int r =t,s=0;
        while(phonebook[r]!=NULL)
        {
            if(s==49)
                return -1;

            r=((r+1)%50);
            s++;

        }
        phonebook[t]->next_index=r;
        phonebook[r] = new hashing(name,telephone);
        return r;

    }


return key;
}

void newdata()
{
    string name;
    long telephone;

    cout<<"ENTER THE NAME OF PERSON - ";
    cin>>name;
    cout<<"ENTER THE TELEPHONE NUMBER OF PERSON - ";
    cin>>telephone;
    int i=hashed(name,telephone);
    if(i==-1)
        cout<<"SORRY..!!! DATA MEMORY IS FULL. \n";
    else
        cout<<" ...DATA ENTERED SUCCESSFULLY...at "<<i<<" \n";

}


void displayall()
{
    cout<<"\n\n\n\t\t\tTELEPHONE BOOK RECORD\n\n";
    for(int i=0;i<50;i++)
    {
        if(phonebook[i]!=NULL)
        {
            phonebook[i]->display();
            cout<<"\n\n\n";
        }
    }

}

int main()
{
    ab:
    system("color f0");
    cout<<"\n\n\t\t\t..::MeNu::..\n\n\n1.EnTeR a NeW DaTa\n2.DiSpLaY AlL\n";
    switch(getch())
    {
    case'1':

           newdata();
        goto ab;
    case'2':
        displayall();
        goto ab;

    }
    return 0;
}
