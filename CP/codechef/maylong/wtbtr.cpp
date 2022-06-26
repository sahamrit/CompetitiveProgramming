#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
long double a1[10005],a2[10005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,n;
	cin>>t;
	long double x,y;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>x>>y;
			a1[i]=(y-x);
			a2[i]=(y+x);
		}
		sort(a1,a1+n);
		sort(a2,a2+n);
		long double a1min,a2min;
		a1min=a1[1]-a1[0];a2min=a2[1]-a2[0];
		for(int i=2;i<n;i++)
		{
			a1min=min(a1min,a1[i]-a1[i-1]);
			a2min=min(a2min,a2[i]-a2[i-1]);
		}
		a1min=a1min*((long double)0.5);
		a2min=a2min*((long double)0.5);
		cout<<setprecision(15)<<min(a1min,a2min)<<endl;
	}
}
