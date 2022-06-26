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
#define MAXN (int)(1e6+5)
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
#define start first
#define end second
vi a(MAXN),prefix(MAXN,0),suffix(MAXN,INT_MAX);
vector<pii>idx(MAXN,mp(0,0));
bool check(int l,int r)
{
	if(prefix[l-1]==-1 || suffix[r+1]==-1)return false;	//both invalid	
	if(prefix[l-1]==0 && suffix[r+1]==INT_MAX || prefix[l-1]==0 && suffix[r+1]!=-1 || 
		prefix[l-1]!=-1 && suffix[r+1]==INT_MAX)return true;//both empty or one valid and other empty
	if(prefix[l-1]!=0 && suffix[r+1]!=INT_MAX && prefix[l-1]<suffix[r+1])return true;//both valid 
	return false;	

}
int main()
{
	fastio;
	int n,x;cin>>n>>x;

	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(idx[a[i]].start==0)idx[a[i]].start=i;
		idx[a[i]].end=i;
	}
	//prefix[i]=0 means no occurence of 1toi
	for(int i=1;i<=x;i++){
		if(prefix[i-1]==-1){
			prefix[i]=-1;continue;
		}
		if(idx[i].start==0){
			prefix[i]=prefix[i-1];
		}
		else
		{
			if(idx[i].start>prefix[i-1])
				prefix[i]=idx[i].end;
			else prefix[i]=-1;
		}
	}
	//suffix[i]=INT_MAX means no occurence of i to x
	for(int i=x;i>=1;i--){
		if(suffix[i+1]==-1){
			suffix[i]=-1;continue;
		}
		if(idx[i].start==0){
			suffix[i]=suffix[i+1];
		}
		else{
			if(idx[i].end<suffix[i+1]){
				suffix[i]=idx[i].start;
			}
			else
				suffix[i]=-1;
		}
	}	
	int l=1,r=1;ll ans=0,lastl=0;
	while(l<=x && r<=x)
	{
		int temp=l;
		while(!check(l,r)&&r<=x){
			r++;
		}
		if(r<=x){
			temp=l+1;
			while(temp<=r){
				if(check(temp,r))l=temp;
				temp++;
			}
			ans+=(l-lastl)*(x-r+1);
			lastl=l;
			r++;l=lastl+1;	
		}
	}
	cout<<ans<<endl;
}
