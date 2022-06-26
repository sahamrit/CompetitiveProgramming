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
#define MAXN (int)(305)
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
int cnt[4],n;
ld dp[MAXN][MAXN][MAXN];
ld ev(int a,int b,int c)
{
	if(a==0 && b==0 && c==0)return 0;

	ld p_waste=((ld)n-a-b-c)/n;
	ld p_a=(ld)a/n,p_b=(ld)b/n,p_c=(ld)c/n;
	if(dp[a][b][c]>0)return dp[a][b][c];

	dp[a][b][c]=(1/(1-p_waste))*(1+
		(a==0?0:p_a*ev(a-1,b,c))+(c==0?0:p_c*ev(a,b+1,c-1))+(b==0?0:p_b*ev(a+1,b-1,c)));
	return dp[a][b][c]; 
}
int main()
{
	fastio;
	int a;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		cnt[a]++;
	}
	cout<<setprecision(15)<<ev(cnt[1],cnt[2],cnt[3])<<endl;

}
