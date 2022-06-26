#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
vector < int > adj[MAXN];
vector < bool > Is_CutPoint(MAXN);

int timer;

void __DFS_FindCutPoints(int v, int par, vector < bool > &visited, vector < int > &tin, vector < int > &fup){
    visited[v] = true;
    tin[v] = fup[v] = timer++;
    int children = 0;

    for(int u: adj[v]){
        if(u==par) continue;
        if(visited[u])
            fup[v] = min(fup[v], tin[u]);
        else{
            __DFS_FindCutPoints(u, v, visited, tin, fup);
            fup[v] = min(fup[v], fup[u]);
            if(fup[u] >= tin[v] and par!=-1)
                Is_CutPoint[v] = true;
            children++;
        }
    }
    if(par==-1 and children > 1)
        Is_CutPoint[v] = true;
}

void FindCutPoints(int n){
    timer = 0;
    vector < bool > visited(n+1);
    vector < int > tin(n+1, -1), fup(n+1, -1);
    
    for(int i=1; i<=n; i++)
        if(!visited[i])
            __DFS_FindCutPoints(i, -1, visited, tin, fup);
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
    FindCutPoints(n);
    for(int i=1; i<=n; i++)
        if(Is_CutPoint[i])
            cout << i << endl;

    return 0;        
}

// Input
// 5 4
// 1 2
// 4 2
// 2 3
// 4 5

// Output
// 2
// 4