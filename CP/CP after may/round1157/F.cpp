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
int main()
{
	fastio;
	int n,l,r,l1,r1;cin>>n;
	vi a(n),cnt(MAXN,0);
	set<int>s;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		s.insert(a[i]);
		cnt[a[i]]++;
	}
	a.clear();
	for(auto x:s)
	{
		a.pb(x);
	}
	l=0,r=0;
	int ans=cnt[a[0]],sum;
	int sz=a.size();
	for(int i=0;i<sz;i++)
	{
		sum=0;
		sum+=cnt[a[i]];
		l1=i;int j=i+1;
		while(j<sz && a[j]-a[j-1]==1 && cnt[a[j]]>1)
		{
			sum+=cnt[a[j]];
			j++;
		}
		r1=j-1;
		if(j<sz && a[j]-a[j-1]==1)
		{
			sum+=cnt[a[j]];
			r1=j;
		}
		if(ans<sum)
		{
			ans=sum;
			l=l1;
			r=r1;
		}
		i=max(i,r1-1);
	}
	cout<<ans<<endl;
	for(int i=0;i<cnt[a[l]];i++)
		cout<<a[l]<<" ";
	for(int i=l+1;i<r;i++)
	{
		for(int j=0;j<cnt[a[i]]-1;j++)
			cout<<a[i]<<" ";
	}
	if(l!=r)
	for(int i=0;i<cnt[a[r]];i++)
		cout<<a[r]<<" ";
	for(int i=r-1;i>l;i--)
		cout<<a[i]<<" ";


}
