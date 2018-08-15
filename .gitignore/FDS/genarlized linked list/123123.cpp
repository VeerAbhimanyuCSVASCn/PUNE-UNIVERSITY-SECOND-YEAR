#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct node
{   char data[100];
    struct node* left,*right;
}*start=NULL,*cord=NULL;


int create()
{   struct node *p=(struct node *)malloc(sizeof(struct node));
    printf("\n\nENTER THE DATA - ");
    scanf("%s",&p->data);
    fflush(stdin);
    p->left=NULL;
    p->right=NULL;
    if(start==NULL)
        {start=p;
        return 0;        }
    printf("\n\nclick (l) for sub-data or (r) for main data - ");
    char t;
    t=getch();
    fflush(stdin);
    if(t=='r')
        {
        cord=start;
        while(cord->right!=NULL)
            cord=cord->right;
        cord->right=p;}

    if(t=='l')
    {
        cord=start;
        char i[100];
        scanf("%s",&i);
        while(strcmp(cord->data,i))
            {printf("%d",cord->data);
                cord=cord->right;}
            if (!strcmp(cord->data,i))
                {
                if(cord->left==NULL)
                    {cord->left=p;
                     return 0;
                    }

                else
                    {
                       struct node *o;
                       o=cord->left;
                       cord->left=p;
                       p->right=o;       }
                 }
            else
            {
                printf("NO DATA IS THERE - ");
                free(p);
            }
    }
}


void display(struct node *r)
{    while(cord!=NULL)
       {printf("%s\n",cord->data);
        cord=cord->right;}}


int sub(struct node*r,int i)
{
    if(r==NULL)
        return 0;
        if(i==0)
    printf("%s\n",r->data);
        if(i==1)
    printf("\t%s",r->data);

    sub(r->left,1);
    printf("\n\n");
    sub(r->right,0);

}



int main()

{ab:
    system("color f0");
    printf("\n\n\n\t\t\t..:: MENU ::..\n\n");
    printf("1.insert\n\n2.display main list \n\n3.display sublist if any \n\n");
    char i;
    i=getch();

    switch(i)
    {
    case'1':

        create();
        goto ab;
    case'2':
        display(start);
        goto ab;
    case '3':
        sub(start,0);
        goto ab;

        }
    return 0;
}
