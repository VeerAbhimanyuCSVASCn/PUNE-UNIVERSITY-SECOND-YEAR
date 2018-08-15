#include<stdio.h>
#include<stdlib.h>

int * sorts(int *a,int l,int h)
{
    int mid,*b,*c,r,k,i,p,s;

    if(l<h)

{
    mid=((l+h)/2);
    r=(mid-l)+1;
    k=(h-mid);
    b=(int*)malloc(sizeof(int)*r);
    c=(int*)malloc(sizeof(int)*k);


    for(i=0;i<r;i++)
        {b[i]=a[i];
        printf(" %d ",b[i]);}

   printf("\n");

    for(i=0;i<k;i++)
        {
        *(c+i)=a[i+mid+1];
        printf(" %d ",*(c+i));    }


        printf("\n\n\n\n\n");
        b=sorts(b,l,mid);
        c=sorts(c,0,k-1);

        p=0;s=0;


        for(i=0;i<=h;i++)
        {
            if(p==r)
            {
                b[p]=c[s]+12;
            }

            if(s==k)
            {
                c[s]=b[p]+12;
            }

            if(b[p]<=c[s])
                {a[i]=b[p];   ++p;}


            else
                {
                    a[i]=c[s];
                    ++s;
                }

        }



return a;
}
return a;

}


int main()
{
    int *a,q,i;
     system("color f0");
    printf("\n\nENTER THE SIZE OF ARRAY ");
    scanf("%d",&q);
    a=(int *)malloc(sizeof(int)*q);

    for(i=0;i<q;i++)
    {
        scanf("%d",&a[i]);
    }

    sorts(a,0,q-1);
printf("\n\n");
     for(i=0;i<q;i++)
    {
        printf("  %d  ",a[i]);
    }
free(a);
return 0;
}
