#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct student
{
    char name[100];
    int clas;
    int roll;
public:
    void getdata()
    {   cout<<"ENTER THE NAME OF STUDENT - ";
        gets(name);

        fflush(stdin);
        cout<<"\nENTER THE CLASS OF THE STUDENT - ";
        cin>>clas;
        cout<<"\nENTER THE ROLL NUMBER - ";
        cin>>roll;
    }
       void putdata()
    {
        puts(name);
        fflush(stdin);
        cout<<"\t"<<clas<<"\t"<<roll;
    }
};


int main()
{
    system("color f0");
    fstream k;
    student g;
char c;
do
{cout<<"\n\n\nMENU\n\n"<<"1.GETDATA\n2.DISPLAY FILE\n\n\t\t";
c=getch();

switch(c)
{
    case'1':
        k.open("temp.dat",ios::out|ios::app|ios::binary);
        g.getdata();
        k.read((char*)&g,sizeof(student));
        k.close();
        break;
    case'2':
        k.open("temp.dat",ios::in|ios::binary);
        k.write((char*)&g,sizeof(student));
        g.putdata();
        k.close();
}
}while(c<'3');
return 0;
}
