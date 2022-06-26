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
bool is_digit(char x){
	return x-'0'>=0 && x-'0'<=9;
}
int conv(char x){
	if(is_digit(x))return x-'0';
	return x-'A'+10;
}
int main()
{
	fastio;int n;cin>>n;
	vector<vi > arr(n,vi(n));
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<n;j++){
			arr[i][j]=((conv(s[j/4]))>>(3-j%4))&1;
		}
	}
	vector<vi > sum(n+1,vi(n+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+arr[i-1][j-1];
		}
	}
	bool check=true;
	for(int x=n;x>=1;x--){
		if(n%x)continue;
		check=true;
		for(int i=1;i<=n;i+=x){
			for(int j=1;j<=n;j+=x){
				int currsum=sum[i+x-1][j+x-1]+sum[i-1][j-1]-sum[i+x-1][j-1]-sum[i-1][j+x-1];
				if(currsum!=0 && currsum!=x*x){
					check=false;break;
				} 
			}
			if(!check)break;
		}
		if(check){
			cout<<x<<endl;return 0;
		}
	}
}
