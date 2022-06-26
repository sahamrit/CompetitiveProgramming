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
vector<vector<char> >a;
vector<vector<pii> >parent;
vector<vector<int> >size;
pii findset(pii p){
	pii temp=parent[p.first][p.second];
	if(temp.first==p.first && temp.second==p.second)return temp;
	return parent[p.first][p.second]=findset(temp);
}
void mergeset(pii a,pii b){
	a=findset(a);
	b=findset(b);
	if(a.first==b.first && a.second==b.second)return;
	if(size[a.first][a.second]>size[b.first][b.second]){
		parent[b.first][b.second]=a;
		size[a.first][a.second]+=size[b.first][b.second];
	}
	else{
		parent[a.first][a.second]=b;
		size[b.first][b.second]+=size[a.first][a.second];	
	}
}
int main()
{
	fastio;int n;cin>>n;
	int r1,c1,r2,c2;cin>>r1>>c1>>r2>>c2;
	a.resize(n);parent.resize(n);size.resize(n);
	for(int i=0;i<n;i++){
		a[i].resize(n);
		parent[i].resize(n);
		size[i].resize(n);
	}	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			parent[i][j]={i,j};
			size[i][j]=1;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]=='1')continue;
			if(i-1>=0){
				if(a[i-1][j]=='0')mergeset({i,j},{i-1,j});
			}
			if(j-1>=0){
				if(a[i][j-1]=='0')mergeset({i,j},{i,j-1});
			}
		}
	}
	pii leader1,leader2;
	leader1=findset({r1-1,c1-1});
	leader2=findset({r2-1,c2-1});
	if(leader1.first==leader2.first && leader1.second==leader2.second){
		cout<<0<<endl;return 0;
	}
	ll ans=LLONG_MAX;
	vector<pii> one,two;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			pii temp=findset({i,j});
			if(temp.first==leader1.first && temp.second==leader1.second)one.pb({i,j});
			if(temp.first==leader2.first && temp.second==leader2.second)two.pb({i,j});
		}
	}
	for(int i=0;i<one.size();i++){
		for(int j=0;j<two.size();j++){
			pii p1=one[i],p2=two[j];
			ans=min(ans,((ll)p1.first-p2.first)*((ll)p1.first-p2.first)+((ll)p1.second-p2.second)*((ll)p1.second-p2.second));
		}
	}
	cout<<ans<<endl;
}
