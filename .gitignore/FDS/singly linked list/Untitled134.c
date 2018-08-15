#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct data
{
    int n;
    struct data *node;
}*f=NULL;


int insertvalid(struct data * a,int i)
{
    struct data *p=f,*q=f;
    int j;
    for( j=0;j<i;j++)
    {
     p=p->node;
     q=q->node;
    }
    q=q->node;
    p->node=a;
    a->node=q;
return 0;
}




void display()
{    struct data *i;
    i=f;
    while(i!=NULL)
    {
        printf(" %d - > ",i->n);
        i=i->node;
    }
}


int deletes()
{   int i,j;
    struct data *q=f,*r=f,*p=NULL;
    display();
    if(f==NULL)
       {
        printf(" NO DATA FURTHER DELETION NOT POSSIBLE ");
        return 0;
       }
    printf("\n\nENTER THE RECORD NUMBER TO BE DELETED start from 1");
    scanf("%d",&i);

    i=i-1;

    if(i==0)
    {
        r=r->node;
        free(f);
        f=r;
        display();
        return 0;
    }
    for(j=1;j<i;j++)
    {
    q=q->node;
    r=r->node;
    }
    r=r->node;
    r=r->node;
    p=q->node;
    q->node=r;
    free(p);
    display();
return 0;
}


int reversed()
{
    struct data *a=f,*b=NULL,*c=f,*d=NULL;

    while(c!=NULL)
    {
     if(c->node==NULL)
     break;
     c=c->node;
    }

    c->node=d;
     b=c;

    while(f!=c)
    {   a=f;
        f=f->node;
        a->node=NULL;
        b=b->node;
        c->node=a;
        a->node=b;
        b=c;



/*        display();
        printf("  \n");
*/
    }

    f=c;

    return 0;

}

int create()
{
    struct data * p;
    int i;
    p=(struct data *)malloc(sizeof(struct data));
    printf("\n\nENTER THE DATA ");
    scanf("%d",&p->n);
    p->node=NULL;


     if(f!=NULL)
     {
         display();
         printf(" \n\nENTER THE POSITION TO INSERT NEW DATA \ncount starts from 1");
         scanf("%d",&i);

         if(i==1)
         {
             p->node=f;
             f=p;
             return 0;
         }
         insertvalid(p,i-2);
     }

        if(f==NULL)
    {
        f=p;
     printf("FIRST DATA CREATED AND INSERTED ");


    }

return 0;
}


int main()
{   char a;
    ab:
        system("color f0");
    printf(" \n\n\n\t\t\t<<  MENU  >>\n\n1.CREATE AND INSERT\n2.DELETE \n3.DISPLAY\n4.REVERSE DISPLAY\n5.LIST REVERT\n\n\t\t");
    a=getch();

    switch(a)
    {

    case '1':
        create();
        goto ab;



    case '2':
        deletes();
        goto ab;



    case '3':
        display();
        goto ab;



    case'4':

        reversed();
        display();
        reversed();
        goto ab;


    case '5':
        reversed();
        printf("\n\n");
        display();
        goto ab;


    }

    return 0;
}
