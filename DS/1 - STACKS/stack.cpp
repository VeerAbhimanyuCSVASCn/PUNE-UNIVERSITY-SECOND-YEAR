#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;

    template <class t>
    class stacks
    {
        public:
            t data;
            stacks *next;

            stacks()
            {
                next=NULL;

            }
    };


    template <class y>
    class stackcode
    {
        stacks <y> *top;

            public:
                stackcode()
                {
                    top=NULL;
                }

                ~stackcode()
                {
                    while(top!=NULL)
                    {
                        stacks <y>*r=NULL;
                        r=top;
                        top=top->next;
                        delete r;
                    }
                    cout<<"\n\n";
                    exit(0);
                }

                void push(y data)
                {
                    stacks <y> *p=new stacks<y>;
                    p->data=data;
                    p->next=top;
                    top=p;
                }

                y toper()
                {
                    return top->data;
                }

                y pop()
                {
                    if(top==NULL)
                    {
                        stackcode();
                    }

                    stacks<y> *temp=NULL;
                    temp=top;
                    top=top->next;
                    y r=temp->data;
                    delete temp;
                    return r;
                }

                int isnull()
                {
                    if(top==NULL)
                        return 0;
                    else
                        return 1;
                }



    };


    int precidence(char t)
    {
        switch(t)
        {
        case'+':return 1;
        case'-':return 1;
        case '/':return 2;
        case'*':return 2;
        case'%':return 2;
        case'^':return 3;
    }
        return 0;
    }


/*
int main()
{
    system("color f0");
    string d;
    stackcode<string> a;
    char t;
    ab:
    system("color f0");
    cout<<"1.push \n\n2.pop\n\n\t\t";
    cin>>t;
        switch(t)
        {
            case'1':
            fflush(stdin);
            cout<<"\n\nenter data to be pushed \n\n";
            cin>>d;
            a.push(d);
            goto ab;

            case'2':
                fflush(stdin);
                cout<<"\n\n"<<a.pop()<<" \n\n\n";
                goto ab;
        }
    return 0;
}



*/
