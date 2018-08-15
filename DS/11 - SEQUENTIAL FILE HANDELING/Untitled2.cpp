#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

using namespace std;

struct student
{
    char name[100];
    int clas;
    int roll;
    char address[100];


    student(){}
    student(char n[],int cl,int rol,char add[])
    {
        strcpy(name,n);
        strcpy(address,add);
        clas=cl;
        roll=rol;

    }


    void display()
    {
        cout<<roll<<"."<<name<<"\n CLASS: "<<clas<<"\n ADDRESS: "<<address<<endl<<endl<<endl;
    }
};


void displayall()
{fstream file;
    file.open("student.txt",ios::in);
    student t;
    while(file.read((char*)&t,sizeof(student)))
        {t.display();}
    file.close();

}


void del(int roll)
{
    fstream file,file2;
    file.open("student.txt",ios::in);
    file2.open("temp.txt",ios::out);
    student t;

    while(file.read((char*)&t,sizeof(student)))
        {
            if(t.roll!=roll)
            file2.write((char*)&t,sizeof(student));
        }
file.close();
file2.close();
remove("student.txt");
rename("temp.txt","student.txt");
}

student searched(int roll)
{
    fstream file;
    file.open("student.txt",ios::in);
    student t;
    t.roll=-1;


    while(file.read((char*)&t,sizeof(student)))
        {if(t.roll==roll)
            {
                file.close();
                return t;
            }
        }
    t.roll=-1;
    file.close();
    return t;
}


int insert()
{
    fstream file;
    file.open("student.txt",ios::out|ios::app);
    cout<<"ENTER THE DATA OF STUDENT TO BE INSERTED - \n\n";
    char name[100];
    cout<<"name : ";
    cin>>name;
    cout<<"\nRoll NUMBER :";
    int roll;
    cin>>roll;
fflush(stdin);


    if(searched(roll).roll!=-1)
    {   cout<<"ROLL NUMBER ALREADY EXIST - ";
        return 0;}

    cout<<"\nClass : ";
    int clas;
    cin>>clas;
    cout<<"\nADDRESS : ";
    char add[100];
    cin>>add;

    student b(name,clas,roll,add);

    file.write((char*)&b,sizeof(student));
//    delete(b);
    file.close();
return 0;
}



int modify(int rolled)
{
    fstream file,file2;

    cout<<"ENTER THE DATA OF STUDENT TO BE INSERTED - \n\n";
    char name[100];
    cout<<"name : ";
    cin>>name;
    cout<<"\nRoll NUMBER :";
    int roll;
    cin>>roll;
    fflush(stdin);


    cout<<"\nClass : ";
    int clas;
    cin>>clas;
    cout<<"\nADDRESS : ";
    char add[100];
    cin>>add;

    student b(name,clas,roll,add);


    file.open("student.txt",ios::in);
    file2.open("temp.txt",ios::out);
    student t;

    while(file.read((char*)&t,sizeof(student)))
        {

            if(t.roll==rolled)
            file2.write((char*)&b,sizeof(student));
            else
                file2.write((char*)&t,sizeof(student));
        }
file.close();
file2.close();
remove("student.txt");
rename("temp.txt","student.txt");


}

int main()
{int roll;
student y;
    ab:

    system("color f0");
    cout<<"\n\n\n\t\t\t..:: MENU ::..\n\n1.INSERT\n2.DELETE\n3.MODIFY\n4.SEARCH\n5.DISPLAY ALL \n";
    switch(getch())
    {
    case'1':
        insert();
        goto ab;
    case'2':
        cout<<"ENTER THE ROLL NUMBER TO BE DELETED - ";
        cin>>roll;
        del(roll);
        goto ab;;
    case'3':
        cout<<"ENTER ROLL NUMBER TO BE MODIFIED - ";
        cin>>roll;
        modify(roll);
        goto ab;
    case'4':cout<<"ENTER THE ROLL NUMBER TO BE SESRCHED - ";
        cin>>roll;
        y=searched(roll);
        if(y.roll!=-1)
        y.display();
        else
            cout<<" DATA NOT FOUND \n\n";
        goto ab;
    case'5':
        displayall();
        goto ab;

    }
}
