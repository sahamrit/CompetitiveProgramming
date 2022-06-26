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
#define MOD (int)(1e9+7)
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
void multiply(vector<vll>&a,vector<vll>&b){
	int m=a.size();
	vector<vll> c(m,vll(m,0));
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<m;k++){
				c[i][j]=addmod(c[i][j],mult(a[i][k],b[k][j]));
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			a[i][j]=c[i][j];
		}
	}
}
void pow(vector<vll>&res,vector<vll>&a,ll n){
	if(n==1)return;
	pow(res,a,n/2);
	multiply(res,res);
	if(n%2)multiply(res,a);
}
int main()
{
	fastio;
	ll n,m;cin>>n>>m;
	vector<vll> a(m,vll(m,0));
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(i==j+1)a[i][j]=1;
		}
	}
	a[0][0]=1;a[0][m-1]=1;
	vector<vll>res=a;
	pow(res,a,n);
	cout<<res[0][0]<<endl;
}
