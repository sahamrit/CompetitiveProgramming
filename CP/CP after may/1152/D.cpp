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
#define MAXN (int)(2000+1)
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
pair<ll,bool> dp[MAXN][MAXN];
int main()
{
	fastio;
	int n;cin>>n;
	n*=2;

	dp[n][0]={0,true};
	//the subtree of a node at some depth,balance factor
	//contains edges which will finally make 2n length balance sequence by adding remaining braces
	//this subtree is unique(in terms of the edges not the sequence at nodes)
	//dp[depth][bal] contains the maximum matching of the subtree
	//the maximum matching of a tree contains all parents of leafs
	for(int depth=n-1;depth>=0;depth--){
		for(int bal=0;bal<=depth;bal++){
			bool isfree=false;//is any of subtrees free
			if(bal>=1){
				dp[depth][bal].first=addmod(dp[depth][bal].first,dp[depth+1][bal-1].first);
				isfree|=dp[depth+1][bal-1].second;
			}
			if(bal+1<=n-(depth+1) && bal+1<=n){//balance factor must not exceed the remaining places where we can put ')'
				dp[depth][bal].first=addmod(dp[depth][bal].first,dp[depth+1][bal+1].first);
				isfree|=dp[depth+1][bal+1].second;				
			}
			if(isfree){
				dp[depth][bal].first=addmod(dp[depth][bal].first,1);
				dp[depth][bal].second=false;
			}
			else{
				dp[depth][bal].second=true;
			}
		}
	}
	cout<<dp[0][0].first<<endl;
}
