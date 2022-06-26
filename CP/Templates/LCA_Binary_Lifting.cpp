#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
vector < int > tree[MAXN];

int tim = 0;
vector < int > tim_in(MAXN), tim_out(MAXN);
vector < int > ances[MAXN];
int l;

void __DFS_BL(int v, vector < bool > &visited){
    tim_in[v] = ++tim;

    for(int i=1; i<=l; i++)
        ances[v][i] = ances[ances[v][i-1]][i-1];

    visited[v] = true;
    for(int i=0; i<tree[v].size(); i++)
        if(!visited[tree[v][i]]){
            ances[tree[v][i]][0] = v;
            __DFS_BL(tree[v][i], visited);
        }

    tim_out[v] = ++tim;
}

void LCA_BL_Preprocessing(int n){
    vector < bool > visited(n+1);

    l = ceil(log2(n));
    for(int i=1; i<=n; i++)
        ances[i].resize(l+1);
    ances[1][0] = 1;

    __DFS_BL(1, visited);
}

bool is_ances(int u, int v){
    return (tim_in[u] < tim_in[v] and tim_out[u] > tim_out[v]);
}

int LCA_BL(int u, int v){
    if(is_ances(u, v))
        return u;
    if(is_ances(v, u))
        return v;
    for(int i=l; i>=0; i--)
        if(!is_ances(ances[u][i], v))
            u = ances[u][i];
    return ances[u][0];
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
        tree[i].push_back(j);
        tree[j].push_back(i);
    }
    LCA_BL_Preprocessing(n);

    int u, v;
    cin >> u >> v;
    cout << LCA_BL(u, v) << endl;
    
    return 0;        
}