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
int p[MAXN],pos[MAXN],t[4*MAXN],n;
//max idx of maximum element between l to r
int querySeg(int v, int tl, int tr, int l, int r){
	if(l>r)
		return 0;
	if(l==tl and r==tr)
		return t[v];
	int tm = (tl + tr)/2;
	int q1=querySeg(v*2, tl, tm, l, min(r, tm));
	int q2=querySeg(v*2+1, tm+1, tr, max(l, tm+1), r);
	return p[q1]>p[q2]?q1:q2;
}
void updateSeg(int v, int tl, int tr, int pos, int new_val){
	if(tl==tr)
		t[v] = tl;
	else{
		int tm = (tl+tr)/2;
		if(pos<=tm)
			updateSeg(v*2, tl, tm, pos, new_val);
		else
			updateSeg(v*2+1, tm+1, tr, pos, new_val);
		t[v] = p[t[v*2]]>p[t[v*2 + 1]]?t[2*v]:t[2*v+1];
	}
}
ll solve(int l,int r)
{
	if(l>=r)return 0;
	ll ans=0;
	int midx=querySeg(1,1,n,l,r);
	if(2*midx<l+r)
	{
		for(int i=midx-1;i>=l;i--)
		{
			int temp=p[midx]-p[i];
			if(pos[temp]>midx && pos[temp]<=r)ans++;
		}
	}else
	{
		for(int i=midx+1;i<=r;i++)
		{
			int temp=p[midx]-p[i];
			if(pos[temp]<midx && pos[temp]>=l)ans++;
		}
	}
	ans+=solve(l,midx-1);
	ans+=solve(midx+1,r);
	return ans;
} 
int main()
{
	fastio;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		pos[p[i]]=i;
		updateSeg(1,1,n,i,p[i]);
	}
	cout<<solve(1,n)<<endl;
}
