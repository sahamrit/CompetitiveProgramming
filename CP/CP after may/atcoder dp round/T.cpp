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
#define MAXN (int)(3001)
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
ll dp[MAXN][MAXN],prefix_sum[MAXN];
//dp[i][j]-no of ways to satisfy inequality upto i places with numbers 1 to i and last no j(<=i).
//note to satisfy a inequality of i places any i distinct numbers will have same answer as only comparision matters not value
//so dp[i][j] will be dependent on dp[i-1][k] (k<=i-1)
//in i-1 places any number >=j will be increased by one virtually 
//thus if last number k is <j it will stay same else will be k+1 and then based on ith comparision answer will be decided
char s[MAXN];
int main()
{
	fastio;
	int n,l,r;cin>>n;
	for(int i=1;i<n;i++)cin>>s[i];
	dp[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		memset(prefix_sum,0,sizeof(prefix_sum));
		for(int j=1;j<i;j++)
			prefix_sum[j]=addmod(prefix_sum[j-1],dp[i-1][j]);
		for(int j=1;j<=i;j++)
		{
			if(s[i-1]=='<'){
				l=1;r=j-1;
			}
			else
			{
				l=j;r=i-1;
			}
			if(l>r)continue;
			dp[i][j]=addmod(dp[i][j],submod(prefix_sum[r],prefix_sum[l-1]));	

			/*for(int k=1;k<i;k++)
			{
				int real=k,virt;
				if(real<j)virt=real;
				else virt=real+1;
				if((s[i-1]=='<'&&virt<j)||(s[i-1]=='>'&&virt>j))
				{
					dp[i][j]=addmod(dp[i][j],dp[i-1][k]);
				}
			}*/
		}
	}
	ll res=0;
	for(int i=1;i<=n;i++)
	{
		res=addmod(res,dp[n][i]);
	}	
	cout<<res<<endl;
}