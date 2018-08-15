#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct set
	{
		int a;
		struct set * node;
	}
	*c[2],*temp,*u;


	void display(int r,int s)
	{ struct set * p=c[r];
	  struct set *w=c[s];

	       while(p!=NULL)
	       {
		   for(w=c[s];w != NULL; w=w->node)
		   {
			    if(w->a==p->a)
			    goto ab;
		   }

			printf("%d, ",p->a);
		      ab:	p=p->node;
	       }
	}


	void skew(int i,int j)
	{  	struct set *p=c[i];
		struct set *q=c[j];
		while(p!=NULL)
			{
			while(q!=NULL)
			{
				if(p->a==q->a)
				goto ab;
				q=q->node;
			}
		printf("%d ,",p->a);
		ab:
		p=p->node;
	}
	}



	void intersection()
		{	struct set *p=c[0];
			struct set *q=c[1];
			while(p!=NULL)
			{
				while(q!=NULL)
				{
					if(p->a==q->a)
					printf("%d",p->a);
					q=q->node;
				}
				p=p->node;
			}
		}



	int create(int r)
	{ 	int k;
		struct set *y;
		temp = (struct set*)malloc(sizeof(struct set));
		printf("enter the data - ");
		scanf("%d",&k);
		 y=c[r];
		 while(y!=NULL)
		 {
			if(y->a==k)
			{return 0;}
			 y=y->node;
		 }
		 temp->a=k;
		temp->node=NULL;

		if(c[r]==NULL)
		c[r]=temp;
		 else
		{
			 u=c[r];
			 c[r]=temp;
			 temp->node=u;
		  }
	  return 0;
	  }




int main()
	{
	int a;
	ab:
	    system("color f0");
	printf("..::MENU::..\n\n1.NEW ENTRY IN SET 1 \n2.NEW ENTRY IN SET2");
	printf("\n\n\n\n3.UNION\n4.INTERSECTION\n5.DIFFERENCE\n6.Skew-Difference\n\t\t");

	scanf("%d",&a);
	printf("{ ");
	switch(a)
	{
		case 1:
		create(0);
		printf(" }");
		goto ab;

		case 2:
		create(1);
		printf(" }");
		goto ab;

		case 3:
		display(0,1);
		display(1,0);
		intersection();
		printf(" }");
		getch();
		goto ab;

		case 4:
		intersection();
		printf(" }");getch();
		goto ab;


		case 5:
		skew(0,1);
		printf(" }");getch();
		goto ab;

		case 6:
		skew(0,1);
		skew(1,0);
		printf(" }");getch();
		goto ab;

		default:
		printf(" PROGRAM TERMINATED }");
}
getch();
return 9;
}
