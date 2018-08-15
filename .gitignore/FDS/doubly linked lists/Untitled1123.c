#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct data
{
    int n;
    struct data *node;
    struct data *node2;

}
*f=NULL,*b=NULL;







void modify()
{   int q,i;
    struct data *a;
    a=f;
    printf("ENTER THE DATA NUMBER TO BE MODIFIED ");
    scanf("%d",&q);

    for(i=1;i<q;i++)

    {
        a=a->node;
        }
      scanf("%d",&a->n);
}


void displayb ()
{    struct data *i;
    i=b;
    while(i!=NULL)
    {
        printf(" %d - > ",i->n);
        i=i->node2;
    }
}









void displayforward ()
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
    displayforward();
    if(f==NULL)
       {
        printf(" NO DATA FURTHER DELETION NOT POSSIBLE ");
        return 0;
       }
    printf("\n\nENTER THE RECORD NUMBER TO BE DELETED start from 1");
    scanf("%d",&i);



    if(i==1)
    {
        r=r->node;
        free(f);
        f=r;
        displayforward();
        return 0;
    }
   i=i-1;


    for(j=1;j<i;j++)
    {
    q=q->node;
    r=r->node;
    printf("%d",r->n);
    if(r->node->node==NULL)
        {
        p=b;
        b=b->node2;
        b->node=NULL;
        p->node2=NULL;
        free(p);
        return 0;
        }
    }
    r=r->node;
    r=r->node;
    p=q->node;
    p->node=NULL;
    p->node2=NULL;
    q->node=r;
    r->node2=q;
    free(p);
    displayforward();
return 0;
}


int intsert(struct data *r)
{
    b->node=r;
    r->node2=b;
    b=r;
    return 0;
    }





int insertvalid(struct data *r,int t)
{   int i;
struct data *a=f,*c=f;
    for( i=1;i<t;i++)
    { a=a->node;
      c=c->node;
      if(a==b)
      {
          intsert(r);
          return 0;
      }
    }
    c=c->node;
    a->node=r;
    r->node=c;
    c->node2=r;
    r->node2=a;
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
    p->node2=NULL;
     if(f!=NULL)
     {
         displayforward();
         printf(" \n\nENTER THE POSITION TO INSERT NEW DATA \ncount starts from 1");
         scanf("%d",&i);
         if(i==1)
         {
             f->node2=p;
             p->node=f;
             f=p;
             return 0;
         }
         insertvalid(p,i-1);
     }
        if(f==NULL)
    {
        f=p;
        b=p;
     printf("FIRST DATA CREATED AND INSERTED ");
    }
return 0;
}






int main()
{   char a;
    ab:
        system("color f0");
    printf(" \n\n\n\t\t\t<<  MENU  >>\n\n1.CREATE AND INSERT\n2.DELETE \n3.DISPLAY FORWARD\n4.DISPLAY BACKWARD\n5.MODIFY\n\n\t\t");
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
        displayforward();
        goto ab;
    case'4':

        displayb();
        goto ab;
    case '5':
        modify();
        goto ab;
    }
    return 0;
}
