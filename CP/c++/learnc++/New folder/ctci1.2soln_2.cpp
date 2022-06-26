#include<iostream>
using namespace std;
int main()
{
    string str;
    cin>>str;
    bool check=true;
    int checker=0;
    int val;
    for(unsigned int i=0;i<str.length();i++)
    {
        val=str[i]-'a';
        if(((checker)&(1<<val))>0)
            {check=false;
            break;}
        checker|=(1<<val);

    }
    if(check)
        cout<<"unique";
    else
        cout<<"not unique";
}
