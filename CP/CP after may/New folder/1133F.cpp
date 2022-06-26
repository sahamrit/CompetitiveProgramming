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
vector < int > parent(MAXN, -1);
vector <int > size(MAXN,1);

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
	fastio;
	int n,m,D;
	cin>>n>>m>>D;
	set<int> marker;vector<pii>one;vi adj[n+1];
	for(int i=1;i<=n;i++)make_set(i);
	int deg_one=0;	
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		if(x==1 || y==1){
			one.pb({x,y});deg_one++;
		}
		else{
			adj[x].pb(y);adj[y].pb(x);
			union_sets(x,y);
		}
	}
	for(int i=2;i<=n;i++){
		marker.insert(find_set(i));
	}
	if(D>deg_one || marker.size()>D){
		cout<<"NO"<<endl;return 0;
	}
	set<int> s,s1;
	for(auto p:one){
		int a;
		if(p.first==1){
			a=find_set(p.second);
			if(s.find(a)==s.end()){
				s.insert(a);
				s1.insert(p.second);
				adj[p.first].pb(p.second);
				adj[p.second].pb(p.first);
			}
		}
		else{
			a=find_set(p.first);
			if(s.find(a)==s.end()){
				s.insert(a);
				s1.insert(p.first);
				adj[p.first].pb(p.second);
				adj[p.second].pb(p.first);
			}
		}
	}
	int cnt=marker.size();
	for(auto p:one){
		if(cnt==D)break;
		if(p.first==1){
			if(s1.find(p.second)==s1.end()){
				cnt++;
				adj[p.first].pb(p.second);
				adj[p.second].pb(p.first);
			}
		}
		else{
			if(s1.find(p.first)==s1.end()){
				cnt++;
				adj[p.first].pb(p.second);
				adj[p.second].pb(p.first);
			}
		}
	}
	vector<bool> visited(n+1,false);
	queue<int>q;
	visited[1]=true;q.push(1);
	vector<pii> ans;
	while(!q.empty()){
		int v=q.front();q.pop();
		for(auto u:adj[v]){
			if(visited[u])continue;
			ans.pb({u,v});
			visited[u]=true;
			q.push(u);
		}
	}
	cout<<"YES"<<endl;
	for(auto u:ans){
		cout<<u.first<<" "<<u.second<<endl;
	}

}
