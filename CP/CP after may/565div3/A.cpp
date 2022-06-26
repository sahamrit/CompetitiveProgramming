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

int main()
{
	fastio;ll q;cin>>q;
	while(q--){
		ll n;cin>>n;
		ll x=n;
		ll cnt2=0,cnt3=0,cnt5=0;
		while(x%2==0){
			x/=2;cnt2++;
		}
		x=n;
		while(x%3==0){
			x/=3;cnt3++;
		}
		x=n;
		while(x%5==0){
			x/=5;cnt5++;
		}
		ll divisor=(ll)pow(2,cnt2);
		divisor*=(ll)(pow(3,cnt3));
		divisor*=(ll)(pow(5,cnt5));
		x=n;x/=divisor;
		if(x>1){
			cout<<-1<<endl;continue;
		}		
		ll op1=0,op2=0,op3=0;
		op2=cnt3;op3=cnt5;
		op1=cnt2+op2+2*op3;
		if(op1>=0 && op2>=0 && op3>=0){
			cout<<op1+op2+op3<<endl;
		}
		else cout<<-1<<endl;
	}
}
