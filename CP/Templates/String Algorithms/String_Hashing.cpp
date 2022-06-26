#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define llu unsigned long long
#define ld long double
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define vi vector < int >
#define vll vector < ll >
#define pb push_back
#define pf push_front
#define iter :: iterator
#define pii pair < int , int >
#define pll pair < ll, ll >
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'
#define all(x) x.begin(),x.end()
#define foreach(it,v) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
#define present(v,x) (v).find(x) != (v).end()
#define cpresent(v,x) (find(all(v),x) != (v).end())
#define mset(x,v) memset(x, v, sizeof(x))
#define sz(x) (int)x.size()
#define shout()  {cout << "I'm Here...!!!" << endl;}
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }

inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int addmod(int a, int val, int p = MOD) {{if ((a = (a + val)) >= p) a -= p;} return a;}
inline int submod(int a, int val, int p = MOD) {{if ((a = (a - val)) < 0) a += p;}return a;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}

ll compute_hash(string const &s){
	const int p = 31;
	const int m = 1e9 + 9;
	ll hash_value = 0;
	ll p_pow = 1;
	for(char c: s){
		hash_value = (hash_value + (c-'a'+1)*p_pow) % m;
		p_pow = (p_pow*p)%m;
	}
	return hash_value;
}

vector<vector<int> > group_identical_strings(vector<string> const&s){
	int n = s.size();
	vector<pair<ll, int> > hashes(n);
	for(int i=0; i<n; i++)
		hashes[i] = {compute_hash(s[i]), i};

	sort(all(hashes));

	vector<vector<int>> groups;

	for(int i=0; i<n; i++){
		if(i==0 or hashes[i].ff != hashes[i-1].ff)
			groups.emplace_back();
		groups.back().push_back(hashes[i].ss);
	}

	return groups;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	

	return 0;
}