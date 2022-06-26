#include<iostream>

using namespace std;
bool pali_perm(string str)
{
     for(int i=0;i<str.length();i++)
    {
        str[i]=tolower(str[i]);

    }

    int *carr=new int[256];
    int oddct=0;
    for(int i=0;i<256;i++)
        carr[i]=0;
    for(int i=0;i<str.length();i++)
    {
        carr[(int)str[i]]++;
    }


    for(int i=0;i<256;i++)
    {
        if(carr[i]%2!=0)
            oddct++;
        if(carr[i]%2!=0&&oddct>1)
            return false;
    }
    return true;
}


int main()
{string str;
getline(cin,str);
    if(pali_perm(str))
        cout<<"perm of palindrome";
    else
        cout<<"not perm of palindrome";

}
