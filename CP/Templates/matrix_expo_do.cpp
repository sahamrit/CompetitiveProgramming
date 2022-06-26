#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define llu unsigned long long
#define ld long double
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pf push_front
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'
#define vvi(v, n, m) vector<vi> v(n, vi(m))
#define vvll(v, n, m) vector<vll> v(n, vll(m))
#define all(x) (x).begin(), (x).end()
#define present(v,x) (v).find(x) != (v).end()
#define cpresent(v,x) (find(all(v),x) != (v).end())
#define mset(x,v) memset(x, v, sizeof(x))
#define sz(x) (int)x.size()

string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
void debug_out() { cout << ""; }
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cout << " " << to_string(H); debug_out(T...);}
#define pr(v, n) {for(int j=0; j<n; j++){debug_out(v[j]); if(j<n-1) cout<<",";}}
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); { cout << endl; }
#define dbg1d(v, n) cout << "[" << #v << "]: {"; pr(v, n); {cout << " }" << endl;}
#define dbg2d(v, n, m) cout<<"["<<#v<<"]:"<<endl;{for(int i=0; i<n; i++){cout<<right<<setw(10)<<"["+to_string(i)+"] {";pr(v[i],m);{cout<<" }"<<endl;}}}
#define shout()  {cout << "I'm Here...!!!" << endl;}

inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int addmod(int a, int val, int p = MOD) {{if ((a = (a + val)) >= p) a -= p;} return a;}
inline int submod(int a, int val, int p = MOD) {{if ((a = (a - val)) < 0) a += p;}return a;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}

struct Matrix {
    static const int MAXN = 50; // Set Size of Matrix
    int x[MAXN][MAXN];
    
    Matrix() {
        memset(x, 0, sizeof(x));
    }
    int* operator [] (int r) {
        return x[r];
    }
    static Matrix unit() {
        Matrix res;
        for (int i = 0; i < MAXN; i++) res[i][i] = 1;
        return res;
    }
    friend Matrix operator + (Matrix A, Matrix B) {
        Matrix res;
        for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
            res[i][j] = A[i][j] + B[i][j];
            if (res[i][j] >= MOD) res[i][j] -= MOD;
        }
        return res;
    }
    friend Matrix operator * (Matrix A, Matrix B) {
        Matrix res;
        for (int i = 0; i < MAXN; i++) 
            for (int k = 0; k < MAXN; k++) 
                for (int j = 0; j < MAXN; j++)
            res[i][j] = (res[i][j] + (long long) A[i][k] * B[k][j]) % MOD;
        return res;
    }
    friend Matrix operator ^ (Matrix A, long long k) {
        if (k == 0) return unit();
        Matrix res, tmp;
        for (int i = 0; i < MAXN; i++) 
            for (int j = 0; j < MAXN; j++)
                res[i][j] = tmp[i][j] = A[i][j];
        k--;
        while (k) {
            if (k & 1) res = res * tmp;
            tmp = tmp * tmp;
            k >>= 1;
        }
        return res;
    }
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k;
	cin >> n >> k;
	Matrix M;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> M[i][j];
	M = M^k;

	int res = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			res = addmod(res, M[i][j]);

	cout << res << endl;

	return 0;
}
