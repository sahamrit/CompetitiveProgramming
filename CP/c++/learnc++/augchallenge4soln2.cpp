#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int a,long long int b)
{
    if(b==0)
        return a;
    else if(a<b)
        return gcd(b,a);
            else
                return gcd(b,a%b);
}

long long int powermod(long long int x,long long int y,long long  int z)
{
   __int128_t res =1;
   __int128_t temp=x;
    temp= temp%z;
    while (y > 0)
    {   if (y & 1)
            res = (res*temp)%z;
        y = y>>1;
        x=(x*x)%z;
    }
    return res;
}


struct node
{
    long long int a;
    long long int b;
    long long int n;
};
int main()
{

    short int n;
    cin>>n;
     vector<node>v(n);
    long long int temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v[i].a=temp;

        cin>>temp;
        v[i].b=temp;

        cin>>temp;
        v[i].n=temp;


    }
    for(int i=0;i<n;i++)
    {
        if(v[i].a==v[i].b)
            cout<<(powermod(v[i].a,v[i].n,1000000007 )+powermod(v[i].b,v[i].n,1000000007))%1000000007<<endl;
            else
        cout<<gcd((powermod(v[i].a,v[i].n,v[i].a-v[i].b)+powermod(v[i].b,v[i].n,v[i].a-v[i].b))%(v[i].a-v[i].b),v[i].a-v[i].b)%1000000007 <<endl;
    }

}
