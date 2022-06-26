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
	int n;
	cin>>n;
	list<int> a;
	for(int i=0;i<n;i++)
	{
		int x;cin>>x;
		a.pb(x);
	}
	vi ans;
	vector<char >step;
	bool check=true;
	while(a.size()!=0 && check)
	{
		check=false;
		int l=a.front();
		int r=a.back();
		if(l<r)
		{
			if(ans.size()==0 ||l>ans[ans.size()-1])
			{
				ans.pb(l);
				step.pb('L');
				a.pop_front();
				check=true;
			}
			else
			{
				if(r>ans[ans.size()-1])
				{
					ans.pb(r);
					step.pb('R');
					a.pop_back();
					check=true;
				}
			}
		}
		else if(l>r)
		{
			if(ans.size()==0 ||r>ans[ans.size()-1])
			{
				ans.pb(r);
				step.pb('R');
				a.pop_back();
				check=true;
			}
			else
			{
				if(l>ans[ans.size()-1])
				{
					ans.pb(l);
					step.pb('L');
					a.pop_front();
					check=true;
				}
			}			
		}
		else
		{
			list <int>temp=a;
			temp.reverse();
			int lscore=0,rscore=0;
			vi fake_ansl=ans,fake_ansr=ans;
			for(auto x:a)
			{
				if(fake_ansl.size()==0 || x>fake_ansl[fake_ansl.size()-1])
				{
					lscore++;
					fake_ansl.pb(x);
				}
				else break;				
			}
			for(auto x:temp)
			{
				if(fake_ansr.size()==0 || x>fake_ansr[fake_ansr.size()-1])
				{
					rscore++;
					fake_ansr.pb(x);
				}
				else break;				
			}
			if(lscore>rscore)
			{
				for(auto x:a)
				{
					if(ans.size()==0 || x>ans[ans.size()-1])
					{
						step.pb('L');
						ans.pb(x);
					}
					else break;				
				}						
			}
			else
			{
				for(auto x:temp)
				{
					if(ans.size()==0 || x>ans[ans.size()-1])
					{
						step.pb('R');
						ans.pb(x);
					}
					else break;				
				}			
			}
			break;			
		}
	}
	cout<<step.size()<<endl;
	for(int i=0;i<step.size();i++)
		cout<<step[i];
}
