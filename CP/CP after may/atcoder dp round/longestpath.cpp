#include<bits/stdc++.h>
#define endl "\n"
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAXN (int)(1e5+1)
using namespace std;
vector<int>adj[MAXN];
bool visited[MAXN];
int indegree[MAXN];
int dist[MAXN];
void dfs(int u)
{
	visited[u]=true;
	for(auto v:adj[u])
	{
		dist[v]=max(dist[v],dist[u]+1);
		indegree[v]--;
		if(indegree[v]==0)
			dfs(v);
	}
}
int main()
{
	fastio;
	int n,m,x,y;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		indegree[y]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(!visited[i]&&indegree[i]==0)
		{
			dfs(i);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,dist[i]);
	cout<<ans<<endl;			
}