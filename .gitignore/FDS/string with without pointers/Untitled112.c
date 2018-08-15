#include<stdio.h>
#include<conio.h>
#include<string.h>

int reversed(char *a)
{ int u,i;
   char g;
   u=strlen(a);
    printf("\n%s IS CURRENT STRING ",a);

   for(i=0;i<(u/2);i++)
   {
   g=a[i];
   a[i]=a[u-i-1];
   a[u-i-1]=g;
   }
    printf(" \n\nNOW! IT CHANGES TO %s",a);
return 0;
}






void copied(char *a,char *b)
{ int u,i;
   char g;
   u=strlen(a);
    printf("\n%s IS CURRENT STRING 1 ",a);
    printf("\n%s IS CURRENT STRING 2 CONTAIN GARBAGE \n\n\n\n",b);

    for( i=0;i<u;i++)
    b[i]=a[i];
     b[u]='\0';
    printf("\n%s IS new STRING 1 ",a);
    printf("\n%s IS new STRING 2 WHICH IS COPIED VALUE\n\n",b);
}



int compare(char c[],char d[])
{     int i,j,k,l;

i=strlen(c);
j=strlen(d);
if(i>=j)
k=i;
else
k=j;

for(l=0;l<k;l++)
{
  if(c[l]!=d[l])
  {
    if(c[l]>d[l])
    {
    printf("\n\n\t STRING 1 IS GREATER ");
    }
    else
    printf("\n\n\t STRING 2 IS GREATER");
    return 0;
  }
}
printf("\n\n\tboth strings are  same ");
 return 0;
}










int palindrome(char *a)
{ int u,i;
   char g;
   u=strlen(a);
    printf("\n%s IS CURRENT STRING ",a);

   for(i=0;i<u/2;i++)
   {
   if(a[i]!=a[u-i-1])
   {printf("\n\t and it is NOT A PALINDROME");
    return 0;
    }
   }
   printf("\n\t and it is A PALINDROME");
   return 0;

}



 void searches(char *c,char e)
 {
 int t,i,r=0;
 printf("\n\nSTRING 1 CONTAINS %s \n",c);
 printf("\n%c TO BE SEARCHED \n\n\n",e);
 t=strlen(c);
 for(i=0;i<t;i++)
 if(c[i]==e)
 printf("\n\tSTRING FOUND AT POSITION %d\n",i+1);
 if(r==0)
 printf("\n\tSTRING NOT FOUND");

 }




int main()
{ char a,*d,*c,e;
xy:
c=(char*)malloc(sizeof(char)*100);
d=(char*)malloc(sizeof(char)*100);
printf("MENU\n\n\n1.REVERSE\n2.PALINDROME\n3.COPY\n4.COMPARE \n5.SEARCH");
printf("\nclick other number to TERMINATE...!!!\n\n\t\t\t");


 a=getch();
 if(a<='3')
 {   printf("PLEASE ENTER THE FIRST STRING : \n");
  gets(c);
 }

 if(a=='4')
 {   printf("PLEASE ENTER THE FIRST STRING : \n");
 gets(c);printf("\nPLEASE ENTER THE SECOND STRING : \n");
 gets(d);
 }


 if(a=='5')
 {   printf("PLEASE ENTER THE FIRST STRING : \n");
 gets(c);
 printf("\nPLEASE ENTER THE SEARCH STRING : \n");
 e=getch();
 }



 switch(a)
 {
 case '1':
 reversed(c);
 getch();
 goto xy;

 case '2':
 palindrome(c);   getch();
 goto xy;

 case '3':
 copied(c,d);       getch();
 goto xy;

 case '4':
 compare(c,d);    getch();
 goto xy;

 case '5':
 searches(c,e);     getch();
 goto xy;

 }
return 0;
}
