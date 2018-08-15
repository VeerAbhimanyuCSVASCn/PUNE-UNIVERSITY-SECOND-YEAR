#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;
static int p=0;

class friends
{
    int id;

public:
    int data;
    friends *next;

    int ids()
    {return id;}
    friends* nexter()
    {return next;}

    friends(int ide)
    {
        data =p;
        id = ide;
        next = NULL;

    }

};


class account
{

    int id_no;
    string name;
    string dob;

public:
    int fri;

    int post;
    int comment;

       friends *next;

    account(string nam,string Dob)
    {
        id_no = p;
        name=nam;
        dob = Dob;
        fri=0;
        next = 0;
        post=0;
        comment=0;
    }

    string names()
    {
        return name;
    }
    int id()
    {
        return id_no;
    }

    int details()
    {
    cout<<"\n\n\nNAME : "<<name<<"\nID : "<<id_no<<"\nDOB : "<<dob;
    return 0;
    }

    friends* nexter()
    {
        return next;
    }

} * new_account[50];



int login(string nam,int id)
    {
        for(int i=0;i<p;i++)
        {
            if(nam==new_account[i]->names()&&id==new_account[i]->id())
            {

                return id;
            }
        }
        return -1;
    }




void friendsf(int i,int uy)
{
    friends *se;
    {se = new friends(uy);

                        if(new_account[i]->next == NULL)
                        {
                            new_account[i]->next = se;
                            cout<<"NEW FRIEND : - "<<new_account[i]->next->ids();
                        }

                        else
                        {
                            friends *po = new_account[i]->next;
                                while(po->next!=NULL)
                                    po=po->next;
                                    po->next=se;

                        }

                        new_account[i]->fri++;
}

}



int login_menu(int i)
{
    friends* re,*se;
    int uy;
    string h;
    ab:
         cout<<"\n__________________________________________________________________________________________________________________\n";
    cout<<"\n\n\n\t\t\tMENU\n\n1. YOURS DETAILS\n\n2.LIST of FRIEND's ACCOUNT DETAIL\n\n3.COMMENT ON FRIEND's POST\n\n4.NEW POST\n\n5.ADD FRIEND\n\n\t\t";
    switch(getch())
    {
        case'1':
                new_account[i]->details();
                goto ab;

        case'2':
                re=new_account[i]->next;
                    if(re==0)
                        {cout<<"\n\n____________NO FRIENDS TO BE SHOWN_____________\n\n";
                    goto ab;}


                    while(re!=NULL)
                    {
                    new_account[re->ids()]->details();
                    re=re->next;
                    }
                goto ab;


            case'3':
                cout<<"\n\n\n________ENTER THE NAME OF PERSON ON WHOSE TIMELINE YOU WANT TO POST A NEW POST : _________\n";
                cin>>h;
                cout<<"\nenter id :- \n\t\t";
                cin>>uy;

                if(login(h,uy)!=-1)
                {
                    ++new_account[i]->post;
                }
                    goto ab;


            case'4':

                cout<<"\n\n\nENTER THE NAME OF PERSON ON WHOSE TIMELINE YOU WANT TO COMMENT : ";
                cin>>h;
                cout<<"\nenter id :- ";
                cin>>uy;

                if(login(h,uy)!=-1)
                {
                    ++new_account[i]->comment;
                }

                    goto ab;


            case'5':


                cout<<"\n\nENTER THE NAME OF PERSON TO SEND FRIEND REQUEST : - ";
                cin>>h;
                cout<<"\nenter id :- ";
                cin>>uy;


                if(login(h,uy)!=-1)
                        {
                            friendsf(i,uy);
                            friendsf(uy,i);

                        }


        goto ab;

    }
return 0;
}







int user_login()
{
    cout<<"\n\nENTER THE NAME  TO LOGIN :- ";
    string name;
    cin>>name;
    cout<<"\n\nACCOUNT ID :-  ";
    int id;
    cin>>id;
    int i=login(name,id);
    if(i==-1)
    {
        cout<<"\n\n\t\t\t_________LOgIN FAilED__________\n";
        return i;
    }
    cout<<"\n\n___________SUCCESSFULL LOGIN___________\n\n";
    login_menu(i);
    return 0;
}




int management()
{
    fflush(stdout);
    fflush(stdin);
    cout<<"\n\nENTER A THE NAME OF NEW ID HOLDER :- ";
    string name;
    cin>>name;
    fflush(stdin);
    cout<<"\nENTER A THE DATE OF BIRTH :- ";
    string DOB;
    cin>>DOB;
    cout<<"\nTHE NEW ACCOUNT's ID WILL BE : - ";
    cout<<p;
    new_account[p] = new account(name,DOB);
    ++p;
    return 0;

}





int * q = new int(p);
friends * rem;
int minimum,maximum,poster,comm;
int * visiter = new int[p];
 int DFS(int i)
    {
        if(visiter[i]!=0)
            return 0;

        visiter[i] =1;

        {
            if(new_account[i]->fri < minimum)
                minimum = new_account[i]->fri;

            if(new_account[i]->fri > maximum)
                maximum = new_account[i]->fri;

            if(new_account[i]->post < poster)
                poster = new_account[i]->post;

            if(new_account[i]->comment > comm)
                comm = new_account[i]->comment;
        }
        friends * tu=new_account[i]->next;
        while(tu!=NULL)
            {
                            DFS(tu->data);

                    tu = tu->next;
            }
            return 0;
    }













void informations()
{
    ab:
        cout<<"\n________________________________________________________________________________________________________________\n";
    cout<<"\n\n\n\t\t\t<<    MENU    >>\n\n1.MAXIMUM/MINIMUM FRIENDS\n\n2.MAXIMUM POST\n\n3.MINIMUM COMMENT\n\n4.USER HAVING DATE OF BIRTH ON THIS MONTH\n";
    cout<<"\n\n\t\t";
                minimum = new_account[0]->fri;
            maximum = new_account[0]->fri;
            poster  = new_account[0]->post;
            comm    = new_account[0]->comment;



    DFS(0);
    switch(getch())
    {
    case '1':
        cout<<endl;
        cout<<"MINIMUM NUMBER OF FRIENDS ARE : - "<<minimum<<endl;
        cout<<"MAXIMUM NUMBER OF REIENDS ARE : - "<<maximum<<endl;
        goto ab;
    case '2':
        cout<<"MAXIMUM NUMBER OF POSTS : - "<<poster<<endl;
        goto ab;
    case '3':
        cout<<"MINUMUM NUMBER OF COMMENTS : - "<<comm<<endl;
        goto ab;
    case '4':
        cout<<"DATE OF BIRTH ON THIS MONTH : - ";
        goto ab;

    }

}




int main()
{
    system("color f0");
    ab:

    cout<<"\n\n\n\t\t\t..:: MeNu ::..\n\n1.CREATE NEW ID\n2.USER LOGIN\n3.INFORMATION UNIT\n\n\nENTER YOUR CHOICE : \t\t\t";
    char c;
    c=getch();
    switch(c)
    {
    case '1':
        fflush(stdin);
        management();
        goto ab;
    case '3':
        fflush(stdin);
        informations();
        goto ab;
    case '2':
        fflush(stdin);
        user_login();
        goto ab;
    }
    return 0;
}

