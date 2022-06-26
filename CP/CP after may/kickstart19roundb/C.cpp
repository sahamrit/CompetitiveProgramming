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
int cnt[MAXN],prefix[MAXN];
list<ll> idx[MAXN];
int n,s;
ll t[4*MAXN][2];
pll query(int v, int tl, int tr, int l, int r){
	if(l>r)
		return mp(0ll,0ll);
	if(l==tl and r==tr)
		return mp(t[v][0],t[v][1]);
	int tm = (tl + tr)/2;
	pll q1=query(v*2, tl, tm, l, min(r, tm));
	pll q2=query(v*2+1, tm+1, tr, max(l, tm+1), r);
	return mp(q1.first+q2.first,max(q1.second,q1.first+q2.second));
}
void update(int v, int tl, int tr, int pos, int new_val){
	if(tl==tr){
		t[v][0]+=new_val;
		t[v][1]+=new_val;
	}
	else{
		int tm = (tl+tr)/2;
		if(pos<=tm)
			update(v*2, tl, tm, pos, new_val);
		else
			update(v*2+1, tm+1, tr, pos, new_val);
		t[v][0] = t[v*2][0] + t[v*2 + 1][0];
		t[v][1]= max(t[2*v][1],t[2*v][0]+t[2*v+1][1]);
	}
}
int main()
{
	fastio;
	int t1;cin>>t1;int N=t1;
	while(t1--){
		cin>>n>>s;vi v(n+1);
		memset(cnt,0,sizeof(cnt));
		memset(t,0,sizeof(t));
		for(int i=0;i<MAXN;i++)idx[i].clear();
		for(int i=1;i<=n;i++){
			cin>>v[i];
			if(cnt[v[i]]<s){
				update(1,1,n,i,1);
			}else if(cnt[v[i]]==s)
			{
				update(1,1,n,i,-s);
				idx[v[i]].pb(i);
			}
			else if(cnt[v[i]]>s){
				idx[v[i]].pb(i);
			}
			cnt[v[i]]++;
		}
		ll ans=0;
		for(int l=1;l<=n;l++){
			pll q=query(1,1,n,l,n);
			ans=max(ans,q.second);
			ll val=v[l];
			auto it=idx[val].begin();
			if(it!=idx[val].end()){
				update(1,1,n,*it,s+1);
			}
			if(idx[val].size()!=0)
				idx[val].pop_front();
			it=idx[val].begin();
			if(it!=idx[val].end()){
				update(1,1,n,*it,-s);
			}			
		}	
		cout<<"Case #"<<N-t1<<": "<<max(0ll,ans)<<endl;
	}
}
