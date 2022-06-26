#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

pair<long long, long long> fib (int n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    int c = (p.first * ((2 * p.second - p.first) % MOD)) % MOD;
    int d = ((p.first * p.first) % MOD + (p.second * p.second) % MOD) % MOD;
    if (n & 1)
        return {d, (c + d) % MOD};
    else
        return {c, d};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cout << fib(n).first << endl;

    return 0;
}