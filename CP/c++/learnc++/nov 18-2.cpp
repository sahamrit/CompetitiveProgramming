#include<bits/stdc++.h>
using namespace std;
int a[100001];
pair<int,int>b[100001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n,ctrmax=0;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ctrmax=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
			b[j].first=0;
			b[j].second=0;

		}
		for(int j=1;j<=n;j++)
		{
			if(b[a[a[j]]].first==0)
			{

			b[a[a[j]]].first++;
			b[a[a[j]]].second=a[j];
			if(ctrmax<b[a[a[j]]].first)
				ctrmax=b[a[a[j]]].first;

			}
			else 
			{
				if(b[a[a[j]]].second!=a[j])
				{
					b[a[a[j]]].first++;
					if(ctrmax<b[a[a[j]]].first)
				ctrmax=b[a[a[j]]].first;

			      if(ctrmax>1)
			      	break;

				}
			}

		}
		if(ctrmax>1)
			cout<<"Truly Happy"<<endl;
		else
			cout<<"Poor Chef"<<endl;

	}

}