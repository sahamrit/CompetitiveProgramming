#include <bits/stdc++.h>
using namespace std;

#define pii pair < int, int >
#define MAXN 200005
vector < pair < int, int > > MST[MAXN];
vector < pair < pii, pii > > edges;
vector < bool > in_MST(MAXN);

#define weight first.first
#define idx first.second
#define x second.first
#define y second.second

vector < int > par(MAXN);
vector <int > size(MAXN,-1);
long long MST_Cost = 0;

void make_set(int v) {
    par[v] = v;
    size[v] = 1;
}


int find_set(int v) {
    if (v == par[v])
        return v;
    return par[v] = find_set(par[v]);
}


void MST_Kruskal(int n, int m){
    MST_Cost = 0;
    for(int i=1; i<=n; i++)
        make_set(i);
    int a,b;
    sort(edges.begin(), edges.end()); //edges is vector < pair < pii, pii > >
    for(int i=0; i<m; i++){
        auto edge = edges[i];
        a=find_set(edge.x);
        b=find_set(edge.y);
        if(a!=b){
            ///merge a and b
            if (size[a] < size[b])
                swap(a, b);
            par[b] = a;
            size[a] += size[b];

            MST_Cost += edge.weight;
            in_MST[edge.idx] = true;
            MST[edge.x].push_back(make_pair(edge.y, edge.weight));
            MST[edge.y].push_back(make_pair(edge.x, edge.weight));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{w, i}, {u, v}});
    }
    MST_Kruskal(n, m);
    cout<<MST_Cost<<endl;
    return 0;
}
