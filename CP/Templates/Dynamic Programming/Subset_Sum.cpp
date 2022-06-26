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
#define msi multiset < int >
#define msll multiset < ll >
#define pqi priority_queue < int >
#define pqll priority_queue < ll >
#define endl '\n'
#define all(x) x.begin(),x.end()
#define foreach(it,v) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
#define present(v,x) (v).find(x) != (v).end()
#define cpresent(v,x) (find(all(v),x) != (v).end())
#define mset(x,v) memset(x, v, sizeof(x))
#define sz(x) (int)x.size()
#define shout()  {cout << "I'm Here...!!!" << endl;}
#define dbg(x) { cout<< #x << ":" << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ":" << (x) << "," << #y << ":" << (y) << endl; }

inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}

bool isSubsetSum(vector < int > &set, int sum) { 
    int n = set.size();
    bool subset[n+1][sum+1]; 
   
    for (int i = 0; i <= n; i++) 
      subset[i][0] = true; 

    for (int i = 1; i <= sum; i++) 
      subset[0][i] = false; 

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= sum; j++) { 
        if(j<set[i-1]) 
            subset[i][j] = subset[i-1][j]; 
        if (j >= set[i-1]) 
            subset[i][j] = subset[i-1][j] || subset[i - 1][j-set[i-1]]; 
       } 

    return subset[n][sum]; 
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}