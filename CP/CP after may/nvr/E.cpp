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
#define MAXN (int)(5e5+5)
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
vll adj[MAXN];
ll nxt[MAXN][23];
ll LOG=22;
int main()
{
	fastio;ll n,m;
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		ll x,y;cin>>x>>y;
		adj[x].pb(y);
	}
	ll mx=0;
	for(ll i=0;i<MAXN;i++){
		for(auto r:adj[i])mx=max(r,mx);
		nxt[i][0]=max(i,mx);	
	}
	for(ll i=1;i<LOG;i++){
		for(int j=0;j<MAXN;j++){
			nxt[j][i]=nxt[nxt[j][i-1]][i-1];
		}
	}
	while(m--){
		ll x,y;cin>>x>>y;
		ll ans=0;
		for(ll i=LOG-1;i>=0;i--){
			while(nxt[x][i]<y){
				if(x==nxt[x][i]){
					break;
				}
				x=nxt[x][i];ans+=(1ll<<i);
			}
		}
		x=nxt[x][0];ans+=1;
		if(x>=y)cout<<ans<<endl;
		else cout<<-1<<endl;
	}
}
