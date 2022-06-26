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
vector<pll >moves={{-1,0},{1,0},{0,-1},{0,1}};
int n,m,p;
bool valid(int x,int y){
	return (x<n && y<m && x>=0 && y>=0);
} 
int main()
{
	fastio;
	cin>>n>>m>>p;
	vll s(p+1);
	for(int i=1;i<=p;i++)cin>>s[i];
	queue<pii >Q[p+1];	
	vector<vector<char> >g(n,vector<char>(m));
	ll lft=n*m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>g[i][j];
			if(g[i][j]-'0'>=1 && g[i][j]-'0'<=p){
				Q[g[i][j]-'0'].push(mp(i,j));
			}
			if(g[i][j]!='.')lft--;
		}
	}
	bool check=true;
	while(check && lft){
		check=false;
		for(int src=1;src<=p;src++){
			for(int steps=1;steps<=s[src];steps++){
				int sz=Q[src].size();
				if(!sz || !lft)break;
				while(sz--){//iterate layers of same distance
					int x,y;
					pii coord=Q[src].front();Q[src].pop();
					x=coord.first;y=coord.second;
					for(int i=0;i<4;i++){// 4 directions from current cell
						int X=moves[i].first+x,Y=moves[i].second +y;
						if(valid(X,Y)&& g[X][Y]=='.'){
							g[X][Y]=src+'0';
							Q[src].push(mp(X,Y));
							lft--;
						}
					}
				}
			}
			if(Q[src].size())check=true;
		}
	}
	vi ans(p+1,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j]-'0'>=1 && g[i][j]-'0'<=p)
			ans[g[i][j]-'0']++;
		}
	}
	for(int i=1;i<=p;i++)
		cout<<ans[i]<<" ";
}
