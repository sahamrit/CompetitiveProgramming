#include<bits/stdc++.h>
#define M 998244353
using namespace std;
long long ncr[1002][1002];
int a[1001],dp[1002],n;
void precompute_ncr()
{
	for(int k=0;k<=1001;k++)
	{
		for(int i=1;i<=1001;i++)
		{
			if(k==0||k==i)
				ncr[i][k]=1;
			else if(i<k)
				ncr[i][k]=0;
			else
				ncr[i][k]=(ncr[i-1][k]%M+ncr[i-1][k-1]%M)%M;
		}
	}
}
int main()
{	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	precompute_ncr();
	dp[n+1]=1;
	for(int i=n;i>=1;i--)
	{
		if(a[i]<=0)
			dp[i]=0;
		else
		{
			for(int j=i+1+a[i];j<=n+1;j++)
			{
				dp[i]=(dp[i]%M+((ncr[j-i-1][a[i]]%M)*(dp[j]%M))%M)%M;
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=(ans%M+dp[i]%M)%M;
	}
	cout<<ans<<endl;

}