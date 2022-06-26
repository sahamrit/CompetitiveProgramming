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
#define MAXN (int)(3e5+1)
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
const int bitmax=19;
int dp[MAXN][bitmax+1];//dp[i][j] stores minimum index k such that a[k] has jth bit set and is reachable from i
int last[bitmax+1];//when we traverse numbers from right to left left[j] stores smallest index(grater than current index) which has jth bit set
int main()
{
	fastio;
	int n,q;cin>>n>>q;
	vi a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	//make a virtual last element with all bits set to 1	
	for(int j=0;j<bitmax;j++){
		dp[n][j]=n;
		last[j]=n;
	}	
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<bitmax;j++){
			if((a[i]>>j)&1)
				dp[i][j]=i;
			else dp[i][j]=n;					
		}
		for(int j=0;j<bitmax;j++){
			for(int k=0;k<bitmax;k++){
				if((a[i]>>k)&1){
					dp[i][j]=min(dp[i][j],dp[last[k]][j]);
				}
			}
		}
		for(int j=0;j<bitmax;j++){
			if((a[i]>>j)&1)
				last[j]=i;				
		}		
	}
	while(q--){
		int x,y;cin>>x>>y;x--;y--;
		bool check=false;
		for(int j=0;j<bitmax;j++){
			if((a[y]>>j)&1){
				if(dp[x][j]<=y){
					check=true;
					break;
				}
			}
		}
		if(check)cout<<"Shi"<<endl;
		else cout<<"Fou"<<endl;
	}
}
