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
#define MAXN (int)(2750137)
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
vll pos(MAXN,0);
vll prime(MAXN,0);
vll grtfctr(MAXN,0);
int main()
{
	fastio;
	int n;cin>>n;
	vll b(2*n+1);
	for(int i=1;i<=2*n;i++)cin>>b[i];
	for(int i=2;i<MAXN;i++){
		if(isprime[i]){
			for(int j=2*i;j<MAXN;j+=i)isprime[j]=false;
		}
	}
	int ctr=0;
	for(int i=2;i<MAXN;i++){
		if(isprime[i]){
			ctr++;
			pos[i]=ctr;
			prime[ctr]=i;
		}	
	}
	for(int i=2;i<MAXN;i++){
		for(int j=2*i;j<MAXN;j+=i){
			grtfctr[j]=i;
		}
	}
	multiset<int> prim,nonprim;
	for(int i=1;i<=2*n;i++){
		if(isprime[b[i]])prim.insert(b[i]);
		else nonprim.insert(b[i]);
	}
	vll ans;
	while(nonprim.size()>0){
		auto it=nonprim.rbegin();
		ans.pb(*it);
		int factor=grtfctr[*it];
		nonprim.erase(nonprim.find(*it));
		if(isprime[factor]){
			prim.erase(prim.find(factor));
		}
		else{
			nonprim.erase(nonprim.find(factor));
		}
	}
	while(prim.size()){
		auto it=prim.rbegin();
		int currprime=*it;
		prim.erase(prim.find(*it));
		ans.pb(pos[currprime]);
		prim.erase(prim.find(pos[currprime]));
	}
	for(auto u:ans)cout<<u<<" ";

}
