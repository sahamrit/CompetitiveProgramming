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
bool comp(vector<char> &a,vector<char> &b){
	return a.size()>b.size();
}
int dp[260][260][260];
int main()
{
	fastio;
	int n,q;cin>>n>>q;
	vector<char > god(n+1);
	for(int i=1;i<=n;i++)cin>>god[i];
	vector<vi> nxt(n+2,vi(27));
	fill(all(nxt[n+1]),n+1);
	for(int i=n;i>=0;i--){
		for(char c='a';c<='z';c++){
			if(i==n){
				nxt[i][c-'a']=n+1;
			}
			else{
				if(god[i+1]==c)nxt[i][c-'a']=i+1;
				else nxt[i][c-'a']=nxt[i+1][c-'a'];
			}
		}
	}
	vector<vector<char> > religion(4);
	dp[0][0][0]=0;
	while(q--){
		char ch;cin>>ch;
		int sz[4];
		if(ch=='+'){
			int x;cin>>x;cin>>ch;
			religion[x].pb(ch);
			sz[1]=religion[1].size();sz[2]=religion[2].size();sz[3]=religion[3].size();
			for(int i=(x==1?sz[1]:0);i<=sz[1];i++){
				for(int j=(x==2?sz[2]:0);j<=sz[2];j++){
					for(int k=(x==3?sz[3]:0);k<=sz[3];k++){
						dp[i][j][k]=n+1;
						if(i>0)dp[i][j][k]=min(dp[i][j][k],nxt[dp[i-1][j][k]][religion[1][i-1]-'a']);
						if(j>0)dp[i][j][k]=min(dp[i][j][k],nxt[dp[i][j-1][k]][religion[2][j-1]-'a']);
						if(k>0)dp[i][j][k]=min(dp[i][j][k],nxt[dp[i][j][k-1]][religion[3][k-1]-'a']);
					}
				}
			}

		}
		else if(ch=='-'){
			int x;cin>>x;religion[x].pop_back();
		}
		sz[1]=religion[1].size();sz[2]=religion[2].size();sz[3]=religion[3].size();
		if(dp[sz[1]][sz[2]][sz[3]]<=n)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;		
	}
}
