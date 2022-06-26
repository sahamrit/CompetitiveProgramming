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
inline ll fpow(ll n, ll k, ll p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
inline ll inv(ll a, ll p = MOD) {return fpow(a, p - 2, p);}
inline ll addmod(ll a, ll val, ll p = MOD) {{if ((a = (a + val)) >= p) a -= p;} return a;}
inline ll submod(ll a, ll val, ll p = MOD) {{if ((a = (a - val)) < 0) a += p;}return a;}
inline ll mult(ll a, ll b, ll p = MOD) {return (ll) a * b % p;}
//DEBUG
#define shout()  {cout << "I'm Here...!!!" << endl;}
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
int edit_distance(string &a,string &b,bool swap=false,int c_in=1,int c_swap=1,int c_sub =1){
	int n,m;
	n=a.size();m=b.size();
	vector<vi> dp(n+1,vi(m+1,INT_MAX));
	for(int i=0;i<=m;i++)dp[0][i]=i;
	for(int i=0;i<=n;i++)dp[i][0]=i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}
			else{
				
				dp[i][j]=min(c_sub+dp[i-1][j-1],min(c_in+dp[i-1][j],c_in+dp[i][j-1]));
				if(swap){
					if((j-2>=0 && a[i-1]==b[j-2])&& (i-2>=0 && a[i-2]==b[j-1])){
						dp[i][j]=min(dp[i][j],dp[i-2][j-2]+c_swap);
					}
				}
			}
		}
	}
	return dp[n][m];	
}
int main()
{
	fastio;
	int t;cin>>t;
	while(t--){
		string a,b;cin>>a>>b;
		cout<<edit_distance(a,b,false,1,1,1)<<endl;
	}
}
