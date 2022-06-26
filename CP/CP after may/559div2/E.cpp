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
void dfs(int v,vi adj[],vector<bool>&visited,int &ctr,vi&p){
	visited[v]=true;
	for(auto u:adj[v]){
		if(visited[u])continue;
		dfs(u,adj,visited,ctr,p);
	}
	if(!p[v])
	p[v]=ctr--;
}
int main()
{
	fastio;
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vi p(n+2,0),next(n+1);
		vi pos(n+1);
		vector<bool> hasnext(n+1,false),visited(n+1,false);
		vi adj[n+1]; 
		int ctr=n;
		for(int i=1;i<=n;i++){
			cin>>next[i];
			if(next[i]!=-1 && next[i]!=n+1){
				hasnext[i]=true;
				adj[i].pb(next[i]);
			}
			if(next[i]==n+1){
				p[i]=ctr--;
			}
		}
		for(int i=1;i<=n;i++){
			if(!visited[i] && hasnext[i])dfs(i,adj,visited,ctr,p);
		}
		for(int i=1;i<=n;i++){
			if(p[i]==0 && ctr>0){
				p[i]=ctr--;
			}
		}
		for(int i=1;i<=n;i++)pos[p[i]]=i;
		bool check=true;
		p[n+1]=n+1;
		stack<pii> s;
		s.push(mp(n+1,n+1)); 
		for(int i=n;i>=1;i--){
			if(next[i]==-1){
				s.push(mp(p[i],i));continue;
			}
			auto it=s.top();
			while(it.first<p[i]){
				s.pop();
				it=s.top();
			}
			s.push(mp(p[i],i));
			if(it.second!=next[i]){
				check=false;break;
			}
		}
		if(check){
			for(int i=1;i<=n;i++)cout<<p[i]<<" ";
		}
		else cout<<-1;
		cout<<endl;	

	}
}
