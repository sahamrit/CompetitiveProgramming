#include<iostream>
using namespace std;
bool pali_perm(string str)
{
    long long int a=0;

    for(int i=0;i<str.length();i++)
    {
        a^=(1<<((int )str[i]));
    }

    //the below would also work fine
    /*while(a)
    {
        ctr+=(a&1);
        a>>=1;
        if(ctr>1)
            return false;
    }
    return true;
    */
    if(((a)&(a-1))==0)
        return true;
    return false;
}
int main()
{
    string str;
    getline(cin,str);
    if(pali_perm(str))
        cout<<"perm of pali";
    else
        cout<<"not pali perm";
}
