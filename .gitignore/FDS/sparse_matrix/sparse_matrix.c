#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


int** sparse(int b,int c,int *ja)
{
    int **a,i=0,j=0,s=0,**r,sa=0;
    *ja=0;
    a=(int**)malloc(b*sizeof(int*));
    for(i=0;i<b;i++)
       {
                for(j=0;j<b;j++)
                {
                    a[i]=(int*)malloc(c*sizeof(int));
                }
       }


       printf("\n\n\nENTER THE MATRIX - ");


       for(i=0;i<b;i++)
       {
                for(j=0;j<c;j++)
                {
                    scanf("%d",&a[i][j]);
                    if(a[i][j]!=0)
                            ++*ja;
                }
        }


    r=(int**)malloc(sizeof(int*)*3);
    r[0]=(int*)malloc(sizeof(int)**ja);
    r[1]=(int*)malloc(sizeof(int)**ja);
    r[2]=(int*)malloc(sizeof(int)**ja);


        for(i=0;i<b;i++)
        {
            for(j=0;j<c;j++)
                {
                    if(a[i][j]!=0)
                        {   r[0][sa]=i;
                            r[1][sa]=j;
                            r[2][sa]=a[i][j];
                            ++sa;
                        }
                }

       }
return r;
}



int ** transpose(int **l, int *ja, int c)
{   int i,*q,j,temp;
    if(c==1)
    {goto ab;}
    q=l[0];
    l[0]=l[1];
    l[1]=q;

        ab:
    for(j=0;j<*ja-1;j++)

        for(i=0;i<*ja-1;i++)
        {
            if((l[0][i]*10 + l[1][i]) > (l[0][i+1]*10 + l[1][i+1]) )
            {
                temp=l[0][i];
                l[0][i]=l[0][i+1];
                l[0][i+1]=temp;


                temp=l[1][i];
                l[1][i]=l[1][i+1];
                l[1][i+1]=temp;

                temp=l[2][i];
                l[2][i]=l[2][i+1];
                l[2][i+1]=temp;
            }
        }
    return l;
}









int** mul(int **l,int**m,int*ja,int*na,int b,int c,int d,int e)
{
    int **q,*p,*r,
    i,j,k=0,z=0,x=0,temp=0,s=0,a=0;

    q=(int**)malloc((sizeof(int*)*3));

    p=m[1];
    m[1]=m[0];
    m[0]=p;

    for( i=0;i<3;i++)
    {
        q[i]=(int*)malloc(sizeof(int)*0);      /*0 byte array created */
    }





    for(i=0;i<b;i++)
    {

            p=(int*)calloc(c,sizeof(int));
            r=(int*)calloc(c,sizeof(int));

        while(l[0][z]==i)
        {
            p[l[1][z]]=l[2][z];
            ++z;
        }

        x=0;
        printf("\n");

        for(j=0;j<e;j++)
        {
            while(m[1][x]==j)
            {
                r[m[0][x]]=m[2][x];
                ++x;
            }

            temp=0;
           for(k=0;k<c;k++)
           {
               temp=temp+(p[k]*r[k]);

           }

            /*printf("%d\n\n",temp);*/

           if(temp!=0)
           {  a=a+1;
               for(s=0;s<3;s++)
               {
                 *(q+s)=(int*)realloc(*(q+s),sizeof(int)*(a));

               }
               q[0][a-1]=j;
               q[1][a-1]=i;
               q[2][a-1]=temp;
           }

        }
free(p);
free(r);
    }
    transpose(q, &a, 1);

    for(i=0;i<a;i++)
    {
        printf("%d %d %d \n",q[0][i],q[1][i],q[2][i]);
    }

    return q;
}










int ** add(int **l, int** m, int *ja,int *ka)
{
    int i=0,j=0,c=0,temp;

    for(i=0;i<*ja;)
    {  printf("%d %d %d \n\n",l[0][i],l[1][i],l[2][i]);
        for(j=0;j<=*ka;j++)
        {
            if((l[0][i]*10 +l[1][i])==(m[0][j]*10 +m[1][j]))
            {
                m[2][i]=l[2][i]+m[2][j];
                goto ab;
            }
        }
            ++ *ka;
        for(c=0;c<3;c++)
       { m[c]=(int *)realloc(m[c],sizeof(int)*( *ka));}

            m[0][(*ka)-1]=l[0][i];
            m[1][(*ka)-1]=l[1][i];
            m[2][(*ka)-1]=l[2][i];


        ab:
            ++i;
    }



for(j=0;j<*ka-1;j++)

    for(i=0;i<*ka-1;i++)
    {
        if((m[0][i]*10 + m[1][i]) > (m[0][i+1]*10 + m[1][i+1]) )
        {
            temp=m[0][i];
            m[0][i]=m[0][i+1];
            m[0][i+1]=temp;


            temp=m[1][i];
            m[1][i]=m[1][i+1];
            m[1][i+1]=temp;

            temp=m[2][i];
            m[2][i]=m[2][i+1];
            m[2][i+1]=temp;
        }
    }




    for(i=0;i<*ka;i++)
        printf("%d %d  %d\n",m[0][i],m[1][i],m[2][i]);

        return m;

}







int main()
{
    int b,c,**l,i,j,*ja=(int*)malloc(sizeof(int)),**m,*na,d,e,**p;
    char q;
    ab:
        system("color f0");
    printf("\n\n\n\t\t\t..:: MENU ::..\n\n1.TRANSPOSE A MATRIX\n2.ADD\n3.MULTIPLY\n4.fasttranspose\n");
    q=getch();
    printf("ENTER THE SIZE OF MATRIX - ");
    scanf("%d%d",&b,&c);
    l=sparse(b,c,ja);

        if(q!='1')
        {
            na=(int*)malloc(sizeof(int));
            printf("ENTER THE SIZE OF MATRIX - ");
            scanf("%d%d",&d,&e);
            m=sparse(d,e,na);

        }


        switch(q)
        {


        case'1':
                printf("BEFORE TRANSPOSE :- ");
                for(i=0;i<*ja;i++)
                    {
                        printf("\n%d %d  %d ",l[0][i],l[1][i],l[2][i]);
                    }


                printf("\n\nAFTER TRANSPOSE :- ");
                transpose(l,ja,0);
                for(i=0;i<*ja;i++)
                    {
                        printf("\n%d %d  %d ",l[0][i],l[1][i],l[2][i]);
                    }

                goto ab;



                case'2':

                    if(b!=d || c!=e)
                        {printf("\n\n\n\t\t\t..:: NOT POSSIBLE ::..\n\n");
                        goto ab;}

                    else
                    {

                        p=add(l,m,ja,na);
                        goto ab;
                    }

                case'3':
                    if(c!=d)
                    {printf(" NO MULTIPLICATION POSSIBLE ");goto ab;}

                    mul(l,m,ja,na,b,c,d,e);
                    goto ab;

        }
getch();


return 0;
}

