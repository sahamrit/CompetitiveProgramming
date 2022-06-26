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
vll pos;
ll n,k,a,b;
ll solve(ll l ,ll r){
	ll cnt=0;
	if(l>r)return 0;
	if(l==r){
		auto it1=lower_bound(all(pos),l);
		auto it2=upper_bound(all(pos),l);
		cnt=it2-it1;
		return cnt==0?a:cnt*b;
	}
	ll res1,res2;
	ll mid=(l+r)/2;
	ll res3;cnt=0;
	auto it1=lower_bound(all(pos),l);
	auto it2=upper_bound(all(pos),r);
	cnt=it2-it1;
	if(cnt==0)return a;
	res1=solve(l,mid);res2=solve(mid+1,r);	
	res3=(cnt==0?a:b*cnt*(r-l+1));
	return min(res3,res1+res2);
}
int main()
{
	fastio;
	cin>>n>>k>>a>>b;
	pos.resize(k);
	for(int i=0;i<k;i++)cin>>pos[i];
	sort(all(pos));
	cout<<solve(1,1ll<<n)<<endl;	
}
