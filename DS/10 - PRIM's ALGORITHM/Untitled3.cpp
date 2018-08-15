#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;

static int u=0;
struct nod
{
    int num;
    int distance;
    int parent;
    int status;
    nod()
    {
        num = u++;
        distance =99999;
        parent = '.';
        status =1;
    }
};




int check(vector<nod>abhimanyu)
{
    int j=0;
    int distance = 10000000;
    for(int i=0;i<abhimanyu.size();i++)
    {
        if(abhimanyu[i].distance< distance && abhimanyu[i].status==1)
        {
            distance = abhimanyu[i].distance;
            j=i;
        }
    }

    return j;
}




nod *node;
int **b;
int main()
{
    system("color f0");
    int a;
    cout<<"ENTER NO OF OFFICES IN A GRRAPH - ";
    cin>>a;
    b=new int*[a];
    for(int i=0;i<a;i++)
        b[i] = new int [a];

    cout<<"ENTER THE DATA MATRIX about the distance of offices - ";
    for(int i=0;i<a;i++)
        for(int j=0;j<a;j++)
            cin>>b[i][j];

    node = new nod[a];
    node[0].distance=0;
    vector <nod> abhimanyu;

    for(int i=0;i<a;i++)
        abhimanyu.push_back(node[i]);

int v=a;
        while(v)
        {
            int r=check(abhimanyu);

                abhimanyu[r].status=0;
                int num = abhimanyu[r].num;


        for(int i=0;i<a;i++)
        {
            if(abhimanyu[i].status==1 && b[num][i]!=0)
            {
                if(abhimanyu[i].distance > b[num][i])
                        abhimanyu[i].distance = b[num][i];
            }
        }
        --v;
        }


        int sum=0;
        for(int i=0;i<a;i++)
        {
            sum =abhimanyu[i].distance+sum;
        }

        cout<<"MINIMUM COST - "<<sum;

}
