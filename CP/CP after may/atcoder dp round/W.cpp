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
#define MAXN (int)(2e5+5)
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
#define start first
#define score second
const ll INF=1e18L+5;
vector< pair<ll,ll> >interval[MAXN];
vll t(4*MAXN,INF),lazy(4*MAXN,0);
void push(ll v) {
	if(!lazy[v])return;
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}
ll query(ll v, ll tl, ll tr, ll l, ll r){
	if(l>r)
		return INF;
	if(l==tl and r==tr)
		return t[v];
	push(v);
	ll tm = (tl + tr)/2;
	return min(query(v*2, tl, tm, l, min(r, tm)),query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
void update(ll v, ll tl, ll tr, ll l, ll r, ll addend) {
    if (l > r)
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        ll tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}	
//initially score contains all intervals
//we want to remove intervals(i.e place zeroes there) such that their score is minimum
//this score is either zero(dont remove any interval) or negative
//dp[i]-considering this is ith place is one 
//iterate over indices less than i ,say j
//and dp[i]=min(dp[j]+score of all intervals inactivated between (j,i));
int main()
{
	fastio;
	ll n,m;
	cin>>n>>m;
	ll score=0;
	for(ll i=0;i<m;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		interval[b].pb(mp(a,c));
		score+=c;
	}
	update(1,0,n+2,0,0,-INF);
	ll best=INF;
	for(ll i=1;i<=n+1;i++)
	{
		for(auto p:interval[i-1])
		{
			update(1,0,n+2,0,p.start-1,p.score);
		}
		best=min(best,query(1,0,n+2,0,i));
		update(1,0,n+2,i,i,best-INF);
	}
	cout<<score-best<<endl;
}
