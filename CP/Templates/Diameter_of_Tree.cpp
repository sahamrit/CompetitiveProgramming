#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()

#define MAXN 100005
vector<int> adj[MAXN];
vector<bool> visited(MAXN);

void __DFS_Diameter(int v, int hops, int &max_hops, int &x){
    visited[v] = true;
    hops++;
	if(hops > max_hops){
		max_hops = hops;
		x = v;
	}
    for(int u: adj[v])
        if(!visited[u])
            __DFS_Diameter(u, hops, max_hops, x);
}

int Diameter(int n, int v){
	int max_hops = INT_MIN, x = v;

    fill(all(visited), false);
    int hops = 0;
    __DFS_Diameter(v, hops, max_hops, x);

    fill(all(visited), false);
    int hops_x = 0;
    __DFS_Diameter(x, hops_x, max_hops, x);

    return max_hops-1;
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
    cout << Diameter(n, 1) << endl;

    return 0;
}

// Input
// 5 5
// 1 2
// 2 3
// 3 1
// 4 1
// 5 2

// Output
// 3