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
int freqcolor[MAXN],freqcount[MAXN];
//freq stores frequency of a colour
//cnt stores frequency of count of colour
int main()
{
	fastio;
	int n;cin>>n;
	int mx=0;int ans=0;
	for(int i=1;i<=n;i++){
		int u;cin>>u;
		freqcount[freqcolor[u]]--;
		freqcount[++freqcolor[u]]++;
		mx=max(mx,freqcolor[u]);
		bool check=false;
		if(freqcount[1]==i)check=true;//all colors appeared have count 1(mx=1)
		else if(freqcolor[u]==i)check=true;//only one color has appeared so far
		else if(freqcount[mx]*mx==i-1)check=true;//1 color appeared once,rest x times(x>1)
		else if(freqcount[mx-1]*(mx-1)==i-mx)check=true;//all color appeared till now appeared mx-1 times & only 1 mx times
		if(check)ans=max(ans,i);
	}
	cout<<ans<<endl;
}
