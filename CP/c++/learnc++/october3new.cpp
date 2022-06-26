#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long sum=0,k;
int a[100000];
int b[100000];
pair<long long,int >temp,temp1;
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

		for(long long i=min(sum,m);i>0;)
		{
			temp=pq.top();
			pq.pop();
			temp1=pq.top();
			if(temp.second!=0)
			    k=(temp.first-temp1.first)/(-temp.second);
			else 
			{
				cout<<0<<endl;
				exit(0);
			}

			
			if(k!=0)
			{
				temp.first=temp.first+min(k,m)*(temp.second);
				i-=min(k,m);
				pq.push(temp);

			}
			else
				{
					temp.first=temp.first+temp.second;
			        pq.push(temp);
			        i--;

				}


		}
		temp=pq.top();
		cout<<temp.first<<endl;
	}

  
}