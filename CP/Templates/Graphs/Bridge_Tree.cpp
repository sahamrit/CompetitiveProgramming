#include <bits/stdc++.h>
using namespace std;

#define MAXN 300005
vector < int > adj[MAXN];
vector < bool > isBridge[MAXN];// Initialise along with the adj list as false

void __DFS_FindBridges(int u, vector < bool > &visited, vector < int > &disc,vector < int > &low, vector < int > &parent, int &time){
	visited[u] = true;
	disc[u] = low[u] = ++time;
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(!visited[v]){
			parent[v] = u;
			__DFS_FindBridges(v, visited, disc, low, parent, time);
			low[u] = min(low[u], low[v]);
			if (low[v] > disc[u]) 
				isBridge[u][i] = true;
		}
		else if(v != parent[u])
			low[u] = min(low[u], disc[v]);
	}
}

void DFS_FindBridges(int n){
	vector < bool > visited(n+1);
	vector < int > disc(n+1), low(n+1), parent(n+1);
	int time = 0;
	for(int i=1; i<=n; i++)
		if(!visited[i])
			__DFS_FindBridges(i, visited, disc, low, parent, time);
}

vector < int > b_tree[MAXN];
int node_cnt = 1;

void __DFS_BridgeTree(int v, vector < bool > &visited, int curr_node){
	visited[v] = true;

	for(int i=0; i<adj[v].size(); i++)
		if(!visited[adj[v][i]]){
			if(isBridge[v][i]){
				node_cnt++;
				b_tree[curr_node].push_back(node_cnt);
				b_tree[node_cnt].push_back(curr_node);
				cout << curr_node << " " << node_cnt << endl; // Print the Results
				__DFS_BridgeTree(adj[v][i], visited, node_cnt);
			}
			else
				__DFS_BridgeTree(adj[v][i], visited, curr_node);
		}
}

void BridgeTree(int n){
	vector < bool > visited(n+1);
	__DFS_BridgeTree(1, visited, 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
 	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		isBridge[x].push_back(false);
		adj[y].push_back(x);
		isBridge[y].push_back(false);
	}
	DFS_FindBridges(n);
	BridgeTree(n);

	return 0;
}

// Input
// 5 5
// 1 2
// 2 3
// 3 1
// 4 1
// 5 2

// Output
// 1 2
// 1 3