#include<stdio.h>
#include<stdlib.h>
#include<conio.h>



struct employee
{
    int t;
int code;
char name[100];

union asd
{
int salary;
char grade;
}an;


};


 struct employee emo[50];







struct employee newemp()
{ int a;
    struct employee w;
printf("\n\n\nENTER THE RECORD OF EMPLOYEE \n");
printf("\n\nENTER THE EMPLOYEE CODE ");
scanf("%d",&w.code);
printf("\nENTER THE EMPLOYEE NAME ");
scanf("%s",&w.name);
printf("ENTER THE TYPE YOU WANT TO INSERT ");
scanf("%d",&a);
w.t=a;
if(a==1)
{printf("\nENTER THE EMPLOYEE salary ");
scanf("%d",&w.an.salary);}
if(a==2)
{printf("\n\nENTER THE GRADE ");
scanf("%s",&w.an.grade);
}
return w;
}






void deleteer(int i,int t)
{
    int y;

    for(y=i;y<t;y++)
    {
    emo[y]=emo[y+1];
    }

}








void output(int i)
{
    printf("\n\n EMPLOYEE CODE ");
    printf("%d",emo[i].code);
    printf("\nENTER THE EMPLOYEE NAME ");
    printf("%s",emo[i].name);

    if(emo[i].t==1)
    {
        printf("\nENTER THE EMPLOYEE salary ");

        printf("%d",emo[i].an.salary);}
    if(emo[i].t==2)
    {


    printf("\nENTER THE GRADE ");
    printf("%c",emo[i].an.grade);
    }
}









int search(int r,int y,int t)
{int i;
struct employee f;

    if(y==0)
       for( i=0;i<50;i++)
        if(emo[i].code==r)
        {  output(i);
           return 0;
        }

     if(y==1)
     {
         for( i=0;i<50;i++)
        if(emo[i].code==r)
         {
             f=newemp();
             emo[i]=f;
             return 0;
         }

     }

          if(y==2)
     {


         for( i=0;i<50;i++)
        if(emo[i].code==r)
         {
         deleteer(i,t);
         return 0;

         }

     }

return 100;


}





int main()
{
    int t=0,i;
 char a;
    int r;
   struct employee nd;
ab:
    system("color f0");
   printf("\n\n\n\t\t\t\t..::MENU::..\n\n");
   printf("PRESS 1. NEW EMPLOYEE RECORD ENTRY\nPRESS 2. DISPLAY\nPRESS 3. DISPLAY ALL\nPRESS 4. MODIFY PARTICULAR\nPRESS 5. DELETE\n\n\n\t\t\t");
   a=getch();

  switch(a)
   {
   case '1':
   nd=newemp();
   emo[t]=nd;
   ++t;

   goto ab;

   case '2':
       printf("enter the employee code to be displayed : ");
       scanf("%d",&r);
	r=search(r,0,t);

	if(r>50)
	    printf("NO SUCH DATA PRESENT ");

 goto ab;

  case '3':

       for( i=0;i<t;i++)
        {output(i);}


    goto ab;


  case '4':

      printf("enter the employee code to be modified : ");
       scanf("%d",&r);
	r=search(r,1,t);

	if(r>50)
	    printf("NO SUCH DATA PRESENT ");

 goto ab;


 case '5':


    printf("enter the employee code to be deleted : ");
       scanf("%d",&r);
	r=search(r,2,t);

	if(r>50)
	    printf("NO SUCH DATA PRESENT ");
    else
    {

        printf("\n\n\nDATA DELETED SUCCESSFULLY ");
    --t;
    }

    goto ab;
}



 return 0;
}


