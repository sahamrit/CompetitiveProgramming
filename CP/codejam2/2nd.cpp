#include<bits/stdc++.h>
using namespace std;
int c[100005],d[100005];
int maxc[100005],maxd[100005];
int main()
{
	int t,n,k;
	long long int ans;
	cin>>t;
	int n1=t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>c[i];
		}
		for(int i=1;i<=n;i++)
		{
			cin>>d[i];
		}
		ans=0;
		for(int p=0;p<n;p++)
		{
			for(int i=1;i+p<=n;i++)
			{
				if(p==0)
				{
					maxc[i]=c[i];
					maxd[i]=d[i];
					if(abs(maxc[i]-maxd[i])<=k)
					{
						ans++;
					}
				}
				else
				{
					maxc[i]=max(maxc[i],c[i+p]);
					maxd[i]=max(maxd[i],d[i+p]);
					if(abs(maxc[i]-maxd[i])<=k)
					{
						ans++;
					}					
				}
			}
		}
		cout<<"Case #"<<n1-t<<": "<<ans<<endl;
	}
}