#include<bits/stdc++.h>
#define p (int)(1e9+7)
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,x,y;
	cin>>n>>x>>y;
	priority_queue<int>pq;
	vector<int>a(n);
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		pq.push((-1)*(a[i]));
	}
	int h,res=0,g;
	if(x>y)cout<<n;
	else
	{
		while(!pq.empty())
		{
			h=(-1)*(pq.top());
			pq.pop();
			if(h-x<=0)
			{
				res++;
				if(pq.empty())break;
				g=(-1)*(pq.top());pq.pop();
				pq.push(-(g+y));
			}
			else
			{
				break;
			}
			if(res==n)break;


		}
		cout<<res;
	}

	
}