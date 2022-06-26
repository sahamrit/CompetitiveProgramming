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
#define x first
#define y second
int n,k;
pll cnt(ll len){
	if(len==0)
	return mp(0,1);
	if(len%2){
		len/=2;
		pll res=cnt(len);
		return mp(addmod(mult(res.x,res.x),mult(k-1,mult(res.y,res.y)))
			,addmod(mult(2,mult(res.x,res.y)),mult(k-2,mult(res.y,res.y))));
	}
	else
	{
		pll res=cnt(len-1);
		return mp(mult(k-1,res.y),addmod(res.x,mult(k-2,res.y))); 
	}
}
ll solve(int l,int r,vll &a){
	if(r==(int)a.size()){
		if(l==r-1)return 1;
		ll ans=1,len=r-l-2;
		if(l<0){ans=k;len--;}
		if(len==-1)return ans;
		pll res=cnt(len);
		return mult(ans,addmod(res.x,mult(k-1,res.y)));
	}
	if(l<0){
		if(r==0)return 1;
		ll ans=1,len=r-1;
		pll res=cnt(len);
		return mult(ans,addmod(res.x,mult(k-1,res.y)));
	}
	pll res=cnt(r-l-1);
	if(a[l]==a[r])return res.x;
	return res.y;
}
int main()
{
	fastio;cin>>n>>k;
	vll odd,even;
	for(int i=0;i<n;i++){
		int p;cin>>p;
		if(i%2==0)even.pb(p);
		else odd.pb(p);
	}
	ll ans=1;
	int l=-1;
	for(int i=0;i<(int)odd.size();i++){
		if(odd[i]==-1)continue;
		ans=mult(ans,solve(l,i,odd));
		l=i;
	}
	ans=mult(ans,solve(l,odd.size(),odd));
	l=-1;
	for(int i=0;i<(int)even.size();i++){
		if(even[i]==-1)continue;
		ans=mult(ans,solve(l,i,even));
		l=i;
	}
	ans=mult(ans,solve(l,even.size(),even));		
	cout<<ans<<endl;
		
}
