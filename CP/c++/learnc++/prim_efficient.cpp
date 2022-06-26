#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[7];
int dist[7];
bool visited[7];
int main()
{
	priority_queue<tuple<int,int,int>>pq;
    
    for(int i=1;i<=6;i++)
    {
    	visited[i]=false;
    	dist[i]=INT_MAX;
    } 
    
    adj[1].push_back({3,2});
    adj[2].push_back({3,1});
    adj[1].push_back({5,5});
    adj[5].push_back({5,1});
    adj[2].push_back({6,5});
    adj[5].push_back({6,2});
    adj[2].push_back({5,3});
    adj[3].push_back({5,2});
    adj[5].push_back({2,6});
    adj[6].push_back({2,5});
    adj[3].push_back({3,6});
    adj[6].push_back({3,3});
    adj[6].push_back({7,4});
    adj[4].push_back({7,6});
    adj[3].push_back({9,4});
    adj[4].push_back({9,3});


	pq.push(make_tuple(0,2,-1));
	dist[2]=0;
	while(!pq.empty())
	{

		int a,b,c;
		tie(a,b,c)=pq.top();
		pq.pop();
		if(visited[b])
			continue;
		if(b!=2)
		cout<<c<<"--"<<b<<endl;
		visited[b]=true;
		for(auto u:adj[b])
		{
			if(!visited[u.second])
			{
				if(u.first<dist[u.second])
				{
					dist[u.second]=u.first;
					pq.push(make_tuple(-dist[u.second],u.second,b));
				}
			}

		}
	}
}