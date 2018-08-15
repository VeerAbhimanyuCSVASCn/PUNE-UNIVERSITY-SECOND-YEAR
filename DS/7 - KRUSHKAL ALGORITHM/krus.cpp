#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<set>
#include<stack>
#include<algorithm>
using namespace std;
/**RAILWAY ENQUIRY SYSTEM **/
static int i=0;
class sets
{
    public:
    set <int>vertex;

    sets()
    {
        vertex.insert(i++);
    }

    void values()
    {       set<int> :: iterator p = vertex.begin();
            for(;p !=vertex.end();p++)
                cout<<*p<<"  ";
    }

    int top()
    {
        return *vertex.begin();
    }

    set<int> :: iterator  it()
    {
        set<int> :: iterator p = vertex.begin();
        return p;
    }

    void movers(sets vertexes)
    {
        while(!vertexes.vertex.empty())
        {
            vertex.insert(*vertexes.vertex.begin());
            vertexes.vertex.erase(*vertexes.vertex.begin());
        }
    }
};



class edges
{public:
    int v0;
    int v1;
    int weight;

    int weighter()
    {
        return weight;
    }


    edges()
    {

    }
    edges(int x,int y,int weights)
    {
        v0 = x;
        v1 = y;
        weight = weights;
    }

    void assignval(int weights, int y, int x)
    {
            v0 = x;
            v1 = y;
            weight = weights;


    }


    edges * edgesort(edges * ed,int n)
    {
        edges  temp;

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(ed[j].weight > ed[j+1].weight)
                {
                    temp = ed[j];
                    ed[j] = ed[j+1];
                    ed[j+1] =temp;
                }
            }
        }
        return ed;
    }
};







void krushkal_PATH_GENERATOR(edges * ed, sets *p,int k,int c)
{
    int *b = new int[c];
    for(int i=0;i<c;i++)
    {b[i]=i;}


    for(int i=0;i<k;i++)
    {
        if(b[ed[i].v0]==b[ed[i].v1])
        {
            ed[i].weight=-1;
        }



        else
        {

            p[ed[i].v0].movers(p[ed[i].v1]);
            p[ed[i].v1].vertex.clear();


            int k =max(b[ed[i].v1], b[ed[i].v0]);
            int l=min(b[ed[i].v1], b[ed[i].v0]);
            for(int r =0 ;r< c;r++)
            {
                if(b[r]==k)
                    b[r]=l;
            }

            /* for(int i=0;i<c;i++ )
                {cout<<i<<"."<<b[i]<<"  ";
                }
                cout<<endl;*/

        }

    }
}




int main()
{
    system("color f0");
    cout<<"ENTER THE NO OF STATIONS IN A COUNTRY TO BE MADE - ";
    int c;
    cin>>c;
    sets *p;
    p =  new sets[c];

    stack<int> re;

    cout<<"\n\n\nENTER THE RAILWAY ROUTE  BY DISTANCE - ";
    for(int y=0;y<c;y++)
    {
        for(int x=0;x<c;x++)
        {
            int t;
            cin>>t;

            if(y>x || t==0)
                continue;

                re.push(y);
                re.push(x);
                re.push(t);

        }
    }

    int k = re.size()/3;

    edges *ed = new edges[k];

    for(int i=0;i<k;i++)
    {
        int w = re.top();re.pop();
        int x = re.top();re.pop();
        int y = re.top();re.pop();
        ed[i].assignval(w,x,y);
    }

    ed=  ed->edgesort(ed,k);
    krushkal_PATH_GENERATOR(ed,p,k,c);

    cout<<"POSSIBLE MINIMUM COST IS - ";
    int cost =0;
    for(int i=0;i<k;i++)
       {
            if(ed[i].weight!=-1)
           cost+=ed[i].weight;

           //cout<<ed[i].weight<<"  ";
       }

        cout<<cost;

    return 0;
}
