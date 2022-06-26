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
vi one[27],two[27];
int cntone[27],cnttwo[27];
int main()
{
	fastio;
	int n;cin>>n;
	string lft,rt;
	cin>>lft>>rt;
	for(int i=0;i<n;i++){
		if(lft[i]=='?'){one[26].pb(i);cntone[26]++;}
		else {one[lft[i]-'a'].pb(i);cntone[lft[i]-'a']++;}
		if(rt[i]=='?'){two[26].pb(i);cnttwo[26]++;}
		else {two[rt[i]-'a'].pb(i);cnttwo[rt[i]-'a']++;}		
	}
	int ans=0;vector<pii> res;
	for(int i=0;i<26;i++){
		int mini=min(cntone[i],cnttwo[i]);
		for(int j=1;j<=mini;j++){
			res.pb({one[i].back(),two[i].back()});
			one[i].pop_back();two[i].pop_back();
		}
		ans+=mini;
		cntone[i]-=mini;cnttwo[i]-=mini;
	}
	
	
	for(int i=0;i<26;i++){
		int mini=min(cnttwo[i],cntone[26]);
		for(int j=1;j<=mini;j++){
			res.pb({one[26].back(),two[i].back()});
			two[i].pop_back();one[26].pop_back();
		}
		ans+=mini;
		cnttwo[i]-=mini;cntone[26]-=mini;
	}


	for(int i=0;i<26;i++){
		int mini=min(cntone[i],cnttwo[26]);
		for(int j=1;j<=mini;j++){
			res.pb({one[i].back(),two[26].back()});
			one[i].pop_back();two[26].pop_back();
		}
		ans+=mini;
		cntone[i]-=mini;cnttwo[26]-=mini;
	}

	int mini=min(cntone[26],cnttwo[26]);ans+=mini;
	for(int i=1;i<=mini;i++){
		res.pb({one[26].back(),two[26].back()});
		one[26].pop_back();two[26].pop_back();
	}
	cout<<ans<<endl;
	for(auto p:res){
		cout<<p.first+1<<" "<<p.second+1<<endl;
	}

}
