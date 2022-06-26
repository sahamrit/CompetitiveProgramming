#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 0x3f3f3f3f;
const int MAXN = 4003;

int dp[MAXN][MAXN] = {0};
int C[MAXN][MAXN] = {0};
vector < int > pref[MAXN];

//Write Cost Function as required
ll cost(int i, int j){
	return C[i][j];
}

void compute(int i, int l, int r, int optl, int optr){
	if(l>r)
		return;

	int mid = (l+r)>>1;
	pair < ll, int > best = {INF, -1};

	for(int k=optl; k<=min(mid, optr); ++k){
		best = min(best, {dp[i-1][k-1] + cost(k, mid), k});
	}

	dp[i][mid] = best.first;
	int opt = best.second;

	compute(i, l, mid-1, optl, opt);
	compute(i, mid+1, r, opt, optr);
}

// dp[i][j] = min{dp[i][k] + dp[k][j]} + C[i][j] where i<j<k

int main()
{
	ios_base::sync_with_stdio(false);
 	cin.tie(NULL);
	
	int n, k;
	cin >> n >> k;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin >> C[i][j];

	for(int j=1; j<=n; j++)
		dp[1][j] = cost(1, j);
	for(int i=2; i<=k; i++)
		compute(i , 1, n, 1, n);

	cout << dp[k][n] << endl;

	return 0;
}

// Input
// 3 2
// 0 2 0
// 2 0 3
// 0 3 0

// Output
// 2