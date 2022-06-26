#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
vector < int > adj[MAXN];
int timer;

void __DFS_FindBridges(int v, int par, vector < bool > &visited, vector < int > &tin, vector < int > &fup){
    visited[v] = true;
    tin[v] = fup[v] = timer++;

    for(int u: adj[v]){
        if(u==par) continue;
        if(visited[u])
            fup[v] = min(fup[v], tin[u]);
        else{
            __DFS_FindBridges(u, v, visited, tin, fup);
            fup[v] = min(fup[v], fup[u]);
            if(fup[u] > tin[v])
                cout << v << " " << u << endl;
        }
    }
}

void FindBridges(int n){
    timer = 0;
    vector < bool > visited(n+1);
    vector < int > tin(n+1, -1), fup(n+1, -1);
    
    for(int i=1; i<=n; i++)
        if(!visited[i])
            __DFS_FindBridges(i, -1, visited, tin, fup);
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
    FindBridges(n);

    return 0;        
}

// Input
// 5 4
// 1 2
// 4 2
// 2 3
// 4 5

// Output
// 4 5
// 2 4
// 2 3
// 1 2