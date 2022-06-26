#include<bits/stdc++.h>
#define endl "\n"
#define M 998244353
using namespace std;
long long int dp[100005];
long long int newdp[100005];
long long int fact[100005];
long long int powermod(long long int x,long long int y)
{
   __int128_t res =1;
   __int128_t temp=x;
    temp= temp%M;
    while (y > 0)
    {   if (y & 1)
            res = (res*temp)%M;
        y = y>>1;
        temp=(temp*temp)%M;
    }
    return res;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long int ans,sum;
	int t,n,k;
	cin>>t;
	fact[0]=1;
	fact[1]=1;
	for(long long int i=2;i<100005;i++)
	{
		fact[i]=((i%M)*(fact[i-1]%M))%M;
	}
	while(t--)
	{
		cin>>n>>k;
		if(n==1)
		{
			cout<<0<<endl;
			continue;
		}
		if(k==1)
		{
			long long int last=powermod(n,n-2);
			long long int res=last;
			long long int ninv=powermod(n,M-2);
			for(int i=3;i<=n;i++)
			{
				last=(last*ninv)%M;
				last=(last*(n-i+1))%M;
				last=(last*(n-i+3))%M;
				last=(last*powermod(i-2,M-2))%M;
				res=(res+last)%M;
			}
			res=(res*powermod(powermod(n,n-2),M-2))%M;
			cout<<res<<endl;
			continue;
		}
		for(int i=0;i<=n-2;i++)
			{
				dp[i]=powermod(i+1,k);
			}	
		for(int i=2;i<=n;i++)
		{
			for(int s=0;s<=n-2;s++)
			{
				if(s==0){
					newdp[s]=1;
					continue;
				}
				newdp[s]=0;
				for(int j=0;j<=s;j++)
				{
					newdp[s]=(newdp[s]%M+(((((((fact[s]*powermod(fact[j],M-2))%M)*powermod(fact[s-j],M-2))%M)*powermod(j+1,k))%M)*(dp[s-j]))%M)%M;
				}
			}
			for(int s=0;s<=n-2;s++)dp[s]=newdp[s];
		}
		cout<<((newdp[n-2])*(powermod(powermod(n,n-2),M-2)))%M<<endl;	
	}


}