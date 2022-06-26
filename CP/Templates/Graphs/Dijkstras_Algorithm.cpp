#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define pii pair < int, int >

#define MAXN 100005
vector < pii > adj[MAXN];
vector < int > d(MAXN, INF), par(MAXN, -1);

void dijkstra(int s){
    priority_queue < pii, vector < pii >, greater < pii > > pq;

    d[s] = 0;
    pq.push({0, s});

    while(!pq.empty()){
        auto node = pq.top();
        int v = node.second;
        pq.pop();

        if(d[v]!=node.first)
            continue;

        for(auto edge: adj[v]){
            int u = edge.first;
            int len = edge.second;
            if(d[v] + len < d[u]){
                d[u] = d[v] + len;
                par[u] = v;
                pq.push({d[u], u});
            }
        }
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
        int i, j, w;
        cin >> i >> j >> w;
        adj[i].push_back({j, w});
        adj[j].push_back({i, w});
    }
    dijkstra(1);

    for(int i=1; i<=n; i++)
        cout << i << " " << d[i] << endl;
    
    return 0;        
}

// Input
// 9 14
// 1 2 4
// 1 8 8
// 2 3 8
// 2 8 11
// 3 4 7
// 3 9 2
// 3 6 4
// 4 5 9
// 4 6 14
// 5 6 10
// 6 7 2
// 7 8 1
// 7 9 6
// 8 9 7

// Output
// 1 0
// 2 4
// 3 12
// 4 19
// 5 21
// 6 11
// 7 9
// 8 8
// 9 14