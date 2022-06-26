#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
vector < int > adj[MAXN];
vector < int > t_sort;

void __DFS(int v, vector < bool > &visited){
    visited[v] = true;
    for(int u: adj[v])
        if(!visited[u])
            __DFS(u, visited);
    t_sort.push_back(v);
}

void TopologicalSort(int n){
    vector < bool > visited(n+1);
    for(int i=1; i<=n; i++)
        if(!visited[i])
            __DFS(i, visited);
    reverse(t_sort.begin(), t_sort.end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}