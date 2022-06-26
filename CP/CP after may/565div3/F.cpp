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
#define MAXN (int)(2e5+5)
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
ll dp[MAXN][10];
int main()
{
	fastio;
	int n;cin>>n;
	for(int i=1;i<=9;i++)dp[0][i]=LLONG_MIN;
	for(int i=0;i<n;i++){
		int k;cin>>k;
		vll one,two,three;
		for(int j=0;j<=9;j++)dp[i+1][j]=dp[i][j];
		for(int j=0;j<k;j++){
			int x,y;cin>>x>>y;
			if(x==1)one.pb(y);
			else if(x==2)two.pb(y);
			else three.pb(y);
		}
		sort(one.rbegin(),one.rend());
		sort(two.rbegin(),two.rend());	
		sort(three.rbegin(),three.rend());
		for(int j=0;j<10;j++){				
					if(three.size()>0){
						if(j+1>=10)
						dp[i+1][(j+1)%10]=max(dp[i+1][(j+1)%10],dp[i][j]+2*three[0]);
						else dp[i+1][(j+1)%10]=max(dp[i+1][(j+1)%10],dp[i][j]+three[0]);
					}
					if(two.size()>0){
						if(j+1>=10)
						dp[i+1][(j+1)%10]=max(dp[i+1][(j+1)%10],dp[i][j]+2*two[0]);
						else dp[i+1][(j+1)%10]=max(dp[i+1][(j+1)%10],dp[i][j]+two[0]);
					}
					if(one.size()>0){
						if(j+1>=10)
						dp[i+1][(j+1)%10]=max(dp[i+1][(j+1)%10],dp[i][j]+2*one[0]);
						else 
						dp[i+1][(j+1)%10]=max(dp[i+1][(j+1)%10],dp[i][j]+one[0]);	

					}
					if(one.size()>=3){
						if(j+3>=10)
						dp[i+1][(j+3)%10]=max(dp[i+1][(j+3)%10],dp[i][j]+2*one[0]+one[1]+one[2]);
						else dp[i+1][(j+3)%10]=max(dp[i+1][(j+3)%10],dp[i][j]+one[0]+one[1]+one[2]);
					}
				
				
					if(one.size()>0 && two.size()>0){
						ll maxi=max(one[0],two[0]),mini=min(one[0],two[0]);
						if(j+2>=10)
						dp[i+1][(j+2)%10]=max(dp[i+1][(j+2)%10],dp[i][j]+2*maxi+mini);
						else
						dp[i+1][(j+2)%10]=max(dp[i+1][(j+2)%10],dp[i][j]+maxi+mini); 						

					}
					if(one.size()>1){
						if(j+2>=10)
						dp[i+1][(j+2)%10]=max(dp[i+1][(j+2)%10],dp[i][j]+2*one[0]+one[1]);
						else 
						dp[i+1][(j+2)%10]=max(dp[i+1][(j+2)%10],dp[i][j]+one[0]+one[1]);	
					}
				
			
		}	
	}
	ll ans=0;
	for(int i=0;i<10;i++)ans=max(ans,dp[n][i]);
	cout<<ans<<endl;	
}