
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
using namespace std;

struct student
{   char name[100];
    int clas;
    int roll;
    char address[100];
    int status;
    student()
    {strcpy(name,"XXXX");
        strcpy(address,"XXXX");
        clas=-1;
        roll=-1;
        status=-1;
    }

    student(char n[],int cl,int rol,char add[])
    {   strcpy(name,n);
        strcpy(address,add);
        clas=cl;
        roll=rol;
        status=1;
        }

        void getdata(int p)
        {   roll=p;
            cout<<"name - ";cin>>name;
            cout<<"class- ";cin>>clas;
            cout<<"ADDRESS - ";cin>>address;
            status=1;
        }
    void display()
    {cout<<roll<<"."<<name<<"\n CLASS: "<<clas<<"\n ADDRESS: "<<address<<endl<<endl<<endl;}
};


int initial[50];
int data[50];
int next[50];
int has(int a)
{
    int key  = a%50;

    if(data[key]==-1)
    {initial[key]=key;
     data[key]=a;
     next[key]=-1;
     return key;
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
           m=(m+1)%50;
       }
    data[m]=a;
    initial[key]=m;
    next[key]=-1;
return m;
   }

    while(next[t]!=-1)
    {        t=next[t];}
    int r=t;
    int s=0;
while(s<50)
    {++s;
        if(s==49)
            return -1;
   if(data[r]!=-1)
        {            r=(r+1)%50;continue;
        }
      break;
    }


    data[r] = a;
    next[t]=r;
    return r;

}




int insert()
{
    fstream file;
    file.open("student.txt",ios::out|ios::in|ios::ate);
    file.seekg(0,ios::beg);
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


    file.seekg(has(roll)*sizeof(student),ios::beg);
    file.write((char*)&b,sizeof(student));
    file.close();
return 0;
}




void displayall()
{fstream file;
    file.open("student.txt",ios::in);
    student t;
    while(file.read((char*)&t,sizeof(student)))
        {if(t.status==1)
            t.display();}
    file.close();

}




int searcher(int r)
{
        int p = initial[r%50];
        while(1)
        {
            if(data[p]==-1)
                break;

            if(data[p]!=r)
            {p=next[p];continue;}

            return p;
        }
        return -1;
}



int ser(int r)
{
    fstream file;
    file.open("student.txt",ios::out|ios::in|ios::ate);

    student t;
    int j=searcher(r);

    if(j==-1)
    {cout<<"\n\n\nNO SUCH DATA \n\n";
      return -1;}
    file.seekg(j*sizeof(student),ios::beg);
    file.read((char*)&t,sizeof(student));
        if(t.status==1)
            t.display();
    file.close();
}


int deleter(int roll)
{
    fstream file;
    file.open("student.txt",ios::out|ios::in|ios::ate);

    student t;
    int j=searcher(roll);
    if(j==-1)
    {cout<<"\n\n\nNO SUCH DATA \n\n";
      return -1;}
    file.seekg((j)*sizeof(student),ios::beg);
    cout<<file.tellg();
    file.write((char*)&t,sizeof(student));
    file.close();

}


int modifier(int roll)
{
fstream file;
    file.open("student.txt",ios::out|ios::in|ios::ate);

    student t;
    t.getdata(roll);
    int j=searcher(roll);
    if(j==-1)
    {cout<<"\n\n\nNO SUCH DATA \n\n";
      return -1;}
    file.seekg((j)*sizeof(student),ios::beg);
    cout<<file.tellg();
    file.write((char*)&t,sizeof(student));
    file.close();

}

int main()
{
    system("color f0");
    student t;
    int rol;
    fstream file;
    file.open("student.txt",ios::out|ios::trunc);
    for(int i=0;i<50;i++)
    {   initial[i]=data[i]=next[i]=-1;
        file.write((char*)&t,sizeof(student));
    }
    file.close();
    ab:
    cout<<"\n\n\n\t\t\t..:: MENU::..\n\n1.INSERT\n2.DELETE\n3.SEARCH display\n4.MODIFY\n5.DISPLAY ALL \n\n\n";
    switch(getch())
    {
    case'1':
        insert();
        goto ab;
    case'2':
        cout<<"ENTER THE ROLL NUMBER TO BE SEARCHED - ";
        cin>>rol;

        deleter(rol);
        goto ab;
    case'3':
        cout<<"ENTER THE ROLL NUMBER TO BE SEARCHED - ";
        cin>>rol;
        ser(rol);
        goto ab;
    case'4':
        cout<<"ENTER THE ROLL NUMBER TO BE SEARCHED - ";
        cin>>rol;
        modifier(rol);
        goto ab;
    case'5':
       displayall();
        goto ab;
   }
    return 0;
}
