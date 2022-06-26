#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
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
#define ones first
#define sz second
ld f;
bool comp(pii a,pii b)
{
	return a.ones - f*a.sz > b.ones -f*b.sz ;
}
int main()
{
	//fastio;
 	freopen("input.in", "r", stdin);
 	freopen("output1.txt", "w", stdout);
	ll n;
	int t,N;
	cin>>t;
	N=t;
	while(t--)
	{
		cin>>n>>f;
		vector <pii> prefix(n+1);
		int ctr=0;
		string s;cin>>s;
		prefix[0]=mp(0,0);
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='1')ctr++;
			prefix[i]=mp(ctr,i);
			
		}
		//cout<<n<<" "<<f<<endl;
		//cout<<s<<endl;		
		if(n==1)
		{
			cout<<"Case #"<<N-t<<": "<<0<<endl;
			continue;
		}
		sort(prefix.begin(),prefix.end(),comp);
		ld ans;int idx;
		ans=(prefix[1].ones -(ld)prefix[0].ones)/(prefix[1].sz - (ld)prefix[0].sz);
		idx=min(prefix[0].sz,prefix[1].sz);
		for(int i=1;i<n;i++)
		{
			ld temp;
			temp=(prefix[i+1].ones -(ld)prefix[i].ones)/(prefix[i+1].sz - (ld)prefix[i].sz);
			if(fabs(temp-f)==fabs(ans-f))
			{
				idx=min(idx,min(prefix[i].sz,prefix[i+1].sz));
			}
			else if(fabs(temp-f)<fabs(ans-f))
			{
				ans=temp;
				idx=min(prefix[i].sz,prefix[i+1].sz);
				
			}
		}
		cout<<"Case #"<<N-t<<": "<<idx<<endl;

	}
}
