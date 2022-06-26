#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
vector < int > adj[MAXN];

void __DFS(int v, vector <bool> &visited, vector < int > &tin, vector < int > &tout){
    visited[v] = true;
    tin[v] = timer++;
    for(int u: adj[v])
        if(!visited[u])
            __DFS(u, visited, tin, tout);
    tout[v] = timer++;
}

void DFS(int n){
    vector < bool > visited(n+1);
    vector < int > tin(MAXN), tout(MAXN);
    for(int i=1; i<=n; i++)
        if(!visited[i])
            __DFS(i, visited, tin, tout);
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
    }
    
    return 0;        
}