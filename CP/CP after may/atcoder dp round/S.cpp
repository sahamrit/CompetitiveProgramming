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
#define MAXN (int)(101)
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
	string s;
	cin>>s;
	ll len=s.size();
	ll d;cin>>d;
	vector< vll >dp(d,vll(2,0)),newdp(d,vll(2,0));
	//dp[i][sum][less considered]-considering i digits how many possible ways 
	//to get sum of digits so far %d as sum,if any digit has been decreaased or not
	for(ll i=0;i<len;i++)
	{
		if(i==0)
		{
			for(ll digit=0;digit<=(ll)(s[0]-'0');digit++)
			{
				if(digit<(ll)(s[0]-'0'))
				{
					newdp[digit%d][1]=addmod(newdp[digit%d][1],1);
					
				}
				else
				{
					newdp[digit%d][0]=addmod(newdp[digit%d][0],1);

				}
				//cout<<newdp[digit%d][0]<<" "<<newdp[digit%d][1]<<endl;
			}
			dp=newdp;
			continue;
		}
		fill(newdp.begin(),newdp.end(),vll(2,0));
		for(ll sum=0;sum<d;sum++)
		{
			for(ll less_cons=0;less_cons<=1;less_cons++)
			{
				for(ll dig=0;dig<=9;dig++)
				{
					if(dig>(ll)(s[i]-'0') && !less_cons)break;
					newdp[(sum%d +dig%d)%d][less_cons||(dig<(ll)(s[i]-'0')?1:0)]=addmod(newdp[(sum%d +dig%d)%d][less_cons||(dig<(ll)(s[i]-'0')?1:0)],dp[sum][less_cons]);
				}
			}
		}
		dp=newdp;
	}

	ll res=addmod(newdp[0][0],newdp[0][1]);
	res=submod(res,1);
	cout<<res<<endl;

}
