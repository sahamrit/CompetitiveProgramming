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
#define MAXN (int)(2e3+1)
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
char cmp[MAXN][MAXN];
vector < int > parent(MAXN, -1);
vector <int > size(MAXN,1);
vector<bool> visited(MAXN,false);
vector<int> adj[MAXN];
vector<int>ans;bool check=true;
vector<int> score(MAXN,0),color(MAXN,0);
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
void dfs(int v){
	visited[v]=true;
	color[v]=1;
	score[v]=1;
	for(auto u:adj[v]){
		if(visited[u]){
			if(color[u]==1 || find_set(u)==find_set(v)){
				check=false;return;
			}
			score[v]=max(score[v],score[u]+1);
			continue;
		}
		dfs(u);
		score[v]=max(score[v],score[u]+1);
	}
	color[v]=2;
}
int main()
{
	fastio;
	int n,m;cin>>n>>m;
	for(int i=0;i<n+m;i++)make_set(i);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>cmp[i][j];
			if(cmp[i][j]=='=')union_sets(i,j+n);
		}
	}
	for(int i=0;i<n+m;i++){
		parent[i]=find_set(i);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(cmp[i][j]=='>'){
				if(parent[i]!=parent[n+j])
					adj[parent[i]].pb(parent[n+j]);
				else{
					cout<<"No"<<endl;return 0;
				}
			}
			else if(cmp[i][j]=='<')
				if(parent[i]!=parent[n+j])
					adj[parent[n+j]].pb(parent[i]);
				else{
					cout<<"No"<<endl;return 0;
				} 
		}
	}
	for(int i=0;i<n+m;i++){
		if(!visited[parent[i]])
			dfs(parent[i]);
	}
	if(!check)cout<<"No"<<endl;
	else{
		
		for(int i=0;i<n+m;i++){
			score[i]=score[parent[i]];
		}
		cout<<"Yes"<<endl;
		for(int i=0;i<n;i++)cout<<score[i]<<" ";
		cout<<endl;
		for(int i=n;i<n+m;i++)cout<<score[i]<<" ";
		cout<<endl;	
	}

}
