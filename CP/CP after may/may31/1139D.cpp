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
#define MOD (int)(1e9+7)
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
vector<bool> isprime(MAXN,true);
map<ll,ll> primefactors[MAXN];//primefactors [i][j] is power of prime factor j in factorisation of i
vi factors[MAXN];//factors of a number i will be stored in f[i] except itself and one
ll dp[MAXN];ll m;
ll solve(ll gcd,ll no){
	vll arr;
	for(auto u:primefactors[no]){
		if(!primefactors[gcd].count(u.first)){
			arr.pb(u.first);
			continue;
		}
		if(u.second==primefactors[gcd][u.first]){
			continue;
		}
		else{
			arr.pb(u.first);
		}
	}
	ll ans=m/gcd,maxgcdmult=m/gcd;
	ll sz=arr.size();
	for(ll i=1;i<(1ll<<sz);i++){
		ll prod=1;ll sgn=1;
		for(ll j=0;j<sz;j++){
			if(i&(1ll<<j)){
				prod=mult(prod,arr[j]);
				sgn*=-1;
			}
		}
		ans+=sgn*(maxgcdmult/prod);
	}
	return ans;

}
int main()
{
	fastio;
	cin>>m;
	for(ll i=2;i<MAXN;i++){
		if(isprime[i]){
			for(ll j=i;j<MAXN;j+=i){
				if(j!=i)isprime[j]=false;
				ll temp=j,cnt=0;
				while(temp%i==0){
					temp/=i;cnt++;
				}
				primefactors[j][i]=cnt;
			}
		}
	}
	for(ll i=1;i<MAXN;i++){
		for(ll j=2*i;j<MAXN;j+=i){
			factors[j].pb(i);
		}
	}
	dp[1]=0;
	ll invm=fpow(m,MOD-2);
	for(ll i=2;i<=m;i++){
		ll ans=1;
		for(auto gcd:factors[i]){
			ll cnt=solve(gcd,i);
			ans=addmod(ans,mult(dp[gcd],mult(invm,cnt)));
		}
		ll cnt=m/i;
		dp[i]=mult(ans,mult(m,fpow(m-cnt,MOD-2)));
	}
	ll ans=1;
	for(ll i=1;i<=m;i++){
		ans=addmod(ans,mult(dp[i],invm));
	}
	cout<<ans<<endl;
}
