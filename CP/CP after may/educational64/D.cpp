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
#define MOD 998244353
#define INF 0x3f3f3f3f
#define MAXN (int)(2e5+1)
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
#define vertex first
#define color second
vector<pii> adj[MAXN];
ll down0[MAXN],down1[MAXN],up0[MAXN],up1[MAXN];
void dfs0(int v,int p)
{
	for(auto u:adj[v])
	{
		if(u.vertex==p)continue;
		dfs0(u.vertex,v);
		if(u.color==0)
		{
			down0[v]+=down0[u.vertex]+down1[u.vertex]+1;
		}
		else
		{
			down1[v]+=down1[u.vertex]+1;
		}
	}
}
void dfs1(int v,int p)
{
	for(auto u:adj[v])
	{
		if(u.vertex==p)continue;
		if(u.color==0)
		{
			up0[u.vertex]=up0[v]+up1[v]+down0[v]+down1[v]-(down0[u.vertex]+down1[u.vertex]);
		}
		else
		{
			up1[u.vertex]=up1[v]+down1[v]-down1[u.vertex];
		}
		dfs1(u.vertex,v);
	}
}
int main()
{
	fastio;
	int n;cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		adj[x].pb(mp(y,z));
		adj[y].pb(mp(x,z));
	}
	dfs0(1,-1);
	dfs1(1,-1);
	ll ctr=0;
	for(int i=1;i<=n;i++)
	{
		ctr+=(down0[i]+down1[i]+up0[i]+up1[i]);
	}
	cout<<ctr<<endl;
}
