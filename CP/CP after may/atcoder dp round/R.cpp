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
#define MAXN (int)(51)
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
ll n,K;
ll dp[MAXN];
vector< vll > a(MAXN,vll (MAXN));
vector< vll > b(MAXN,vll (MAXN));
vector< vll > F(MAXN,vll (MAXN));
void multiply( vector< vll > &a,vector <vll> &b) 
{
    ll mul[n+1][n+1]; 
    for (int i = 1; i <= n; i++) 
    { 
        for (int j = 1; j <=n; j++) 
        { 
            mul[i][j] = 0; 
            for (int k = 1; k <= n; k++) 
                mul[i][j]=addmod(mul[i][j],mult(a[i][k],b[k][j])); 
        } 
    } 
      for (int i=1; i<=n; i++) 
        for (int j=1; j<=n; j++) 
            a[i][j] = mul[i][j]; 
} 
  
void power( vector < vll > &f,ll n) 
{
	if(n==1)return; 
    power(f,n/2); 
    multiply(f,f); 
    if (n%2 != 0) 
        multiply(f,b); 

} 

int main()
{
	fastio;
	cin>>n>>K;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			b[j][i]=a[i][j];
			F[j][i]=b[j][i];
		}
	}
	for(int i=1;i<=n;i++)
		dp[i]=1;
	ll res=0;
	power(F,K);
	//dp[i][k] number of ways to reach vertex i using k steps
	//=summation dp[j][k-1] provided i is reachable from j

    for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			res=addmod(res,mult(F[i][j],dp[j]));
		}
	}
	cout<<res<<endl;
  	
}
