#include<bits/stdc++.h>
using namespace std;
long long int arr[100001];
vector< long long int>v;
bool dp[51][51];
long long int prefix[51];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long int n,q,t,k,sum;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>q;
	while(q--)
	{
		v.clear();
		cin>>k;
		for(int i=0;i<n;i++)
		{
			cin>>t;
			if(t)
			{
				v.push_back(t*arr[i]);
			}
		}
		if(k>v.size())cout<<0<<endl;
		else
		{

			prefix[0]=0;
			for(int i=1;i<=v.size();i++)
			{
				prefix[i]=prefix[i-1]+v[i-1];
			}
			
			long long int bestbitmask=0,currbitmask=0;
			for(int setbit=60;setbit>=0;setbit--)
			{
				memset(dp,false,sizeof(dp));
				currbitmask=bestbitmask|(((long long int)1)<<setbit);
				for(int i=1;i<=v.size();i++)
				{
					if((prefix[i]&currbitmask)==currbitmask)
						dp[i][1]=true;
				}

				for(int j=2;j<=k;j++)
				{
					for(int i=j;i<=v.size();i++)
					{
						for(int m=i-1;m>=j-1;m--)
						{
							sum=prefix[i]-prefix[m];
							if(dp[m][j-1]&& (sum&currbitmask)==currbitmask)
								dp[i][j]=true;
						}
					}
				}
				if(dp[v.size()][k])
				{
					bestbitmask=currbitmask;
				}
			}
			cout<<bestbitmask<<endl;
			
		}
	}
}