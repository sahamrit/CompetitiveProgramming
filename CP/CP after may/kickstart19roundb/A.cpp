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
vector<char> s(MAXN);
int t[4*MAXN][26];
void buildSeg(int v, int tl, int tr){
	if(tl==tr){
		for(int i=0;i<26;i++){
			if(s[tr]-'A'==i)t[v][i]=1;
			else t[v][i]=0;
		}
	}		
	else{
		int tm = (tl + tr)/2;
		buildSeg(v*2, tl, tm);
		buildSeg(v*2+1, tm+1, tr);
		//operation in the segment tree
		for(int i=0;i<26;i++){
			t[v][i]=t[2*v][i]+t[2*v+1][i];
		}
	}
}
vector<int> querySeg(int v, int tl, int tr, int l, int r){
	if(l>r)
		return vector<int>(26,0);
	if(l==tl and r==tr)
		{
			vector<int>cnt(26,0);
			for(int i=0;i<26;i++)cnt[i]=t[v][i];
			return cnt;	
		}
	int tm = (tl + tr)/2;
	vi cnt1=querySeg(v*2, tl, tm, l, min(r, tm));
	vi cnt2=querySeg(v*2+1, tm+1, tr, max(l, tm+1), r);
	vi res(26,0);
	for(int i=0;i<26;i++)res[i]=cnt1[i]+cnt2[i];
	return res;	
}

int main()
{
	fastio;
	int t;cin>>t;
	int N=t;
	while(t--){
		int n,q;cin>>n>>q;
		for(int i=1;i<=n;i++)cin>>s[i];
		buildSeg(1,1,n);
		ll ans=0;
		for(int i=1;i<=q;i++){
			int l,r;cin>>l>>r;
			vi cnt=querySeg(1,1,n,l,r);
			int odd=0;
			for(int i=0;i<26;i++)if(cnt[i]%2)odd++;
			if(odd<=1)ans++;	
		}
		cout<<"Case #"<<N-t<<": "<<ans<<endl;
	}
}
