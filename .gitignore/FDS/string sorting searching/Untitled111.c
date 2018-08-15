#include<stdio.h>
#include<conio.h>
#include<string.h>


void BUBBLE(char u[],int r)
        {
            int i,j;
            char temp;
            printf("\n\n\n BUBBLE SORT OF STRING %s",u);
            for( i=0;i<r;i++)
            {
                for( j=0;j<r-1-i;j++)
                {
                 if(u[j]>u[j+1])
                 {
                     temp=u[j];
                     u[j]=u[j+1];
                     u[j+1]=temp;
                 }
                }
                 printf("\n  %s",u);
            }
        }



void SELECTION(char *t,int r)
{   char larg,temp;
    int y,i,j;

    for( i=0;i<r-1;i++)
    {
        larg=t[i];
        y=i;

        for( j=i+1;j<r;j++)
        {
           if(t[j]>larg)
               {
                larg=t[j];
                y=j;               }

        }

        temp=t[i];
        t[i]=t[y];
        t[y]=temp;


        printf("\n\n%s",t);
    }
}





int Bsearch(char *t,int start,int last,char u)
{ int mid=(start+last)/2;
    printf(" %d %d ",start,last);

    if(last<start)
    {
        printf(" NOT FOUND STRING IS NOT SORTED ");
        return 0;
    }

    if(start==last)
        {
            if(t[mid]==u)
                {printf(" FOUND ");
                   return 0;}

            if(t[mid]!=u)
            {

         printf(" SORRY NOT FOUND ");
            return 0;}
        }


    else


    {
        if(t[mid]==u)
            {
            printf("\n\n\n FOUND ");
            return 0;
            }

        if(t[mid]<u)
            {start=mid+1;
                Bsearch(t,start,last,u);}

        if(t[mid]>u)
            {last=mid-1;
                Bsearch(t,start,last,u);}

            }
    }





void bsearch(char *t,int r)
{
    int start,ends,mid;
    char a;
    printf("\n\n\nENTER THE CHARECTER TO BE SEARCHED - ");
    a=getch();

    start=0;
    ends=r-1;
    mid=(start+ends)/2;
    while(start<=ends)
    {
        if(t[mid]==a)
        {
            printf("\n\n FOUND at %d",mid);
            break;
        }

        if(t[mid]<a)
        {start=mid+1;}

        if(t[mid]>a)
        {ends=mid-1;}

    mid=(start+ends)/2;


    }



}


void INSERTION(char *t, int r)
{
    int i,temp,j;
    for( i=1;i<r;i++)
    {
        temp=t[i];
        j=i-1;

        while(temp<t[j])
        {
            t[j+1]=t[j];
            --j;
        }
        t[j+1]=temp;



    printf("\n\n%s",t);
    }
}

int main()
{   int p;
    char a,c;
    char *w;
    w=(char *) malloc (sizeof(char)*50);
system("color f0");
   ab:
    printf("\n\n\n\t\t\t ENTER THE STRING TO PERFORM FURTHER OPERATIONS  ");
    scanf("%s",w);

    p= strlen(w);

    printf("\n\n1.BUBBLE SORT\n2.SELECTION SORT\n3.INSERTION SORT\n4.BINARY SEARCH\n5.RECURSIVE BINARY SEARCH");
    a=getch();


    switch(a)
    {
    case '1':
      BUBBLE(w,p);
      goto ab;

    case '2':
        SELECTION(w,p);
        goto ab;

    case '3':
        INSERTION(w,p);
        goto ab;

    case '4':
        bsearch(w,p);
        goto ab;
    case '5':

        printf(" \n\n ENTER THE CHARECTER TO BE SEARCHED ");
        c=getch();
        Bsearch(w,0,p-1,c);
        goto ab;


    }
}
