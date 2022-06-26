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
void computeLPSArray(string& pat, vector < int > &lps) { 
    int i = 1, len = 0, M = pat.size();  
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else 
            if (len != 0)
                len = lps[len - 1]; 
            else{ 
                lps[i] = 0; 
                i++; 
            } 
    } 
} 
int cnt[2],cntpat[2];

int main()
{
	fastio;
	string s,pat;
	cin>>s>>pat;
	int M=pat.size();
	vector<int>lps(M);
	computeLPSArray(pat,lps);
	for(int i=0;i<(int)s.size();i++){
		if(s[i]=='0')cnt[0]++;
		else cnt[1]++;
	}
	for(int i=0;i<(int)pat.size();i++){
		if(pat[i]=='0')cntpat[0]++;
		else cntpat[1]++;
	}	
	if(cnt[0]<cntpat[0] || cnt[1]<cntpat[1]){
		cout<<s<<endl;return 0;
	}
	vector<char>ans;
	for(int i=0;i<M;i++){
		ans.pb(pat[i]);cnt[pat[i]-'0']--;
	}
	bool check=true;
	while(check){
		int j=lps[M-1];
		for(int i=j;i<M;i++){
			if(cnt[pat[i]-'0']){
				ans.pb(pat[i]);cnt[pat[i]-'0']--;
			}
			else{
				check=false;break;
			}
		}
	}
	while(cnt[0]!=0 || cnt[1]!=0){
		if(cnt[0]){
			ans.pb('0');cnt[0]--;
		}
		if(cnt[1]){
			ans.pb('1');cnt[1]--;
		}
	}
	for(auto x:ans)
		cout<<x;

}
