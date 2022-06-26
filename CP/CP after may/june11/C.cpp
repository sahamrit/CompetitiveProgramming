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
#define MAXN (int)(5e3+5)
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
ll l[MAXN],r[MAXN];
int main()
{
	fastio;
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=q;i++)cin>>l[i]>>r[i];
	ll ans=0;
	for(int i=1;i<=q;i++){
		vll diff(n+3,0),a(n+3,0),d(n+3,0),pref(n+3,0);
		for(int j=1;j<=q;j++){
			if(j==i)continue;
			diff[l[j]]++;
			diff[r[j]+1]--;
		}
		for(int j=1;j<=n;j++){
			a[j]=diff[j]+a[j-1];
		}
		ll cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j]>=1)cnt++;
			if(a[j]==1)d[j]=1;
		}
		for(int j=1;j<=n;j++){
			pref[j]=d[j]+pref[j-1];
		}
		for(int j=1;j<=q;j++){
			if(i==j)continue;
			ans=max(ans,cnt-(pref[r[j]]-pref[l[j]-1]));
		}
	}
	cout<<ans<<endl;
}
