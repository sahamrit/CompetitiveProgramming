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
#define MAXN (int)(2e5+5)
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
vi cnt(MAXN,0);
int main()
{
	fastio;int n;cin>>n;
	vll a(n+1);
	for(int i=1;i<=n;i++){cin>>a[i];cnt[a[i]]++;}
	int val=a[1],maxi=cnt[a[1]];
	for(int i=0;i<MAXN;i++){
		if(cnt[i]>maxi){
			maxi=cnt[i];val=i;
		}
	}	
	ll seglen=1;
	ll first,second;
	for(int i=1;i<=n;i++){
		if(a[i]!=val)continue;
		int l=i,r=i+1;
		while(r<=n && a[l]==a[r]){
			r++;
		}
		r--;
		i=r;
		if(seglen<=r-l+1){
			seglen=r-l+1;
			first=l;second=r;
		}
	}
	ll l=first,r=second;
	vector<pair<int,pii>> ans;
	for(int i=l-1;i>=1;i--){
		if(a[i]>a[l]){
			ans.pb({2,{i,i+1}});
		}
		else if(a[i]<a[l]){
			ans.pb({1,{i,i+1}});
		}
	}
	for(int i=r+1;i<=n;i++){
		if(a[i]>a[r]){
			ans.pb({2,{i,i-1}});
		}
		else if(a[i]<a[r]){
			ans.pb({1,{i,i-1}});
		}
	}
	cout<<ans.size()<<endl;
	for(auto u:ans){
		cout<<u.first<<" "<<u.second.first<<" "<<u.second.second<<endl;
	}	
}
