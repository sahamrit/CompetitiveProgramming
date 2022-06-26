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
	vector<char> clown(n+1),acrobat(n+1);
	vi first,second,third,fourth;
	for(int i=1;i<=n;i++)cin>>clown[i];
	for(int i=1;i<=n;i++)cin>>acrobat[i];
	int x=0,y=0,z=0,w=0;
	for(int i=1;i<=n;i++){
		if(clown[i]=='0' && acrobat[i]=='0'){x++;first.pb(i);}
		else if(clown[i]=='0' && acrobat[i]=='1'){y++;second.pb(i);}
		else if(clown[i]=='1' && acrobat[i]=='0'){z++;third.pb(i);}
		else {w++;fourth.pb(i);}
	}
	int a,b,c,d;	
	bool check=false;
	for(int i=0;i<n/2+1;i++){
		for(int j=0;j<n/2+1;j++){
			b=i;d=j;
			c=y+w-b-2*d;
			a=n/2-b-c-d;
			if(a>=0 && b>=0 && c>=0 && d>=0 && b<=y && d<=w && a<=x && c<=z){
				check=true;break;
			}
		}
		if(check)break;
	}
	if(!check)cout<<-1<<endl;
	else{
		for(int i=0;i<a;i++)cout<<first[i]<<" ";
		for(int i=0;i<b;i++)cout<<second[i]<<" ";
		for(int i=0;i<c;i++)cout<<third[i]<<" ";
		for(int i=0;i<d;i++)cout<<fourth[i]<<" ";	
	}		
}
