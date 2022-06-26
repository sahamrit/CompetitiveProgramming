#include<bits/stdc++.h>
using namespace std;
const int N=3e5+1;
vector<int>adj[N];
bool visited[N];
bool colored[N];
set<int>s;
void dfs(int v)
{
	bool check=true;
	for(auto u:adj[v])
	{
		if(!visited[u])
		{
			visited[u]=true;
			if(!colored[u])check=false;
			dfs(u);
		}
	}
	if(check&&colored[v])
		s.insert(v);
}
int main()
{
	int n,parent,color,root;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>parent>>color;
		if(parent!=-1)
			{adj[i].push_back(parent);
			adj[parent].push_back(i);
			}
		else root=i;	
		if(color)
			colored[i]=true;
		else colored[i]=false;

	}
	visited[root]=true;
	dfs(root);
	if(s.empty())
	{
		cout<<"-1"<<endl;
		return 0;
	}
	for(auto u:s)
	{
		cout<<u<<" ";
	}
}		