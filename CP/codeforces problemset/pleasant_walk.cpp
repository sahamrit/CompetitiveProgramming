#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int max=1,temp=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i+1])
			temp++;
		else
		{
			if(max<temp)
				max=temp;
			temp=1;
		}
		if(max<temp)
			max=temp;
	}
	cout<<max<<endl;
}