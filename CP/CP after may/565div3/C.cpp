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
vll cnt[6];
int main()
{
	fastio;
	int n;cin>>n;
	vll a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=n-1;i>=0;i--){
		if(a[i]==4)cnt[0].pb(i);
		else if(a[i]==8)cnt[1].pb(i);
		else if(a[i]==15)cnt[2].pb(i);
		else if(a[i]==16)cnt[3].pb(i);
		else if(a[i]==23)cnt[4].pb(i);
		else if(a[i]==42)cnt[5].pb(i);
	}	
	ll ctr=0;
	bool check=true;
	while(cnt[0].size()){
		int maxi=cnt[0].back();cnt[0].pop_back();
		while(cnt[1].size()){
			if()
		}
	}
}