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
#define MAXN (int)(1e7+1)
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
vi idx[MAXN];
ll cnt[MAXN];
int main()
{
	fastio;int n;cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		cnt[x]++;idx[x].pb(i);
	}
	ll res=LLONG_MAX,resfirst,ressecond;
	for(ll gcd=1;gcd<MAXN;gcd++){
		ll a=0,b=0,first=0,second=0;
		for(ll i=gcd;i<MAXN;i+=gcd){
			if(cnt[i] && first){
				b=i;second=idx[i][0];break;
			}
			else if(cnt[i]){
				if(cnt[i]>1){
					first=idx[i][0];second=idx[i][1];
					a=i;b=i;
					break;
				}
				else{
					first=idx[i][0];a=i;
				}
			}
		}
		if(first && second){
			ll currans=(a*b)/gcd;
			if(currans<res){
				res=currans;
				resfirst=first;ressecond=second;
			}
		}
	}
	if(resfirst>ressecond)swap(resfirst,ressecond);
	cout<<resfirst<<" "<<ressecond<<endl;
}
