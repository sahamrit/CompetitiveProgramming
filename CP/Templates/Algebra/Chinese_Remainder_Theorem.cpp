#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}

vector<int> primes_upto(int n) {
    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<bool> is_prime(nsqrt + 1, true);
    for (int i = 2; i <= nsqrt; i++)
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }

    int S = nsqrt;
    vector<int> res;
    for (int k = 0; k * S <= n; k++) {
        vector<bool> block(S, true);
        int start = k * S;
        for (int p : primes) {
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j<S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (int i = 0; i<S && start + i <= n; i++)
            if (block[i])
                res.push_back(start + i);
    }
    return res;
}

// a[i] = n%p[i]
// p is a vector of relatively prime numbers
// n = x[0] + x[1]*p[0] + x[2]*p[0]*p[1] + x[3]*p[0]*p[1]*p[2] + ....
vector<int> CRT(vector<int> &a, vector<int> &p){
    vector<int> x(a.size());

    vector<vector<int> > r(p.size());
    for(int i=0; i<p.size(); i++){
        r[i].resize(p.size());
        for(int j=0; j<p.size(); j++)
            r[i][j] = inv(p[i], p[j]);
    }
            
    for(int i=0; i<a.size(); i++){
        x[i] = a[i];
        for(int j=0; j<i; j++){
            x[i] = mult(r[j][i], (x[i] - x[j]), p[i]);
            if(x[i]<0)
                x[i] += p[i];
        }
    }

    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    //Vector of relatively prime elements
    int limit = 10;
    vector<int > p = primes_upto(limit);

    vector<int > a(p.size());
    for(int i=0; i<p.size(); i++)
        a[i] = n%p[i];

    vector<int > x = CRT(a, p);
    for(int xi: x)
        cout << xi << " ";
    cout << endl;

    return 0;
}

// Input
// 49

// Output
// 1 0 3 1 