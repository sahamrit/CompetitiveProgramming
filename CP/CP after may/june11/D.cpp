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
ll n,k;
ll a[MAXN],b[MAXN];
ll temp[MAXN];
bool check(ll x){
	ll tick=0;
	//shout();
	vll times[MAXN];
	for(int i=1;i<=n;i++){
		//if(x==5)cout<<a[i]/b[i]<<endl;
		if(b[i] && a[i]/b[i]<=k)
		times[a[i]/b[i]].pb(i);
		temp[i]=a[i];
	}
	ll i=tick;
	while(tick<k){
		bool ok=true;
		for(;i<k;i++){
			if(times[i].size()>0){ok=false;break;}
		}
		if(ok)return true;
		while(times[i].size()>0){
			ll idx=times[i].back();
			times[i].pop_back();
			temp[idx]=min(temp[idx]+x,(ll)(1e13));tick++;
			if(b[idx]&& temp[idx]/b[idx]<=k){
				times[temp[idx]/b[idx]].pb(idx);
			}
			//if(x==5)cout<<tick<<" "<<i<<endl;
			if(tick>i && times[i].size() && i<k-1)return false;
		}

	}
	return true;
}
int main()
{
	fastio;
	cin>>n>>k;
	if(k==1){cout<<0<<endl; return 0;}
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	ll l=0,r=(ll)(2e12+5);
	while(l<r){
		ll mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	if(l>=(ll)(2e12+5))
		cout<<-1<<endl;
	else
	cout<<l<<endl;
}
