#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//STANDARD DATA TYPES
#define ll long long
#define llu unsigned long long
#define ld long double
//ADV DATA TYPES
#define pii pair < int , int >
#define pll pair < ll, ll >
#define mp make_pair
#define ff first
#define ss second
//C ++ DS
#define vi vector < int >
#define vll vector < ll >
#define pb push_back
#define pf push_front
#define iter :: iterator
#define all(x) x.begin(),x.end()

//priority_queue < pii, vector < pii >, greater < pii > > pq;
//lower_bound(v.begin(),v.end(),20);//for any sorted container
//CONSTANTS
int MOD;
#define INF 0x3f3f3f3f
#define MAXN (int)(1e5+1)
//MOD OPERATIONS
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
inline ll inv(ll a, ll p = MOD) {return fpow(a, p - 2, p);}
inline ll addmod(ll a, ll val, ll p = MOD) {{if ((a = (a + val)) >= p) a -= p;} return a;}
inline ll submod(ll a, ll val, ll p = MOD) {{if ((a = (a - val)) < 0) a += p;}return a;}
inline ll mult(ll a, ll b, ll p = MOD) {return (ll) a * b % p;}
//DEBUG
#define shout()  {cout << "I'm Here...!!!" << endl;}
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
vi adj[MAXN],children[MAXN],prefix[MAXN],suffix[MAXN];
ll down[MAXN],up[MAXN];
void dfs_one(int v,int parent)
{
	ll res=1;
	for(auto u:adj[v])
	{
		if(u!=parent)
		{
			children[v].pb(u);
			dfs_one(u,v);
			res=mult(res,addmod(1,down[u]));
			prefix[v].pb(res);

		}
	}
	down[v]=res;
}
void dfs_two(int v,int parent)
{
	ll res=1;
	if(v==1)up[v]=1;
	for(int i=0;i<children[v].size();i++)
	{
		res=1;
		if(i!=0)
			res=mult(res,prefix[v][i-1]);
		if(i!=children[v].size()-1)
			res=mult(res,suffix[v][i+1]);
		res=mult(res,up[v]);
		up[children[v][i]]=addmod(res,1);
		dfs_two(children[v][i],v);

	}
}
int main()
{
	fastio;
	int n;
	cin>>n>>MOD;
	for(int i=1;i<n;i++)
	{
		int x,y;cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs_one(1,-1);
	for(int i=1;i<=n;i++)
	{
		int sz=children[i].size();
		suffix[i].resize(sz);
		ll res=1;
		for(int j=sz-1;j>=0;j--)
		{
			res=mult(res,addmod(1,down[children[i][j]]));
			suffix[i][j]=res;
		}
	}
	dfs_two(1,-1);
	ll res;

	for(int i=1;i<=n;i++)
	{
		res=mult(up[i],down[i]);
		cout<<res<<endl;
	}

}
