#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<list>
#define max 20
using namespace std;
/*int mat[max][max];
int visit[max];
int c =0;



int BFS(int i)
{
    cout<<endl;
    for(int u=0;u<max;u++)
        visit[u]=0;

    list <int> las;
    las.push_back(i);
    visit[i]=1;
    int r;
    while(!las.empty())
    {

        {r = las.front();
            las.pop_front();
        for(int l =0; l<c;l++)
            if(mat[r][l]!=0 && visit [l]==0)
            {las.push_back(l);
            visit[l]=1;
            cout<<l<<"  ";
            }
        }
    }
    return 0;
}






int DFS(int i)
{
    if(visit[i]==1)
        return 0;

    visit[i]=1;
    cout<<i<<"  ";
    for(int r =0;r<c;r++)
    {
        if(mat[i][r]!=0)
        {
            DFS(r);
        }
    }
    return 0;
}

int main()
{
    system("color f0");
    cout<<"ENTER THE SIZZE OF MATRIX : - ";
    cin>>c;

    cout<<"ENTER THE MATRIX _ ";
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<c;j++)
            cin>>mat[i][j];
    }

    int k;
    cout<<"ENTER THE STARTING POINT - ";
    cin>>k;
    DFS(k);
    cout<<endl<<endl;
    BFS(k);
    return 0;
}
*/



int c=0;
int mat[max][max];
int visited[max];
static int r;

class adjs
{
public:

    int data;
    adjs *next;

    adjs()
    {
        data =r++;
        next=0;
    }

    adjs(int po)
    {
        data =po;
        next =0;
    }
};

adjs * p=NULL;


   int creates(int i,int j)
    {
        adjs * r = new adjs(j);

        if(p[i].next==0)
        {
                p[i].next =r;
                return 0;
        }

        else
        {
             adjs *il=p[i].next;

                while(il->next!=NULL)
                   {
                    il=il->next;}
                    il->next =r;

        }
        return 0;
    }



    void display()
    {
        adjs *ps;
        for(int i=0;i<c;i++)
        {
            cout<<endl;
            cout<<p[i].data<<"  -   ";
            ps=p[i].next;
            while(ps!=NULL)
            {
                cout<<ps->data<<"     ";
                ps=ps->next;
            }
            cout<<endl;
        }
    }




    int DFS(int i)
    {
        if(visited[i]!=0)
            return 0;

        visited[i] =1;

        cout<<"   "<<i;

        adjs * tu=p[i].next;

        while(tu!=NULL)
            {
                            DFS(tu->data);

                    tu = tu->next;
            }
            return 0;
    }



    int BFS(int i)
    {
        list <int> y;
        cout<<i<<"  ";
        y.push_back(i);
        visited[i]=1;
        int r;
        while(!y.empty())
        {
            r=y.front();
            y.pop_front();
            adjs *ui = &p[r];

            while(ui!=NULL)
            {
                if(visited[ui->data]==0)
               {

                 y.push_back(ui->data);
                    cout<<ui->data<<"  ";
                visited[ui->data]=1;}

                ui=ui->next;
            }


        }
            return 0;
    }

int main()
{
    system("color f0");
    int t;
    cout<<"ENTER THE NO OF NODES TO CREATE : - ";
    cin>>c;
    p = new adjs[c];


    cout<<"\n\nENTER thE MATRIX :-  ";
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>t;
            if(t!=0)
            creates(i,j);
        }
    }
    display();
    cout<<endl<<endl<<endl;
   // DFS(0);
    BFS(0);
    return 0;
}




