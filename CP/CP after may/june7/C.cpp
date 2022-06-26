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
#define MAXN (int)(1e3+5)
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
int complete[MAXN];
int status[MAXN];
int process[102];
int interest[MAXN];
int main()
{
	fastio;
	int n,k;cin>>n>>k;
	queue<int>q;
	for(int i=1;i<=n;i++){
		cin>>complete[i];q.push(i);
	}
	for(int i=1;i<=k;i++){
		if(!q.empty()){
			process[i]=q.front();
			q.pop();
		}
	}
	int m=0,ans=0;
	//process t to t+1 second
	while(1){
		if(m==n)break;
		int percent=round(100.0*((ld)m/n));
		for(int i=1;i<=k;i++){
			if(!process[i])continue;
			status[process[i]]++;
			if(status[process[i]]==percent)interest[process[i]]=1;
		}
		for(int i=1;i<=k;i++){
			if(!process[i])continue;
			if(status[process[i]]==complete[process[i]]){
				m++;
				if(!q.empty()){
					process[i]=q.front();q.pop();
				}
				else process[i]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(interest[i]==1)ans++;
	}
	cout<<ans<<endl;
}
