#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long sum=0;
int a[100000];
int b[100000];
pair<long long,int >temp;
pair<long long ,int> c[100000];
int main()
{
	priority_queue <pair<long long ,int>> pq;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		c[i].first=a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		c[i].first*=(long long)b[i];
		c[i].second=-b[i];
		pq.push(c[i]);

	}
	if(sum<=m)
		cout<<0<<endl;
	else
	{
		for(long long i=0;i<min(sum,m);i++)
		{
			temp=pq.top();
			pq.pop();
			temp.first=temp.first+temp.second;
			pq.push(temp);


		}
		temp=pq.top();
		cout<<temp.first<<endl;
	}

  
}