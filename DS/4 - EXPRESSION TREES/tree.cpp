#include"E:\assignments\secon year sem 2\DS\1 - STACKS\infix_to_postfix.cpp"

class tree_substance
{
    public:
    char data;
    tree_substance * left;
    tree_substance * right;
    tree_substance(char t)
    {
        left=right=0;
        data = t;
    }
};



int traversepre (tree_substance *c)
{
    if(c==NULL)
        return 0;
    cout<<c->data;
    traversepre(c->left);
    traversepre(c->right);
    return 1;
}



int traversepost (tree_substance *c)
{
    if(c==NULL)
        return 0;
    traversepost(c->left);
    traversepost(c->right);
    cout<<c->data;
    return 1;
}


int traversein (tree_substance *c)
{
    if(c==NULL)
        return 0;
    traversein(c->right);
    cout<<c->data;
    traversein(c->left);
    return 1;
}



void treegenerator(string b)
{

    stackcode <tree_substance * > a;

    tree_substance *c = 0;

    for(int i=0;i<b.length();i++)
    {
        c=new tree_substance(b[i]);

        if(c->data==' ')
            continue;

        if(b[i]>='a' && b[i]<='z')
            {a.push(c);}

        else
            {
                tree_substance *d = a.pop();
                tree_substance *e = a.pop();
                c->left = d;
                c->right =e;
                a.push(c);
            }
    }


c=a.pop();



    cout<<"\n\n\n\t\tTREE CREATED ...\n\n\t...EnTeR ThE OrDeR oF TrAvErSaL...\n\n1.PRE-ORDER\n2.POST-ORDER\n3.IN-ORDER\n\n\n";

    char t;
    t=getch();
     cout<<"\t\t\t..YoUr REsULt iS :- \n\t\t\t\t\t";
    switch(t)
    {
    case'1':
        traversepre(c);
        break;
    case'2':
        traversepost(c);
        break;
    case'3':
        traversein(c);
        break;

    }


}


