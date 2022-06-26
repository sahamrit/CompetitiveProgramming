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
#define MAXN (int)(2e5+1)
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
int parent[MAXN],size[MAXN];
int find_set(int a){
	if(a==parent[a])return a;
	return parent[a]=find_set(parent[a]);
}
void merge_set(int a,int b){
	a=find_set(a);
	b=find_set(b);
	if(a==b)return;
	if(size[a]>size[b]){
		parent[b]=a;
		size[a]+=size[b];
	}
	else{
		parent[a]=b;
		size[b]+=size[a];
	}
}

int main()
{
	fastio;
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		parent[i]=i;
		size[i]=1;
	}
	vector<tuple<int,int,int> >edges(m);
	for(int i=0;i<m;i++){
		cin>>get<1>(edges[i])>>get<2>(edges[i])>>get<0>(edges[i]);
	}
	sort(all(edges));
	ll ans=0;
	for(int i=0;i<m;i++){
		int a,b,w;w=get<0>(edges[i]);a=get<1>(edges[i]);b=get<2>(edges[i]);
		vector<pll> v;
		v.pb(mp(a,b));
		int j=i+1;
		while(j<m && w==get<0>(edges[j])){
			v.pb(mp(get<1>(edges[j]),get<2>(edges[j])));
			j++;
		}
		i=j-1;
		vector<pll> good;
		for(auto p:v){
			if(find_set(p.first)!=find_set(p.second))good.pb(p);
		}	
		for(auto p:good){
			int x,y;x=find_set(p.first);y=find_set(p.second);
			if(x!=y)merge_set(x,y);
			else ans++; 
		}
	}
	cout<<ans<<endl;
}
