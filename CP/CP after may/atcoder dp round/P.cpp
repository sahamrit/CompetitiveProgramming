#include <bits/stdc++.h>
using namespace std;
#define MOD int(1e9 +7)
#define MAXN 100005
#define ll long long
inline ll mult(ll a, ll b, ll p = MOD) {return (ll) a * b % p;}
inline ll addmod(ll a, ll val, ll p = MOD) {{if ((a = (a + val)) >= p) a -= p;} return a;}

vector < int > adj[MAXN];
bool visited[MAXN];
ll wp[MAXN],bp[MAXN];
void __DFS(int v){
    visited[v] = true;
    ll wres=1,bres=1;        
    for(int u: adj[v])
        {
            if(visited[u] && adj[v].size()==1)
            {
                wp[v]=bp[v]=1;
                continue;
            }
           
           if(!visited[u])
            {
               __DFS(u);
               wres=mult(wres,addmod(wp[u],bp[u]));
               bres=mult(bres,wp[u]);
            }
        }
        wp[v]=wres;bp[v]=bres;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    if(n==1){cout<<2<<endl;
        return 0;
    }
    int m=n-1;
    while(m--)
    {
        int i, j;
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    __DFS(1);
    cout<<addmod(wp[1],bp[1])<<endl;
    return 0;        
}