#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
vector < int > adj[MAXN];

void __BFS(int src, vector < bool > &visited, vector < int > &dist, vector < int > &par){
    queue < int > q;
    q.push(src);
    visited[src] = true;
    par[src] = -1;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u: adj[v])
            if(!visited[u]){
                visited[u] = true;
                q.push(u);
                dist[u] = dist[v] + 1;
                par[u] = v;
            }
    }
}

void BFS(int n){
    vector < bool > visited(MAXN);
    vector < int > dist(MAXN), par(MAXN);
    for(int i=1; i<=n; i++)
        if(!visited[i])
            __BFS(i, visited, dist, par);
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
    BFS(n);

    return 0;
}