#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

class student
{private:
    int roll;
    char name[30];
    int clas;
    int marks;

public:
    student()
    {
        roll=0;
        clas=0;
        marks=0;
    }

    student(int rolled,char nam[], int cla, int mar)
    {
        roll=rolled;
        strcpy(name,nam);
        clas=cla;
        marks=mar;
    }

    void display()
    {
        cout<<"\n\nNAME - ";
        puts(name);
        cout<<"ROLL NUMBER "<<roll<<"\nCLASS - "<<clas<<"\nMARKS - "<<marks;
    }

    int rol()
    {
    return roll;
    }

    int getdata()
    {
        cout<<"\n\n\n\t\t\tENTER THE REQUIRED DATA : - ";
        cout<<"\nROLL NUMBER ";
        cin>>roll;
        fstream file;student r;
         file.open("DATAFILE.dat",ios::in);
        while(file.read((char*)&r,sizeof(r)))
        {
        if(r.rol()==roll)
        {
            cout<<"  ROLL NUMBER ALREADY EXIST NO DATA CREATED ";
        goto abc;}
        }
        file.close();

        cout<<"\n\nNAME - ";
        cin>>name;
        cout<<"\nENTER THE CLASS ";
        cin>>clas;
        cout<<"\nTHE THE MARKS ";
        cin>>marks;
      return 1;
      abc:
          return 0;
    }
};


int disp(int c,int p)
{student r;
int y=0;
fstream file("DATAFILE.txt",ios::in|ios::out);
fstream file2("DATAFILE.txt",ios::in|ios::out);
         cout<<"\n\n";

          while(file.read((char*)&r,sizeof(r)))
            {
                if(r.rol()==c && p==0 )
                {r.display(); break;}


                if(r.rol()==c && p==1)
                {
                   file.seekg(y);
                r.getdata();
                file.write((char*)&r,sizeof(r));
                break;
                }
                 file2.read((char*)&r,sizeof(r));
                y=file2.tellg();
            }

        file.close();
        file2.close();
    return 0;
}


int displ(int c)
{student r;
fstream file("DATAFILE.txt",ios::in);
fstream file2("DATAFILEs.txt",ios::out|ios::app);


          while(file.read((char*)&r,sizeof(r)))
            {
                if(r.rol()!= c)
                {
                file2.write((char*)&r,sizeof(r));
                }
            }

        file.close();
        file2.close();

        remove("DATAFILE.txt");
        rename("DATAFILEs.txt","DATAFILE.dat");
    return 0;
}

int main()
{   ab:
    student r,s;
    int c;
    fstream file;

    do{cout<<"\n\n\n\t\t\t\t..:: MENU ::..\n\n";
    cout<<"1. CREATE NEW DATA \n2. DISPLAY ALL\n3. DISPLAY \n4. MODIFY\n5. DELETE ";
    char a;
    system("color f0");
    a=getch();

    switch(a)
    {
    case '1':
       c= r.getdata();
       if(c==0)
       {
       break;
       }
        file.open("DATAFILE.txt",ios::out|ios::app);
        file.write((char*)&r,sizeof(r));
        file.close();

        break;


    case '2':

         file.open("DATAFILE.txt",ios::in);
         cout<<"\n\n";

          while(file.read((char*)&r,sizeof(r)))
            {
                r.display();
                cout<<"\n\n\n";
            }

        file.close();

        break;
    case '3':
        cout<<"\n\n\n\tENTER THE ROLL NUMBER TO BE DISPLAYED - " ;
        cin>>c;
        disp(c,0);
        break;
    case '4':
        cout<<"\n\n\n\tENTER THE ROLL NUMBER TO BE EDITED - " ;
        cin>>c;
        disp(c,1);
        break;
    case '5':
        cout<<"\n\n\n\tENTER THE ROLL NUMBER TO BE DELETED - " ;
        cin>>c;
        displ(c);
        break;
    }}while(a<'6');

    return 0;
}
