#include<bits/stdc++.h>
#define endl "\n"
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const long long int INF=1e18L+5; 
long long int dp[100001];
long long int newdp[100001];

int main()
{
	fastio;
	int n,w;
	cin>>n>>w;
	vector<pair<int,int>>a(n+1);
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first>>a[i].second;
		sum+=a[i].second;
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			if(i==1)
			{
				if(j==0)
				{
					newdp[j]=0;
					continue;
				}
				if(a[i].second==j)newdp[j]=a[i].first;
				else
				{
					newdp[j]=INF;
				}
				continue;
			}
			if(a[i].second>j)newdp[j]=dp[j];
			else
			{
				newdp[j]=min(dp[j],dp[j-a[i].second]+a[i].first);
			}
		}
		for(int j=0;j<=sum;j++)dp[j]=newdp[j];
	}
	long long int ans=0;
	for(long long int j=0;j<=sum;j++)
	{
		if(newdp[j]<=w)ans=max(ans,j);
	}
	cout<<ans<<endl;
}