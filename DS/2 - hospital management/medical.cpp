#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


using namespace std;

class patient
{
    char name[100];
    int age;
    char problem[300];

public:
        void inputdetails()
            {
                cout<<"\n\t\tENTER THE NAME OF THE PATIENT - ";
                cin.getline(name,100);
                cout<<"\n\t\tENTER THE AGE OF PATIENT - ";
                fflush(stdin);
                cin>>age;
                fflush(stdin);
                cout<<"\n\t\tENTER THE PROBLEM - ";
                cin.getline(problem,300);
            }

            void outputdetails()
            {
                cout<<"\n\n\t\t NAME OF THE PATIENT - ";
                cout<<name;
                cout<<"\n\t\tENTER THE AGE OF PATIENT - ";
                fflush(stdin);
                cout<<age;
                fflush(stdin);
                cout<<"\n\t\tENTER THE PROBLEM - ";
                cout<<problem;
                fflush(stdin);
            }
};















struct DLLdata
{
    patient *data;
    int priority;
    DLLdata *next;
    DLLdata *previous;

    DLLdata()
    {
        priority = 0;
        next = 0;
        previous = 0;
    }


    int prioritize()
    {
        cout<<"\n\t\tENETER THE PRIORITY OF THE PATIENT - ";
        cin>>priority;
        fflush(stdin);
        return priority;
    }

    int seriouness()
    {
        return priority;
    }

};












class hospitalmanagement
{
    DLLdata * datalist ;
    DLLdata *front;
    DLLdata * rear;

public:
    hospitalmanagement()
    {
        datalist = NULL ;
        front = NULL;
        rear = NULL;
    }


public:
    void attendent_interface()
    {
                char r;

        ab:

        cout<<"\n\n\t\t\t..:: MENU ::.. \n\n1. NEW DATA TO BE ENTERED \n 2. NEXT PATIENT TO BE CHECKED \n";

        fflush(stdin);
        r=getch();
        fflush(stdin);
            switch(r)
            {
                case'1':
                    newdata();
                    goto ab;
                case '2':
                    nextpatient();
                    goto ab;
            }


    }


    int newdata()
    {
        DLLdata * bh = new DLLdata();
        bh->data  = new patient();
        bh->data->inputdetails();
        bh->prioritize();



        if(front == NULL)
        {

            front = rear = bh;
            return 0;
        }


        if(bh->seriouness()>=front->seriouness())
        {
            bh->next=front;
            front->previous=bh;
            front=bh;
            return 0;
        }

        else
        {
            datalist = front;
            while(bh->seriouness() <= datalist->seriouness() && datalist->next!=rear )
            {
                datalist = datalist->next;
            }

            if(datalist==rear)
            {

                rear->next=bh;
                bh->previous=rear;
                rear=bh;
                return 0;
            }
            else
            {
                bh->next=datalist;
                bh->previous=datalist->previous;
                datalist->previous->next=bh;
                datalist->previous=bh;
                return 0;

            }
        }
  }



    int nextpatient()
    {
        if(front==NULL)
        {
            cout<<"\t\t\t..:: NO ANY PATIENT LEFT ::.. \n\n\n";
            return 0;
        }
            datalist = front;
            datalist->data->outputdetails();
            cout<<endl<<endl<<endl;

            if(front->next!=0)
            {front = front->next;
            front->previous=0;}
            else
                {front=0;
                rear=0;}
            delete datalist;
            return 0;
    }
};


int main()
{


    patient t;
    system("color f0");
    hospitalmanagement y;
    y.attendent_interface();
    getch();
    return 0;
}
