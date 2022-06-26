#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
vector < int > adj[MAXN], adjT[MAXN];

void DFS(int v, vector < bool > &used, vector < int > &order){
    used[v] = true;
    for(int u: adj[v])
        if(!used[u])
            DFS(u, used, order);
    order.push_back(v);
}

void DFST(int v, vector < bool > &used, vector < int > &component){
    used[v] = true;
    component.push_back(v);
    for(int u: adjT[v])
        if(!used[u])
            DFST(u, used, component);
}

void SCC(int n){
    vector < bool > used(n+1);
    vector < int > order;

    for(int i=1; i<=n; i++)
        if(!used[i])
            DFS(i, used, order);
    reverse(order.begin(), order.end());

    fill(used.begin(), used.end(), false);
    vector < int > component;
    for(int v: order)
        if(!used[v]){
            DFST(v, used, component);
            for(int u: component)
                cout << u << " ";
            cout << endl;
            component.clear();
        }
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
        adjT[j].push_back(i);
    }
    SCC(n);

    return 0;        
}

// Input
// 5 5
// 2 1
// 1 3
// 3 2
// 1 4
// 4 5

// Output
// 1 2 3 
// 4 
// 5