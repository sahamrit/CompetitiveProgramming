#include <bits/stdc++.h>
using namespace std;

// Define MAXN
#define INF 0x3f3f3f3f
#define MAXN 100005
#define iter :: iterator
vector<int> a(MAXN);
multiset<int>t[4*MAXN];

// Build the SegTree
// a = array of elements, v = 1, tl = 1, tr = n
//O(n(logn)^2)
void buildSeg(int v, int tl, int tr){
	if(tl==tr)
		t[v].insert(a[tr]);
	else{
		int tm = (tl + tr)/2;
		buildSeg(v*2, tl, tm);
		buildSeg(v*2+1, tm+1, tr);
		//operation in the segment tree
		t[v].insert(t[2*v].begin(),t[2*v].end());
		t[v].insert(t[2*v+1].begin(),t[2*v+1].end());
	}
}

// Sum Query over [l, r]
// v = 1, tl = 1, tr = n, l = left bound, r = right bound
//O((logn)^2)
int querySeg(int v, int tl, int tr, int l, int r,int x){
	if(l>r)
		return INF;
	if(l==tl and r==tr)
		{
			multiset<int> iter it;
			it=t[v].lower_bound(x);
			if(it!=t[v].end())
				return *it;
			return INF;
		}
	int tm = (tl + tr)/2;
	return min(querySeg(v*2, tl, tm, l, min(r, tm),x), querySeg(v*2+1, tm+1, tr, max(l, tm+1), r,x));
}

// Update Query
// v = 1, tl = 1, tr = n, pos = position to be updated, new_val = new value
//O((logn)^2)
void updateSeg(int v, int tl, int tr, int pos, int new_val){
	t[v].erase(a[pos]);
	t[v].insert(new_val);
	if(tl==tr)
		a[tl] = new_val;
	else{
		int tm = (tl+tr)/2;
		if(pos<=tm)
			updateSeg(v*2, tl, tm, pos, new_val);
		else
			updateSeg(v*2+1, tm+1, tr, pos, new_val);
		}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> a[i];

	buildSeg(1, 1, n);

	int x=5;
	for(int i=1; i<=n; i++)
		cout << querySeg(1, 1, n, 1, i,x) << " ";
	cout << endl;

	for(int i=1; i<=n; i++)
		updateSeg(1, 1, n, i, 11-i);

	for(int i=1; i<=n; i++)
		cout << querySeg(1, 1, n, i, n,x) << " ";
	cout << endl;

	return 0;
}

// Input
//10
//1 6 5 4 5 6 7 8 9 10

// Output
//1061109567 6 5 5 5 5 5 5 5 5
//5 5 5 5 5 5 1061109567 1061109567 1061109567 1061109567

