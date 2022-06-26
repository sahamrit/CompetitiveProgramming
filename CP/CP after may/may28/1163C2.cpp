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
int main()
{
	fastio;int n;cin>>n;
	vector<pll >v(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i].first>>v[i].second;
	}
	set<tuple<ll,ll,ll>> s;//set of lines
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ll x1,x2,y1,y2;
			x1=v[i].first;y1=v[i].second;
			x2=v[j].first;y2=v[j].second;
			ll a,b,c;
			a=y1-y2;b=x2-x1;c=y1*x2-y2*x1;
			ll gcd=__gcd(a,__gcd(b,c));
			a/=gcd;b/=gcd;c/=gcd;
			if(a<0){
				a*=-1;b*=-1;c*=-1;
			}
			s.insert(make_tuple(a,b,c)); 
		}
	}
	ll sz=s.size();
	if(sz==1){cout<<0<<endl;return 0;}	
	ll ans=((sz)*(sz-1))/2;
	vector<tuple<ll,ll,ll> >a;
	for(auto x:s){
		a.pb(x);
	}
	int i=0;ll ctr;
	while(i<sz-1){
		ctr=1;
		while(i<sz-1 && get<0>(a[i])==get<0>(a[i+1]) && get<1>(a[i])==get<1>(a[i+1])){
			ctr++;i++;
		}
		if(ctr>1)
			ans-=(ctr*(ctr-1))/2;
		i++;	
	}
	cout<<ans<<endl;

}
