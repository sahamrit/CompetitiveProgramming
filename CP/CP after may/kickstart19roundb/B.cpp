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
bool comp(tuple<ll,ll,ll>a,tuple<ll,ll,ll>b)
{	ll s1,e1,l1,s2,e2,l2;
	s1=get<0>(a);e1=get<1>(a);l1=get<2>(a);
	s2=get<0>(b);e2=get<1>(b);l2=get<2>(b);
	return s1*l2<s2*l1;
}

int main()
{
	fastio;
	int t;cin>>t;int N=t;
	while(t--)
	{
		int n;cin>>n;
		vector<tuple<ll,ll,ll> >v(n+1);
		int maxtime=0;
		for(int i=1;i<=n;i++){
			ll s,e,l;cin>>s>>e>>l;
			maxtime+=s;
			v[i]=make_tuple(s,e,l);
		}
		sort(v.begin()+1,v.end(),comp);
		maxtime+=5;
		vll dp(MAXN,0);
		//dp[time][itemindex]considering items upto item index and maxtime as time
		//whats the max energy
		for(int i=1;i<=n;i++)
		{
			for(int j=maxtime;j>=0;j--){
				if(j+get<0>(v[i])<maxtime){
					dp[j+get<0>(v[i])]=max(dp[j+get<0>(v[i])],dp[j]+max(0ll,get<1>(v[i])-j*(get<2>(v[i]))));
				}
			}
		}
		ll ans=LLONG_MIN; 
		for(int i=0;i<=maxtime;i++)ans=max(ans,dp[i]);		
		cout<<"Case #"<<N-t<<": "<<ans<<endl;
	}
}
