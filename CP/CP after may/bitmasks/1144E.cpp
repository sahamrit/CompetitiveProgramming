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
	fastio;
	int k;cin>>k;
	string s,t;
	cin>>s>>t;
	vi a(k+1),b(k+1);
	for(int i=1;i<=k;i++){
		a[i]=s[i-1]-'a';
		b[i]=t[i-1]-'a';
	}
	for(int i=k;i>=0;i--){
		a[i]+=b[i];
		int q=a[i]/26;
		a[i]%=26;
		if(i>=1){
			a[i-1]+=q;
		}
	}
	for(int i=0;i<=k;i++){
		int rem=a[i]%2;
		a[i]/=2;
		if(i+1<=k){
			a[i+1]+=26*rem;
		}
	}
	for(int i=1;i<=k;i++)
		cout<<(char)(a[i]+'a');
	cout<<endl;
}
