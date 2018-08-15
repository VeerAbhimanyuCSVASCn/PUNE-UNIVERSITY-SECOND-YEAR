#include"stack.cpp"
#include<ctype.h>



stackcode <char> t;

char* converter(string a)
{


    t.push(' ');
    char *d=new char[a.length()+5];

    int k=0;

    for(int i=0;i<a.length();i++)
    {

        char c;

        if(a[i]>='a'&&a[i]<='z'  || a[i]>='A'&&a[i]<='Z' ||a[i]>='0' && a[i]<='9')
            {   d[k++]=a[i];
              //  cout<<"enter1";
            }


        else
        if(a[i]=='(')
            {t.push('(');

            //cout<<"enter2";
            }


        else
            if(a[i]==')')
         {
             while((c=t.pop())!='(')
             {
                 d[k++]=c;
          //       cout<<"enter3";
             }

         }

        else
            {
                if(  precidence(a[i])  < precidence(t.toper()) )
                {
                    while(precidence(a[i])  < precidence(t.toper()))
                    {
                        d[k++]=t.pop();
                    }
                    t.push(a[i]);
      //              cout<<"enter4";
                }

                else
                {
                    t.push(a[i]);
        //            cout<<"enter5";
                }
            }


    }


   while(t.isnull())
    {

        d[k++]=t.pop();

    //cout<<"enter6";
    }
    d[k]='\0';





    //for(int i=0;i<d[i]!='\0';i++)
      //  cout<<d[i];

    return d;
}






/*
int main()
{
    system("cls");
    system("color f0");
    string a,b;
    cout<<"ENETR AN EXPRESSION IN INFIX FORMAT for CONVERSION INTO POSTFIX FORMAT \n\n";
    cin>>a;

    b=converter(a);
    cout<<b;

    return 0;
}


*/
