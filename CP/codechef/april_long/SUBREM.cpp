#include<bits/stdc++.h>
using namespace std;
vector<vector<long long int> >adj;
vector<long long int>a,sum,score;
vector<bool>visited;
void dfs(long long int u,long long int p,long long int x)
{
		
	sum[u]+=a[u];	
	for(auto v:adj[u])
	{
		if(v==p)continue;
		if(visited[v])continue;
		visited[v]=true;
		dfs(v,u,x);
		sum[u]+=sum[v];
		score[u]=max(score[u],score[u]+score[v]);
	}
	score[u]=max(score[u],-sum[u]-x);	

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long int t,n,x,u,v;
	cin>>t;
	while(t--)
	{
		cin>>n>>x;
		a.resize(n+1);
		sum.resize(n+1);fill(sum.begin(),sum.end(),0);
		score.resize(n+1);fill(score.begin(),score.end(),0);
		visited.resize(n+1);fill(visited.begin(),visited.end(),false);
		adj.clear();adj.resize(n+1);
		for(int i=1;i<=n;i++)
				cin>>a[i];
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		visited[1]=true;
		dfs(1,-1,x);
		cout<<sum[1]+score[1]<<endl;

	}

}