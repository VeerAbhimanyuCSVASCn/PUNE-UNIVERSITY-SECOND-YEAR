#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
    struct student
    {
        char name[50];
        int rno;
        int classs;
    };

    struct student * getdata()
    {
        struct student *a=0;

        a=(struct student*)malloc(sizeof(struct student));
        printf("\n\n\nenter the name of student - ");
        scanf("%s",a->name);
        printf("\nenter the roll number ");
        scanf("%d",&a->rno);
        printf("\nenter the class ");
        scanf("%d",&a->classs);
        return a;
    }





    int display(int y)
    {
    FILE *a;
    int f;
    struct student q;
    a=fopen("abc.dat","r");
        if(y==0)
        {

            printf("\n\nENTER THE ROLL NUMBER TO BE DISPLAYED ");
            scanf("%d",&f);
        }
        printf("\n\n\n STUDENT's NAME\t\t\tROLL NUMBER\t\t\tCLASS");
        printf("\n_____________________________________________________________________________________");

        while(!feof(a))
        {
            fscanf(a,"%s%d%d",&q.name,&q.rno,&q.classs);
            if(q.rno==f&&y==0)
            {
                printf("\n\n%s\t\t\t\t%d\t\t\t%d",q.name,q.rno,q.classs);
                fclose(a);
                return 1;
            }
            if(y==1)
            {
                printf("\n\n%s\t\t\t\t%d\t\t\t%d",q.name,q.rno,q.classs);
            }
        }
    fclose(a);
    printf("\n\n\n\n\n");
    return 0;
    }


    void deletes()
    {   int as;
        FILE *a,*b;
        struct student w;
        a=fopen("abc.dat","a+");
        rewind(a);
        b=fopen("abcd.dat","w");
        printf("\n\n\nENTER THE ROLL NUMBER TO BE DELETED ");
        scanf("%d",&as);
        while(!feof(a))
        {
            fscanf(a,"%s%d%d",&w.name,&w.rno,&w.classs);
            if(as!=w.rno)
            {
            fprintf(b,"%s %d %d",w.name,w.rno,w.classs);
            }
        }
        fclose(a);
        fclose(b);
        remove("abc.dat");
        rename("abcd.dat","abc.dat");
    }




    int modify()
    {
    FILE * a;
    int qa,t;
    struct student q;
    struct student *abh;
    int y;
    a=fopen("abc.dat","r+");
    printf("\n\n\nenter the ROLL NO to be modified  - ");
    scanf("%d",&qa);
    while(!feof(a))
        {
            t=ftell(a);
        fscanf(a,"%s%d%d",&q.name,&q.rno,&q.classs);
        if(qa==q.rno)
            {
                 fseek(a,t,0);
        abh=getdata();
        y=searches(abh->rno);
        if(y)
            {
            printf(" \n\nDATA NOT CREATED \n\n");
            return 0;}
        fprintf(a,"%s %d %d",abh->name,abh->rno,abh->classs);
        printf("\n\nDATA INSERTED SUCCESSFULLY \n\n");
        fclose(a);
            return 0;}
        }
        return 0;
        }


    int searches(int t)
    {   FILE *a;
        struct student q;
        a=fopen("abc.dat","r");
        while(!feof(a))
        {   fscanf(a,"%s%d%d",&q.name,&q.rno,&q.classs);
            if(q.rno==t)
                {   fclose(a);
                    return 1;}
        }
        fclose(a);
        return 0;
    }

    int create()
    {   struct student *abh;
        FILE *a;
        int y;
        a=fopen("abc.dat","a+");
        abh=getdata();
        y=searches(abh->rno);
        if(y)
            {
            printf(" \n\nDATA NOT CREATED \n\n");
            return 0;}

        fprintf(a,"%s %d                                                                     %d",abh->name,abh->rno,abh->classs);
        printf("\n\nDATA INSERTED SUCCESSFULLY \n");
        fclose(a);
        return 1;
    }




int main()
{
    char a;int t;
    ab:
        system("color f0");
    printf("\n\n\n\t\t\t\t..:: MENU ::..\n\n");
    printf("1.INSERT\n2.MODIFY\n3.DELETE\n4.DISPLAY\n5.DISPLAY ALL\n\n\n\t\t\t");
     a=getch();

    switch(a)
    {
    case'1':
        create();
        goto ab;
    case '2':
        modify();
        goto ab;

    case '3':
        deletes();
        goto ab;

    case '4':
        t=display(0);
        if(!t)
        {printf("\n\n .. SORRY..!! NO SUCH DATA FOUND \n\n");}
        goto ab;
    case '5':
        display(1);
        goto ab;
    }

return 0;
}
