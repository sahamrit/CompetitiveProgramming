#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
vector<int> adj[MAXN];

//An Adjacency List Graph Should be declared globally
void __DFS(int v, vector<bool> &visited)
{
    visited[v] = true;
    for(int u: adj[v])
        if(!visited[u])
            __DFS(u, visited);
}

void DFS(int n)
{
    vector<bool> visited(n+1);
    for(int i=1; i<=n; i++)
        if(!visited[i])
            __DFS(i, visited);
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
    DFS(n);
    
    return 0;        
}