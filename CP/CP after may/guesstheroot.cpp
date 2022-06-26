#include <bits/stdc++.h>
using namespace std;
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
#define MOD (int)(1e6+3)
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
#define EPS (ld)(1e-10)
int k=10;
vll f(k+1);
ll inv_[MOD];
int lagrange(int x){
	ll ans=0,mul=1;
	for(int i=1;i<=k;i++){
		mul=mult(mul,submod(x,i));
		mul=mult(mul,inv_[submod(0,i)]);
	}
	ans=addmod(ans,mult(mul,f[0]));
	for(int i=1;i<=k;i++){
		mul=mult(mul,submod(x,submod(i,1)));
		mul=mult(mul,inv_[submod(x,i)]);

		mul=mult(mul,submod(i,addmod(k,1)));
		mul=mult(mul,inv_[i]);
		ans=addmod(ans,mult(mul,f[i]));
	}
	return ans;
}
int main()
{
	fastio;
	for(int i=0;i<=k;i++){
		cout<<"? "<<i<<endl;
		cin>>f[i];
		if(f[i]==0){
			cout<<"! "<<i<<endl;return 0;
		}	
	}
	inv_[1] = 1;
	for(int i = 2; i < MOD; ++i)
	    inv_[i] = (MOD - (MOD/i) * inv_[MOD%i] % MOD) % MOD;	
	for(int i=k+1;i<MOD;i++){
		if(lagrange(i)==0){
			cout<<"! "<<i<<endl;
			return 0;
		}
	}
	cout<<"! -1"<<endl;
}
