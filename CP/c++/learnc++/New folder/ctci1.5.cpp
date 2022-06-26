#include<iostream>
#include<cmath>
using namespace std;
bool oneaway(string & str1,string &str2)
{
   long long int ctr1=0,ctr2=0;
   int length1=str1.length(),length2=str2.length();

    if(abs(length1-length2)>1)
        return false;

    if(length2<=length1)
    {
        for(int i=0;i<length2;i++)
        {
            ctr2^=(1<<((int)str2[i]));
        }
        for(int i=0;i<length1;i++)
        {
            ctr1^=(1<<((int)str1[i]));
        }
    }

  if(ctr2<ctr1)
    {ctr2^=ctr1;
    ctr2&=ctr1;
    if((ctr2&(ctr2-1))!=0)
        return false;
    return true;}
  else{ctr1^=ctr2;
       ctr1&=ctr2;
        if((ctr1&(ctr1-1))!=0)
        return false;
        return true;
      }

}
int main()
{
    string str1,str2;
    cin>>str1;
    cin>>str2;

    if(oneaway(str1,str2))
        cout<<"one away";
    else
        cout<<"not one away";

}
