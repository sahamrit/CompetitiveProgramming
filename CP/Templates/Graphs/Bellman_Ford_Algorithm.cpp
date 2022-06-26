#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define pii pair < int, int >

#define MAXN 100005
vector < pii > adj[MAXN];
vector < int > d(MAXN, INF), par(MAXN, -1);

void BellmanFord(int s, int n){
    d[s] = 0;

    for(int i=0; i<n-1; i++){
        bool any = false;
        for(int v=1; v<=n; v++)
            for(auto node: adj[v]){
                int u = node.first;
                int len = node.second;
                if(d[v]<INF and d[u] > d[v] + len){
                    d[u] = d[v] + len;
                    par[u] = v;
                    any = true;
                }
            }
        if(!any)
            break;
    }

    //For Checking if the graph contains negative weight cycle
    bool neg_cycle = false;
    for(int v=1; v<=n; v++){
        for(auto node: adj[v]){
            int u = node.first;
            int len = node.second;
            if(d[v]<INF and d[u] > d[v] + len){
                neg_cycle = true;
                break;
            }
        }
        if(neg_cycle){
            cout << "Graph contains a Negative weight Cycle" << endl;
            break;
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
    BellmanFord(1, n);

    for(int i=1; i<=n; i++)
        cout << i << " " << d[i] << endl;
    
    return 0;        
}