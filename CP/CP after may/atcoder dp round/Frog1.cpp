#include<bits/stdc++.h>
#define endl "\n"
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int INF=1e9+5; 
int main()
{
	fastio;
	int n,k;
	cin>>n>>k;
	vector<int> h(n+1);
	for(int i=0;i<n;i++)
		cin>>h[i+1];
	vector<int>dp(n+1,INF);

	dp[1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=i+k && j<=n;j++)
		{
			dp[j]=min(dp[j],dp[i]+abs(h[i]-h[j]));
		}
	}
	cout<<dp[n]<<endl;
}