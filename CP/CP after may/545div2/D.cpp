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
int main()
{
	fastio;
	string s,t;
	cin>>s>>t;
	ll cntszero=0,cnttzero=0,cntsone=0,cnttone=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')cntszero++;
		else cntsone++;
	}
	vector<char> ans;
	for(int i=0;i<t.size();i++){
		ans.pb(t[i]);
		if(t[i]=='0')cnttzero++;
		else cnttone++;
	}
	if(cnttone>cntsone || cnttzero>cntszero){
		cout<<s<<endl;
		return 0;
	}
	int M=t.size();
    vector < int > lps(M);
    computeLPSArray(t,lps);
    int i=t.size(),sz=s.size(),j=lps[t.size()-1];
    cntszero-=cnttzero;cntsone-=cnttone;
    while(i<sz){
    	if(t[j]=='1'&&cntsone){
    		j++;i++;ans.pb('1');cntsone--;
    		if(j==t.size())j=lps[t.size()-1];
    	}
    	else if(t[j]=='0'&&cntszero){
    		j++;i++;ans.pb('0');cntszero--;
    		if(j==t.size())j=lps[t.size()-1];
    	}
    	else break;
    }
    while(cntsone){ans.pb('1');cntsone--;}
    while(cntszero){ans.pb('0');cntszero--;}
    for(int i=0;i<ans.size();i++)cout<<ans[i];
}
