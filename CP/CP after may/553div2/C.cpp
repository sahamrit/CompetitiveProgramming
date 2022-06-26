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
pll cntoddeven(ll x){
	ll cntodd=0,cnteven=0;
	ll X=(ll)ceil(log2(x));
	for(ll i=0;i<=X;i++){
		ll power=(ll)pow(2,i);
		if(i%2){
			if(x<power){
				cnteven+=x;
				break;
			}
			else{
				cnteven+=power;
				x-=power;
			}
		}
		else{
			if(x<power){
				cntodd+=x;
				break;
			}
			else{
				cntodd+=power;
				x-=power;
			}
		}
	}
	return mp(cntodd,cnteven);
}
int main()
{
	fastio;
	ll l,r;
	cin>>l>>r;
	ll prefl=0,prefr=0;
	pll cnt;
	if(l>1){
		cnt=cntoddeven(l-1);
		cnt.first=cnt.first%MOD;
		cnt.second=cnt.second%MOD;
		prefl=addmod(prefl,mult(cnt.first,cnt.first));
		prefl=addmod(prefl,mult(cnt.second,addmod(cnt.second,1)));
	}
		cnt=cntoddeven(r);
		cnt.first=cnt.first%MOD;
		cnt.second=cnt.second%MOD;		
		prefr=addmod(prefr,mult(cnt.first,cnt.first));
		prefr=addmod(prefr,mult(cnt.second,addmod(cnt.second,1)));
		cout<<submod(prefr,prefl)<<endl;		
}
