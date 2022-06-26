#include<bits/stdc++.h>
#define endl "\n"
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
//const int INF=1e9+5; 
int main()
{
	fastio;
	int n;
	cin>>n;
	vector<int>dp(3,0);
	vector<int>newdp(3,0);
	vector<int>c(3);
	for(int day=0;day<n;day++)
	{
		cin>>c[0]>>c[1]>>c[2];
		fill(newdp.begin(),newdp.end(),0);
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(i!=j)
				{
					newdp[j]=max(newdp[j],dp[i]+c[j]);
				}
			}
		}
		dp=newdp;
	}	
	cout<<max({dp[0],dp[1],dp[2]});
}