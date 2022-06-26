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
ll dp[26],curr[26];
string s;
int n,q;
void solve(ll *f){//max substring of equal char for each char
	for(int i=0;i<26;i++)f[i]=0;
	int sz=1;f[s[0]-'a']=1;	
	for(int i=1;i<n;i++){
		ll now;
		if(s[i]==s[i-1])now=sz+1;
		else now=1;
		sz=now;
		f[s[i]-'a']=max(f[s[i]-'a'],now);
	}	
}
int main()
{
	fastio;
	cin>>q;	cin>>s;n=s.size();solve(dp);
	while(--q){
		cin>>s;n=s.size();
		bool check=true;
		for(int i=1;i<n;i++){
			if(s[i]!=s[i-1]){check=false;break;}
		}
		if(check){//all same
			int ch=s[0]-'a';
			for(int i=0;i<26;i++)
				if(ch!=i && dp[i])dp[i]=1;
				dp[ch]=dp[ch]+(dp[ch]+1)*n;
		}
		else//all are not same
		{
			solve(curr);
			int cntl=1,cntr=1,l=0,r=n-1;
			while(s[l]==s[l+1]){cntl++;l++;}
			while(s[r]==s[r-1]){cntr++;r--;}
			int head=s[0]-'a',tail=s[n-1]-'a';
			for(int i=0;i<26;i++){
				if(i!=head && i!=tail){
					if(dp[i])dp[i]=1;
					dp[i]=max(dp[i],curr[i]);
				}
			}
			if(head==tail){
				if(dp[head])dp[head]=cntl+cntr+1;
				dp[head]=max(dp[head],curr[head]);
			}
			else{
				if(dp[head])dp[head]=cntl+1;
				dp[head]=max(dp[head],curr[head]);
				if(dp[tail])dp[tail]=cntr+1;
				dp[tail]=max(dp[tail],curr[tail]);
			}
		}
		for(int i=0;i<26;i++)dp[i]=min(dp[i],(ll)(1e9+1));
	}
	ll ans=0;
	for(int i=0;i<26;i++)ans=max(ans,dp[i]);
	cout<<ans<<endl;	

}
