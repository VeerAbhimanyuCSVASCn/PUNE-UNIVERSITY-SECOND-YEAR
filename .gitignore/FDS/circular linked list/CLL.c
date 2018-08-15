#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct cll
{
    float coff;
    int power;
    struct cll* next;
};




struct cll* val (struct cll *a ,struct cll *node)
{   struct cll *u=NULL;


    if(a==NULL)
    {
        a=node;
        a->next=a;

        return a;
    }

    if(node->power > a->power)
    {
        node->next=a->next;
        a->next=node;
        a=node;
        return a;
    }
    if(node->power == a->power)
    {
        a->coff=node->coff+a->coff;
        return a;
    }
    u=a;
    while(u->next!=a && node->power>=u->next->power)
        u=u->next;
    if(node->power == u->power)
        u->coff = u->coff+node->coff;
    else
        {
        node->next=u->next;
    u->next=node;
        }

    return a;
}






struct cll* insert(struct cll *a,float co,float po)
{
    struct cll *node;
    node=(struct cll*)malloc(sizeof(struct cll));
    node->coff=co;
    node->power=po;
    node->next=NULL;
    a=val(a,node);
    return a;
}






void display(struct cll * q)
{
    struct cll *u;
    u=q;
  u=q->next;
    do
    {
        printf("%5.1f x^ %d + ",u->coff,u->power);
        u=u->next;
    }while(u!=q->next);
}





void evaluate(float a, struct cll * b)
{    long int r=0;
    struct cll *c=b;
    do
    {
        r=r+(c->coff)*pow(a,c->power);
    c=c->next;
    }while(b->power!=c->power);

    printf("\n\n ANSWER IS : - %lld",r);
}




int sum(struct cll *a, struct cll * b)
{
    struct cll *c=NULL;
    struct cll *u=NULL,*v=NULL;
    u=a->next;
    do
    {v=(struct cll *)malloc(sizeof(struct cll));
         v->coff=u->coff;
        v->power=u->power;
        v->next=NULL;
        c=val(c,v);
        u=u->next;
    }while(u!=a->next);


        u=b->next;

     do
    {v=(struct cll *)malloc(sizeof(struct cll));
        v->coff=u->coff;
        v->power=u->power;
        v->next=NULL;
        u=u->next;
        c=val(c,v);
    }while(u!=b->next);
display(c);
return 0;
}



int multiply(struct cll *a, struct cll *b)
{

    struct cll *h1=0,*h2=0,*h3=NULL,*r=0;

    h2=b->next;
    do
    {
        h1=a->next;
        do
            {

                  r=(struct cll *)malloc(sizeof(struct cll));
                  r->power=(h1->power+h2->power);
                  r->coff=(h1->coff*h2->coff);
                  r->next=NULL;

                  h3=val(h3,r);
                  h1=h1->next;

            }while(h1!=a->next);
                h2=h2->next;
    }while(h2!=b->next);

    display(h3);

    return 0;
}


int main()
{  struct cll *p=NULL,*q=NULL;
    char a;
    float co=0,de=0,qa;
    int ra;
    ab:

    printf("\n\n\n\t\t\t..:: MENU ::.. \n\n");
    printf("\n1.inset in 1st polynomial\n2.insert in second polynomial\n");
    printf("\n3.print polynomial\n4.add \n5.multiply\n6.evaluate\n\n\t\t");
    a=getch();

    switch(a)
    {
    case'1':
        {   printf("\n\nENTER THE COFFECIENT - ");
            scanf("%50f",&co);
            printf("\nENTER THE DEGREE     - ");
            scanf("%50f",&de);
            p=insert(p,co,de);
            goto ab;
        }


    case'2':
            {printf("\n\nENTER THE COFFECIENT - ");
            scanf("%50f",&co);
            printf("\nENTER THE DEGREE     - ");
            scanf("%50f",&de);
            q=insert(q,co,de);
            goto ab;
            }


    case'3':


        if(p!=NULL)
        {printf(" EQUATION 1 : - \n\n");
        display(p);}
        if(q!=NULL)
        {printf(" EQUATION 2 : - \n\n");
        display(q);}
        goto ab;


    case'4':

        sum(p,q);
    goto ab;



    case'5':
        multiply(p,q);
    goto ab;



    case'6':

        printf("\n\nENTER A VARIABLE & POLYNOMIAL NUMBER TO EVALUATE - ");
        scanf("%f%d",&qa,&ra);
        if(ra==1  && p!=NULL)
            evaluate(qa,p);
        else
            if(q!=NULL)
            evaluate(qa,q);
    goto ab;
    }




    return 0;
}
