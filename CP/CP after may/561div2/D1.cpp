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
ll bitmax=ceil(log2(1e14));
ll check(ll a,ll b,ll m){
	ll res=1;
	bool ok=false;
	for(ll i=0;i<bitmax;i++){
		if(res*(a+1)>b){
			ok=false;break;
		}
		if(res*(a+1)<=b && b<=res*(a+m)){
			ok=true;break;
		}
		res=2*res;
	}
	if(ok)return res;
	return -1;
}
int main()
{
	fastio;
	ll a,b,m,q;cin>>q;
	while(q--){
		cin>>a>>b>>m;
		if(a==b){
			cout<<1<<" "<<a<<endl;continue;
		}
		ll res=check(a,b,m);		
		if(res==-1)cout<<-1<<endl;
		else{
			ll n=log2(res)+2;
			ll k=b/res-a;
			ll r=b%res;	
			vll v(n+1);
			v[1]=a;
			ll p=a,tempr=0;
			for(ll i=2;i<=n;i++){
				v[i]=p+k+ (i==n?0:(r>>(n-i-1))&1);
				p+=v[i];
			}
			cout<<n<<" ";
			for(int i=1;i<=n;i++){
				cout<<v[i]<<" ";
			}
			cout<<endl;
		}
	}
}
