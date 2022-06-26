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
#define MAXN (int)(3e6+20)
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
#define valsum first
#define wsum second
bool comp(tuple<ll,ll,ll> a,tuple<ll,ll,ll> b)
{
	return (get<0>(a)+get<1>(a))<(get<0>(b)+get<1>(b));
}
vll dp(MAXN,0);
int main()
{
	fastio;
	int n;cin>>n;
	vector< tuple<ll,ll,ll> >v(n+1);
	for(int i=1;i<=n;i++)
	{
		ll a,b;cin>>a>>b;
		v[i]=make_tuple(b,a,1);
	}
	sort(v.begin()+1,v.end(),comp);//exchange arguments
	//dp[i]-max score with total weight<=i so far considering n items
	//when considering n+1 th item see if all weights <= its strength 
	//can increase the dp[weights + curr_weight] from its previous value
	for(int i=1;i<=n;i++)
	{
		for(ll weight=get<1>(v[i]);weight>=0;weight--)
		{
			if(weight+get<0>(v[i])<MAXN)
			dp[weight+get<0>(v[i])]=max(dp[weight+get<0>(v[i])],dp[weight]+get<2>(v[i]));
		}
	}
	 ll res=0;
	 for(int i=0;i<MAXN;i++)
	 {
	 	res=max(res,dp[i]);
	 }
	 cout<<res<<endl;
}
