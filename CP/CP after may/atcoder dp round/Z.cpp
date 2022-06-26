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

typedef ll ftype;
typedef complex < ftype > point;
#define x real
#define y imag

ftype dot(point a, point b){
	return (conj(a)*b).x();
}

ftype cross(point a, point b){
	return (conj(a)*b).y();
}

vector < point > hull, vecs;

void add_line(ftype k, ftype b){
	point nw = {k, b};

	//Pops those points above the new Lower Convex Hull
	//Assuming when linear functions are added their k only increases
	//Else if k is decreasing 
	// Change '<' to '>' in the inequality in following while loop condition
	while(!vecs.empty() && dot(vecs.back(), nw - hull.back())<0){
		hull.pop_back();
		vecs.pop_back();
	}

	//Pushes the normal vector for last two point in the hull
	if(!hull.empty()){
		point iota = {0, 1};
		vecs.push_back(iota*(nw-hull.back()));
	}

	//Pushes the new  point in the Hull
	hull.push_back(nw);
}

ll get(ftype x) {
    point query = {x, 1};
    auto it = lower_bound(vecs.begin(), vecs.end(), query, [](point a, point b) {
        return cross(a, b) > 0;
    });
    return dot(query, hull[it - vecs.begin()]);
}
ll height[MAXN];
ll dp[MAXN];
int main()
{
	fastio;
	int n;cin>>n;
	ll C;cin>>C;
	for(int i=1;i<=n;i++)
		cin>>height[i];
	for(int i=1;i<=n;i++)
	{
		if(i==1){
			dp[1]=0;
			add_line(height[1],height[1]*height[1]);
			continue;
		}
		ll res;
		res=get(-2*height[i]);
		dp[i]=res+C+height[i]*height[i];
		add_line(height[i],dp[i]+height[i]*height[i]);
	}
	cout<<dp[n]<<endl;
}
