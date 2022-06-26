#include <bits/stdc++.h>
using namespace std;

// Define MAXN
#define MAXN 100005
int nt, t[4*MAXN];

// Build the SegTree
// a = array of elements, v = 1, tl = 1, tr = n
void buildSeg( int v, int tl, int tr){
	if(tl==tr)
		t[v] = a[tr];
	else{
		int tm = (tl + tr)/2;
		buildSeg(v*2, tl, tm);
		buildSeg( v*2+1, tm+1, tr);
		t[v] = t[v*2] + t[v*2+1]; //Operation in the segtree
	}
}

// Sum Query over [l, r]
// v = 1, tl = 1, tr = n, l = left bound, r = right bound
int querySeg(int v, int tl, int tr, int l, int r){
	if(l>r)
		return 0;
	if(l==tl and r==tr)
		return t[v];
	int tm = (tl + tr)/2;
	return querySeg(v*2, tl, tm, l, min(r, tm)) + querySeg(v*2+1, tm+1, tr, max(l, tm+1), r);
}

// Update Query
// v = 1, tl = 1, tr = n, pos = position to be updated, new_val = new value
void updateSeg(int v, int tl, int tr, int pos, int new_val){
	if(tl==tr)
		t[v] = new_val;
	else{
		int tm = (tl+tr)/2;
		if(pos<=tm)
			updateSeg(v*2, tl, tm, pos, new_val);
		else
			updateSeg(v*2+1, tm+1, tr, pos, new_val);
		t[v] = t[v*2] + t[v*2 + 1];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> a(n+1);
	for(int i=1; i<=n; i++)
		cin >> a[i];

	buildSeg(a, 1, 1, n);

	for(int i=1; i<=n; i++)
		cout << querySeg(1, 1, n, 1, i) << " ";
	cout << endl;

	for(int i=1; i<=n; i++)
		updateSeg(1, 1, n, i, 11-i);

	for(int i=1; i<=n; i++)
		cout << querySeg(1, 1, n, i, n) << " ";
	cout << endl;

	return 0;
}

// Input
// 10
// 1 2 3 4 5 6 7 8 9 10

// Output
// 1 3 6 10 15 21 28 36 45 55
// 55 45 36 28 21 15 10 6 3 1
