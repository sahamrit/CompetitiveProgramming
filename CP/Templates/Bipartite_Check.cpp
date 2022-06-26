#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
vector < int > adj[MAXN];

void __DFS_isBiparite(int v, vector <bool> &visited, vector < int > &color, bool &isBipartite){
    visited[v] = true;
    for(auto u: adj[v]){	
    	if(!isBipartite)
        	return;
    	if(color[v]==color[u]){
    		isBipartite = false;
    		return;
    	}
        if(!visited[u]){
        	color[u] = -color[v];
            __DFS_isBiparite(u, visited, color, isBipartite);
        }
    }
}

bool isBiparite(int n){
    vector < bool > visited(n+1);
    vector < int > color(n+1);
    bool is_Bipartite = true;
    for(int i=1; i<=n; i++)
        if(!visited[i]){
        	color[i] = 1;
            __DFS_isBiparite(i, visited, color, is_Bipartite);
        }
    return is_Bipartite;
}

int main()
{
	ios_base::sync_with_stdio(false);
 	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	while(m--)
	{
		int i, j;
		cin >> i >> j;
		adj[i].push_back(j);
		adj[j].push_back(i);
	}
	cout << isBiparite(n) << endl;
	
	return 0;
}