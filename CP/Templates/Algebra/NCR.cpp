#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
vector < vector < int > > PreCompute_NCR(int n) {
    vector < vector < int > > C;
    C.resize(n+1);
	for(int i=0; i<=n; i++) {
		C[i].resize(n+1);
		C[i][0] = C[i][i] = 1;
		for(int j=1; j<i; j++)
			C[i][j] = (C[i-1][j]+C[i-1][j-1])%MOD;
	}
    return C;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector < vector < int > > NCR = PreCompute_NCR(n);
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
            cout << i << "C" << j << ":" << NCR[i][j] << " ";
        cout << endl;
    }
    return 0;
}

// Input
// 5

// Output
// 0C0:1 0C1:0 0C2:0 0C3:0 0C4:0 0C5:0 
// 1C0:1 1C1:1 1C2:0 1C3:0 1C4:0 1C5:0 
// 2C0:1 2C1:2 2C2:1 2C3:0 2C4:0 2C5:0 
// 3C0:1 3C1:3 3C2:3 3C3:1 3C4:0 3C5:0 
// 4C0:1 4C1:4 4C2:6 4C3:4 4C4:1 4C5:0 
// 5C0:1 5C1:5 5C2:10 5C3:10 5C4:5 5C5:1 