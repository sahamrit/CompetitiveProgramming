//MAX QUERY IN RANGE AND UPDATE ADD VALUE TO RANGE
#include <bits/stdc++.h>
using namespace std;

// Define MAXN
#define MAXN 100005
int t[4*MAXN],lazy[4*MAXN];
vector<int> a(MAXN);

void push(int v) {
	if(!lazy[v])return;
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

// Build the SegTree
// a = array of elements, v = 1, tl = 1, tr = n
void build(int v, int tl, int tr){
	if(tl==tr)
		t[v] = a[tr];
	else{
		int tm = (tl + tr)/2;
		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);
		t[v] = max(t[v*2],t[v*2+1]); //Operation in the segtree
	}
}

// max Query over [l, r]
// v = 1, tl = 1, tr = n, l = left bound, r = right bound
int query(int v, int tl, int tr, int l, int r){
	if(l>r)
		return INT_MIN;
	if(l==tl and r==tr)
		return t[v];
	push(v);
	int tm = (tl + tr)/2;
	return max(query(v*2, tl, tm, l, min(r, tm)),query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

// Update Query
void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r)
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = max(t[v*2], t[v*2+1]);
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
	build (1,1,n);
	cout<<query(1,1,n,2,7)<<endl;
	update(1,1,n,2,7,5);
	cout<<query(1,1,n,1,n)<<endl;

	return 0;
}

