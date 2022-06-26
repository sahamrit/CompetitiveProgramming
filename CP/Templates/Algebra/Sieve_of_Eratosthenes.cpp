#include <bits/stdc++.h>
using namespace std;

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector < int > primes = primes_upto(n);
    for(int p: primes)
        cout << p << " ";
    cout << endl;

    return 0;
}

// Input
// 100

// Output
// 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 
