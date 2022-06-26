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
int t[4*MAXN],lazy[4*MAXN];
vector<int> a(MAXN),ans(MAXN,0),ansleft(MAXN,0),ansrht(MAXN,0);
map<ll,vector<pll>>rht,lft;
void push(int v) {
	if(!lazy[v])return;
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}
void build(int v, int tl, int tr){
	if(tl==tr)
		t[v] = a[tr];
	else{
		int tm = (tl + tr)/2;
		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);
		t[v] = min(t[v*2],t[v*2+1]);
	}
}

int query(int v, int tl, int tr, int l, int r){
	if(l>r)
		return INT_MAX;
	if(l==tl and r==tr)
		return t[v];
	push(v);
	int tm = (tl + tr)/2;
	return min(query(v*2, tl, tm, l, min(r, tm)),query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r)
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}
int main()
{
	fastio;
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	build(1,1,n);
	vector<pll> segments(m+1);
	for(int i=1;i<=m;i++){
		cin>>segments[i].first>>segments[i].second;
		rht[segments[i].second].pb(segments[i]);
		lft[segments[i].first].pb(segments[i]);
	}
	for(int i=1;i<=n;i++){
		int mini=min(query(1,1,n,1,i-1),query(1,1,n,i+1,n));
		if(mini==INT_MAX)ans[i]=0;//it is the max and min
		else{
				ans[i]=a[i]-mini;
		}
	}		
	for(int i=1;i<=n;i++){
		int mini=query(1,1,n,1,i-1);
		if(mini!=INT_MAX){
			if(a[i]-mini>ans[i]){
				ansleft[i]=1;
				ans[i]=a[i]-mini;
			}
		}
		for(int j=0;j<rht[i].size();j++){
			pll p=rht[i][j];
			update(1,1,n,p.first,p.second,-1);
		}
	}
	for(int i=1;i<=n;i++){		
		for(int j=0;j<rht[i].size();j++){
			pll p=rht[i][j];
			update(1,1,n,p.first,p.second,1);
		}
	}
	for(int i=n;i>=1;i--){
		int mini=query(1,1,n,i+1,n);
		if(mini!=INT_MAX){
			if(ans[i]<a[i]-mini){
				ans[i]=a[i]-mini;
				ansrht[i]=1;
			}
		}	
		for(int j=0;j<lft[i].size();j++){
			pll p=lft[i][j];
			update(1,1,n,p.first,p.second,-1);
		}
	}	
	ll maxans=ans[1],ansidx=1;
	for(int i=2;i<=n;i++){
		if(ans[i]>maxans){
			maxans=ans[i];
			ansidx=i;
		}
	}
	cout<<maxans<<endl;
	vi res;
	for(int i=1;i<=m;i++){
		if(segments[i].second<ansidx && ansleft[ansidx])res.pb(i);
		if(segments[i].first>ansidx && ansrht[ansidx])res.pb(i);
	}
	cout<<res.size()<<endl;
	for(auto x:res)cout<<x<<" ";
}
