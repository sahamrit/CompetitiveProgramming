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
ll t[4*MAXN];
ll dp[MAXN];
ll querySeg(int v, int tl, int tr, int l, int r){
	if(l>r)
		return 0;
	if(l==tl and r==tr)
		return t[v];
	int tm = (tl + tr)/2;
	return max(querySeg(v*2, tl, tm, l, min(r, tm)),querySeg(v*2+1, tm+1, tr, max(l, tm+1), r));
}
void updateSeg(int v, int tl, int tr, int pos, ll new_val){
	if(tl==tr)
		t[v] = new_val;
	else{
		int tm = (tl+tr)/2;
		if(pos<=tm)
			updateSeg(v*2, tl, tm, pos, new_val);
		else
			updateSeg(v*2+1, tm+1, tr, pos, new_val);
		t[v] = max(t[v*2],t[v*2 + 1]);
	}
}
int main()
{
	fastio;
	int n;cin>>n;
	vll h(n+1),a(n+1);
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	//dp[i] max total score when last flower picked is of height i
	//note height is unique so height and flower has unique relation

	for(int flower=1;flower<=n;flower++)
	{
		
		dp[h[flower]]=a[flower]+querySeg(1,0,n,0,h[flower]-1);
	//	cout<<h[flower]<<" "<<querySeg(1,0,n,0,h[flower]-1)<<endl;
		updateSeg(1,0,n,h[flower],dp[h[flower]]);		
	}
	ll res=LLONG_MIN;	
	for(int i=1;i<=n;i++)
	{
		res=max(res,dp[i]);
		//cout<<dp[i]<<" ";
	}
	cout<<res<<endl;
}
