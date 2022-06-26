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
#define INF (int)(1e9+7)
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
void kmp_(string &s,vi&kmp,vector<vi >&mtch ){
	int n=s.size();
	kmp[0]=0;
	for(int i=1;i<n;i++){
		int curr=kmp[i-1];
		while(curr>0 && s[curr]!=s[i])
			curr=kmp[curr-1];
		if(s[curr]==s[i])curr++;
		kmp[i]=curr;
	}
	for(int i=0;i<=n;i++){
		for(char c='a';c<='z';c++){
			int curr=i;
			if(i==n)curr=kmp[n-1];
			while(curr>0 && s[curr]!=c)
				curr=kmp[curr-1];
			if(s[curr]==c)curr++;
			mtch[i][c-'a']=curr;
		}
	}
}
int dp[1005][52][52];
int main()
{
	fastio;string code,s,t;
	cin>>code>>s>>t;
	int k=code.size(),n=s.size(),m=t.size();
	vi kmps(n+1),kmpt(m+1);
	vector<vi >mtchs(n+1,vi(26,0));vector<vi >mtcht(m+1,vi(26,0));
	kmp_(s,kmps,mtchs);kmp_(t,kmpt,mtcht);
	memset(dp,-INF,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			for(int l=0;l<=m;l++){
				for(char c='a';c<='z';c++){
					if(code[i]=='*' || code[i]==c){
						int first,second;
						first=mtchs[j][c-'a'];second=mtcht[l][c-'a'];
						dp[i+1][first][second]=max(dp[i+1][first][second],dp[i][j][l]+(first==n)-(second==m));
					}	
				}
			}
		}
	}
   int ans=-INF;
   for(int i=0;i<=n;i++){
   	for(int j=0;j<=m;j++){
   		ans=max(ans,dp[k][i][j]);
   	}
   } 
   cout<<ans<<endl;
}
