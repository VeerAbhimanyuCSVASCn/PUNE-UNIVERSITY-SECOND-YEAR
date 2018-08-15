#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void display(int*a,int c)
{int i;
       for( i=0;i<c;i++)
   printf("%d ",a[i]);
   printf("\n\n ");

}



void quick(int *a,int b,int c,int n)
{

int no=b,temp,i;


if(b<c)
{
for( i=c;i>b;i--)
{
    if((a[no]>a[i] && no<i) || (a[no]<a[i]&&no>i))
    {
        temp=a[no];
        a[no]=a[i];
        a[i]=temp;

        no=i;
         printf("\n\n");
        display(a,n+1);
    }
}

for( i=0;i<c;i++)
{
    if((a[no]>a[i] && no<i) || (a[no]<a[i]&&no>i))
    {
        temp=a[no];
        a[no]=a[i];
        a[i]=temp;

        no=i;
        printf("\n\n");
        display(a,n+1);
    }




}

quick(a,b,no-1,no);

quick(a,no+1,c,c);

}

}


int main()
{
    int *a,r,i;
   scanf("%d",&r);
    a=(int *)malloc(sizeof(int)*r);

    for( i=0;i<r;i++)
   scanf("%d",&a[i]);

    quick(a,0,r-1,r-1);

printf("\n\n\nSORTED LIST : ");
display(a,r);

    return 0;
}
