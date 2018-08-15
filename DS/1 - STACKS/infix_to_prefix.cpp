#include"infix_to_postfix.cpp"

string reverser(string bh)
{
    char temp;

    for(int i=0;i<bh.length()/2;i++)
    {
        temp=bh[i];
        bh[i]=bh[bh.length()-i-1];
        bh[bh.length()-i-1]=temp;
    }
    return bh;
}

string changer(string bh)
{
    for(int i=0;i<bh.length();i++)
    {
        if(bh[i]=='(')
            bh[i]=')';
        else if(bh[i]==')')
            bh[i]='(';
    }
    return bh;
}

string expressionconverter(string bh)
{

    bh=changer(bh);
    bh=reverser(bh);
    bh=converter(bh);
    bh=reverser(bh);
    return bh;
}

int main()
{
    system("cls");
    system("color f0");
    string a,b;
    cout<<"ENETR AN EXPRESSION IN INFIX FORMAT for CONVERSION INTO PREFIX FORMAT \n\n";
    cin>>a;

    b=expressionconverter(a);
    cout<<b;

    return 0;
}
