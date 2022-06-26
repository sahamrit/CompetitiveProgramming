#include <bits/stdc++.h>
using namespace std;
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
int n;
int bsrchrow(int row)
{
	int l=1,r=n;
	//during while loop head/tail idx lies in [l,r]
	//if mid is >=head/tail column idx ans will be odd;hence we check with r=mid bcz idx can be in [l,mid] 
	//elseif mid is less than head/tail idx ans will be even and hence l will be mid+1 
	while(l<r)
	{
		int mid=(l+r)/2;
		cout<<"? "<<row<<" "<<l<<" "<<row<<" "<<mid<<endl;
		int q;cin>>q;
		if(q%2)r=mid;
		else l=mid+1;
	}
	return l;
}
int bsrchcol(int col)
{
	int l=1,r=n; 
	while(l<r)
	{
		int mid=(l+r)/2;
		cout<<"? "<<l<<" "<<col<<" "<<mid<<" "<<col<<endl;
		int q;cin>>q;
		if(q%2)r=mid;
		else l=mid+1;
	}
	return l;
}
int main()
{
	fastio;cin>>n;
	//query rows first
	vi v;
	for(int i=1;i<=n;i++)
	{
		cout<<"? "<<i<<" "<<1<<" "<<i<<" "<<n<<endl;
		int x;cin>>x;
		if(x%2)v.pb(i);
	}
	if(v.size()==0)//head tail in same row
	{
		for(int i=1;i<=n;i++)//query columns
		{
			cout<<"? "<<1<<" "<<i<<" "<<n<<" "<<i<<endl;
			int x;cin>>x;
			if(x%2)v.pb(i);
		}
		int r1=bsrchcol(v[0]);
		cout<<"! "<<r1<<" "<<v[0]<<" "<<r1<<" "<<v[1]<<endl;		
	}
	else //head tail in diff row v[0] && v[i]
	{
		int c1=bsrchrow(v[0]);
		int c2=bsrchrow(v[1]);
		cout<<"! "<<v[0]<<" "<<c1<<" "<<v[1]<<" "<<c2<<endl;
	}

}
