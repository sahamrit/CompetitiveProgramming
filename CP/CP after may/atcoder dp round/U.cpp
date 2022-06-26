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
#define MAXN (int)(20)
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
ll dp[1<<MAXN];
vll pre;
ll a[MAXN][MAXN];
void solve(int i,vi &not_cons,int mask,ll score,int curr_grp)
{
	if(i==not_cons.size())
	{
		dp[mask]=max(dp[mask],score+pre[curr_grp]);
		return;
	}
	int curr_bit=(1<<not_cons[i]);
	solve(i+1,not_cons,mask,score,curr_grp);
	solve(i+1,not_cons,mask^(curr_bit),score,curr_grp^(curr_bit));
}
//dp[mask]-max score if we have grouped rabbits in mask 
//this can be obtained from considering masks st
//some of bits of mask are turned off dp[mask'] and we group the remaining bits
//since mask' is less than mask we would have its answer 
int main()
{
	fastio;
	int n;cin>>n;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			cin>>a[i][j];
		}
	}
	pre.resize(1<<n);
	//O(2^n * n^2)
	for(int i=0;i<(1<<n);++i)//i is the mask
	{
		for(int j=0;j<n;++j)
		{	
			if(i&(1<<j))
			for(int k=j+1;k<n;++k)
			{
				if((i&(1<<k)))
					pre[i]+=a[j][k];
			}
		}
	}
	dp[0]=0;
	vi not_cons;
	//O(2^n*n + 3^n)
	for(int mask=0;mask<(1<<n);++mask)
	{
		not_cons.clear();
		for(int i=0;i<n;i++)
		{
			if(!(mask & (1<<i)))
				not_cons.pb(i);
		}
		solve(0,not_cons,mask,dp[mask],0);
	}
	cout<<dp[(1<<n)-1]<<endl;


}
