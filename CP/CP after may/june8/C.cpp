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
	int n;cin>>n;int cnt=0,firstone=-1;
	vi pile(n+1),hand(n+1);
	for(int i=1;i<=n;i++)cin>>hand[i];
	for(int i=1;i<=n;i++){cin>>pile[i];if(pile[i]==1)firstone=i;}

	if(firstone!=-1){
		bool checker=true;
		for(int i=firstone;i<n;i++){
			if(pile[i]+1!=pile[i+1]){checker=false;break;}
		}
		if(checker){
			vi num(n+1,0);queue<int> q;
			int cnt=0;
			for(int i=1;i<=n;i++)num[hand[i]]++;
			for(int i=1;i<firstone;i++)q.push(pile[i]);
			for(int i=pile[n]+1;i<=n;i++){
				if(num[i]>0){
					num[q.front()]++;num[i]--;
					q.pop();cnt++;
				}
				else {checker=false;break;}
			}
			if(checker){cout<<cnt<<endl;return 0;}	
		}
	}
	for(int i=n;i>=1;i--){
		if(pile[i]==0)cnt++;
		else break;
	}
	int l=0,r=n-cnt;
	while(l<r){
		int mid=(l+r)/2;
	//	cout<<l<<" "<<r<<" "<<mid<<endl;
		queue<int>q;
		vi num(n+1,0);
		for(int i=1;i<=n;i++){
			num[hand[i]]++;
			if(i>=mid+1)q.push(pile[i]);
		}
		for(int i=1;i<=mid;i++){num[pile[i]]++;num[0]--;}
		bool check=true;
		for(int i=1;i<=n;i++){
			if(num[i]>0){
				num[q.front()]++;num[i]--;
				q.pop();
				q.push(i);
			}
			else {
				check=false;break;
			}
		}
		if(check)r=mid;
		else l=mid+1;	
	}
	cout<<l+n<<endl;	
}
