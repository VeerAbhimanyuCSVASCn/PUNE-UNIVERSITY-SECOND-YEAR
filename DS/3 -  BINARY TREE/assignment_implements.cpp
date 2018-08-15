#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
/**BINARY TREE (FAMILY TREE) **/
using namespace std;

class family
{
    string name;

public:
    family *left;
    family *right;

    string names()
    {
        return name;
    }
    family(string names)
    {
        name = names;
        left=NULL;
        right=NULL;
    }

};


family * forefathers(family * root)
{
        cout<<"\n\nenter the name of the new member - ";
        string h;
        cin>>h;
        family * newmember = new family(h);


    if(root==NULL)
    {
        root = newmember;
        return root;
    }

    family * temp =root;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    temp->right = newmember;
    return root;

}








family * decendent(family * root,string h,string k)
{
    if(root==NULL)
        return root;

    if(root->names()==k)
    {

        family * mem = new family(h);
        mem->right = root->left;
        root->left=mem;
        return root;
    }

    decendent(root->left,h,k);
    decendent(root->right,h,k);

return root;
}








family* newfamilymember(family * root)
{
    string h;
    cout<<"\n\n1.FAMILY MEMBER AT THE TOP MOST OF THE TREE\n\n2.FAMILY MAMBER FROM BELOW THE TOP MOST\n\t\t\t";
    switch(getch())
    {
    case'1':
        root=forefathers(root);
        break;
    case'2':
        cout<<"ENTER THE NAME OF NEW FAMILY MEMBER - ";
        cin>>h;
        cout<<"\nENTER THE NAME OF FATHERR - ";
        string k;
        cin>>k;
        root=decendent(root,h,k);
        break;
    }

    return root;
}





int display(family *root,int p)
{
    if(root==NULL)
        return 0;

    for(int i=0;i<p*2;i++)
        cout<<" ";
        cout<<'`';
    for(int i=0;i<p;i++)
        cout<<"-";
        cout<<'>';
    cout<<root->names()<<endl;;
    display(root->left,p+1);
    display(root->right,p);
    return 0;

}




int s=0;
int generation(family *root,int p)
{
    if(root==NULL)
        return 0;

        if(p>s)
            s=p;

  generation(root->left,p+1);
  generation(root->right,p+1);
return s;
}




int generated(family *root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->names()<<endl;
    }
    generated(root->left);
    generated(root->right);
    return 0;

}



family * copyed(family * root, family * rec)
{
    if(root==NULL)
        return 0;

    family *t = new family(root->names());

    if(rec==NULL)
    {
        rec=t;
        return rec;
    }




    return rec;

}

int main()
{
    family * root =NULL;
    ab:
    system("color f0");
    cout<<"\n\n\n\t\t\t<< MeNu >>\n\n1.NEW FAMILY MEMBER\n2.DISPLAY FAMILY TREE\n3.NO OF GENERATION PASSED\n4.LIST OF PERSONS PRESENT AT THE LEAF OF FAMILY TREE\n\t5.COPY\n\t\t\t";

    switch(getch())
    {
    case'1':
        root=newfamilymember(root);
        goto ab;
    case'2':
        cout<<endl;
        display(root,0);
        goto ab;
    case'3':
        cout<<generation(root,0);
        goto ab;
    case'4':

            generated(root);
        goto ab;
    case'5':
            family * rec = NULL;
            rec = copyed(root,rec);
            display(rec,0);
        goto ab;

    }
    return 0;
}
