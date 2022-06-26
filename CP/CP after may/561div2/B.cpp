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
int main()
{
	fastio;
	int n,m;cin>>n>>m;
	vector<pii>a(m);
	for(int i=0;i<m;i++){
		cin>>a[i].first>>a[i].second;
	}
	bool check=false;
	int x1=a[0].first,x2=a[0].second;
	set<pii>s;
	for(int i=1;i<m;i++){
		if(a[i].first!=x1 && a[i].second!=x1)s.insert(a[i]);
	}
	auto it=s.begin();
	if(it==s.end()){
		cout<<"YES"<<endl;return 0;
	}
	int y1=(*it).first,y2=(*it).second;
	int ctr1=0,ctr2=0;
	for(auto x:s){
		if(x.first==y1||x.second==y1)ctr1++;
		if(x.first==y2||x.second==y2)ctr2++;
	}
	if(ctr1==s.size()||ctr2==s.size()){
		cout<<"YES"<<endl;return 0;
	}
	s.clear();

	for(int i=1;i<m;i++){
		if(a[i].first!=x2 && a[i].second!=x2)s.insert(a[i]);
	}
	it=s.begin();
	if(it==s.end()){
		cout<<"YES"<<endl;return 0;
	}
	y1=(*it).first;y2=(*it).second;
	ctr1=0,ctr2=0;
	for(auto x:s){
		if(x.first==y1||x.second==y1)ctr1++;
		if(x.first==y2||x.second==y2)ctr2++;
	}
	if(ctr1==s.size()||ctr2==s.size()){
		cout<<"YES"<<endl;return 0;
	}
	cout<<"NO"<<endl;
}
