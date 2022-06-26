#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

ll binpow(ll a, ll b, ll m = MOD) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
 	cin.tie(NULL);

     int n, k;
     cin >> n >> k;
     cout << binpow(n, k) << endl;

    return 0;
}

// Input
// 13 15

// Output
// 655789513