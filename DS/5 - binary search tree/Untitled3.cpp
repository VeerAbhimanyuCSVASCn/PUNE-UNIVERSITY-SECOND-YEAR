/**BINARY SEARCH TREES **/

#include"E:\assignments\secon year sem 2\DS\1 - STACKS\stack.cpp"
using namespace std;
class tree_substance
{
    public:
    int data;
    tree_substance *left,*right;

     tree_substance(int datas)
     {
         data = datas;
         left=0,right=0;
     }
} ;

tree_substance* creator(tree_substance *roots,int r)
{
        if(roots==NULL)
        {
            roots = new tree_substance(r);
            return roots;
        }

        if(roots->data > r)
                {roots->left=creator(roots->left,r);
                    return roots;
                }
        if(roots->data < r)
                {roots->right=creator(roots->right,r);
                return roots;}
                return roots;

}

tree_substance* inserter (tree_substance * root)
{
    cout<<"\n\n\t\t\t...ENTER THE DATA FOR TREE MAKING...";
    int r;
    cin>>r;
     if(root==NULL)
    {
            tree_substance * newdata = new tree_substance(r);
            return newdata;
    }

   root= creator(root,r);
   return root;
}


int display (tree_substance * roots)
{
    if(roots==NULL)
            return 0;
    cout<<roots->data<<"  ";
    display(roots->left);
    display(roots->right);


    return 0;
}

int search (tree_substance * roots,int k)
{
    if(roots==NULL )
            {cout<<"\n\n\n   SooooooooooRRY !!! THERE IS NO SUCH DATA PRESENT IN BINARY TREE...!!!";
            return 0;}

    if(roots->data==k)
    {
        cout<<"  ----> "<<"FiNaLlY FoUnD -->  "<<k;
        return 0;
    }

    if(k>roots->data)
    {   cout<<roots->data<<"   ";
        search(roots->right,k);
        return 0;}



          else if(k>roots->data)
    {   cout<<roots->data<<"    ";
        search(roots->left,k);
        return 0;}
cout<<"\n\n\n \t\t\t  SooooooooooRRY !!! THERE IS NO SUCH DATA PRESENT IN BINARY TREE...!!!";
    return 0;
}

    tree_substance* mirror(tree_substance*root)
    {
        if(root==NULL)
            return 0;
        tree_substance *l,*r;
        l=root->left;
        r=root->right;
        root->left = r;
        root->right =l;

        mirror(root->left);
        mirror(root->right);
        return root;
    }



int displaylevel(int level,stackcode <tree_substance *> stack1)
{
    if(!stack1.isnull())
        {return 0;}
    cout<<"\n\nlevel  "<<level<<"   -   ";
    stackcode <tree_substance *> stack2;
    tree_substance *a=NULL;

    while(stack1.isnull())
    {
        a=stack1.pop();
        cout<<a->data<<"   ";
        if(a->left!=NULL)    stack2.push(a->left);
        if(a->right!=NULL)    stack2.push(a->right);
    }
    displaylevel(level+1,stack2);
    return 0;
}
















int main()
{    stackcode <tree_substance *> stack1;
    tree_substance*root =0;
       ab:
   // system("cls");
    system("color f0");

    cout<<"\n\n\n\t\t\t...Enter YoUr ChOiCe FoR BiNaRy SeArCh TrEe...\n\t1.InSeRt\n\t2.SeArCh\n\t3.DiSpLaY\n\t4.DiSpLaY LeVeL WiSe\n\t5.mirror\n\t";
    switch(getch())
    {
    case'1':
       root= inserter(root);
        goto ab;
    case'2':
        cout<<"ENTER THE ELEMENT TO BE SEARCHED - ";
        int k;
        cin>>k;
        cout<<"       ";
        search(root,k);
        goto ab;
    case'3':
        display(root);
    getch();    goto ab;

    case'4':
        stack1.push(root);
        displaylevel(1,stack1);

        goto ab;

    case'5':
       root= mirror(root);
        goto ab;

    }
    return 0;
}
