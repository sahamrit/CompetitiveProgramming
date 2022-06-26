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
vector<int> primes_upto(int n){
    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<bool> is_prime(nsqrt + 1, true);
    for(int i=2; i<=nsqrt; i++)
        if(is_prime[i]){
            primes.push_back(i);
            for(int j=i*i; j<=nsqrt; j+=i)
                is_prime[j] = false;
        }

    int S = nsqrt;
    vector<int> res;
    for(int k = 0; k*S<=n; k++) {
        vector<bool> block(S, true);
        int start = k*S;
        for(int p : primes) {
            int start_idx = (start + p - 1)/p;
            int j = max(start_idx, p)*p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k==0)
            block[0] = block[1] = false;
        for (int i = 0; i<S && start+i<=n; i++)
            if (block[i])
                res.push_back(start + i);
    }
    return res;
}

int main()
{
	fastio;
	int n;cin>>n;
	vi cnt(3,0);
	for(int i=0;i<n;i++){
		int x;cin>>x;
		if(x==1)cnt[1]++;
		else cnt[2]++;
	}
    vi primes = primes_upto(2*n+1);
    vi ans;
    for(int i=0;i<primes.size();i++){
    	int diff;
    	if(i==0)diff=primes[0];
    	else diff=primes[i]-primes[i-1];
    	int twos=diff/2,ones=diff%2;
    	if(twos<=cnt[2] && ones<=cnt[1]){
    		while(twos>0){
    			ans.pb(2);twos--;cnt[2]--;
    		}
    		while(ones>0){
    			ans.pb(1);ones--;cnt[1]--;
    		}
    	}
    	else if(cnt[1]>=diff){
    		while(diff>0){
    			ans.pb(1);diff--;cnt[1]--;
    		}
    	}
    	else break;
    }
    while(cnt[1]>0){
    	ans.pb(1);cnt[1]--;
    }
    while(cnt[2]>0){
    	ans.pb(2);cnt[2]--;
    }
    for(auto u:ans)
    	cout<<u<<" ";
}
