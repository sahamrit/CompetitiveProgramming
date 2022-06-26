#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[100000],b[100000];
long long c[100000];

bool possible (long long x)
{
	long long  temp=m;

	for(int i=0;i<n;i++)
	{
		long long temp1=c[i];
		if(temp1<=x)
			continue;
		if((temp1-x)%b[i]==0)
		{
			temp-=(temp1-x)/b[i];
		}
		else
		{
			temp-=(temp1-x)/b[i]+1;
		}

		if(temp<0)
			break;

	}
	return temp>=0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long maximum=0; 
cin>>n>>m;
for(int i=0;i<n;i++)
{
	cin>>a[i];
	c[i]=a[i];
}
for(int i=0;i<n;i++)
{
	cin>>b[i];
	c[i]*=b[i];
	maximum=max(c[i],maximum);
	
}
long long p=-1;
for(long long b=(maximum+1);b>=1;b/=2)
{
	while(!possible(b+p))
		p+=b;
}


cout<<p+1<<endl;
}