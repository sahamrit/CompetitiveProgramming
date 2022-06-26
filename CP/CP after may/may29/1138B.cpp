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
	fastio;
	int n;cin>>n;
	vi clown,acrobat,useless,talent;
	string c1,a1;cin>>c1;cin>>a1;
	for(int i=1;i<=n;i++){
		if(c1[i-1]=='1'&& a1[i-1]=='1')talent.pb(i);
		else if(c1[i-1]=='1'&&a1[i-1]=='0')clown.pb(i);
		else if(c1[i-1]=='0'&& a1[i-1]=='1')acrobat.pb(i);
		else useless.pb(i);
	}
	int na,nb,nc,nd;
	na=useless.size();nb=acrobat.size();nc=clown.size();nd=talent.size();
	int a,b,c,d;bool check=false;
	for(int i=0;i<=min(n/2,nb);i++){
		for(int j=0;j<=min(n/2,nc);j++){
			if((nb+nd-i-j)>=0 && (nb+nd-i-j)%2==0){
				int k=(nb+nd-i-j)/2;
				if(n/2-i-j-k>=0){
					b=i;c=j;d=k;a=n/2-b-c-d;
					if(a<=na&&b<=nb&&c<=nc&&d<=nd)
						{check=true;break;}
				}
			}
		}
		if(check)break;
	}
	//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	if(!check){cout<<-1<<endl;return 0;}
	//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	for(int i=0;i<a;i++)cout<<useless[i]<<" ";
	for(int i=0;i<b;i++)cout<<acrobat[i]<<" ";
	for(int i=0;i<c;i++)cout<<clown[i]<<" ";
	for(int i=0;i<d;i++)cout<<talent[i]<<" ";


}
