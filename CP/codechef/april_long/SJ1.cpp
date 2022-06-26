#include<bits/stdc++.h>
using namespace std;
vector<vector<long long int> >adj;
vector<long long int>a,m;
vector<bool>visited;
set<pair<long long int,long long int>> s;
void dfs(long long int u,long long int p,long long int gcd)
{
		
	if(adj[u].size()==1&&adj[u][0]==p)
	{
		long long int gcdcurr;
		gcdcurr=__gcd(gcd,m[u]);
		s.insert(make_pair(u,(m[u]/gcdcurr-1)*gcdcurr));
	}

	for(auto v:adj[u])
	{
		if(v==p)continue;
		if(visited[v])continue;
		visited[v]=true;
		dfs(v,u,__gcd(gcd,a[v]));
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long int t,n,u,v;
	cin>>t;
	while(t--)
	{
		cin>>n;
		a.resize(n+1);
		m.resize(n+1);
		s.clear();
		visited.resize(n+1);fill(visited.begin(),visited.end(),false);
		adj.clear();adj.resize(n+1);
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
				cin>>a[i];
		for(int i=1;i<=n;i++)
				cin>>m[i];						
		visited[1]=true;
		dfs(1,1,a[1]);
		for(auto u:s)
			cout<<u.second<<" ";
		cout<<endl;

	}

}