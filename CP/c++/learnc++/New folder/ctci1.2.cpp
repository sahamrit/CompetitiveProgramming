#include<iostream>
using namespace std;
int main()
{string str1,str2;
cin>>str1;
cin>>str2;

bool check=true;
int *temp=new int[256];
if(str1.length()==str2.length())
{


    for(int i=0;i<256;i++)
        {
            temp[i]=0;
        }
    for(int i=0;i<str1.length();i++)
        {
            temp[(int)str1[i]]++;

        }
    for(int i=0;i<str2.length();i++)
        {
            temp[(int)str2[i]]--;
            if(temp[(int)str2[i]]<0)
                {
                    check=false;

                }

        }
    if(check)
            cout<<"permutation";
    else
        cout<<"not permutation";


}
else
    cout<<"not permutation";
}
