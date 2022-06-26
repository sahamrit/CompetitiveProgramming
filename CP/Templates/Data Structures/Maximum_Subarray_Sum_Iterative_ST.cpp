#include <bits/stdc++.h>
using namespace std;

const int N = 1e5; //Limit for Array Size

int st_size; //Array Size
int st[2*N], max_sum[2*N], max_rsum[2*N], max_lsum[2*N];

//Set the value at each Node
void set_node(int p, int val){
	int node = st_size+p;
	st[node] = max_sum[node] = max_lsum[node] = max_rsum[node] = val;
}

//Build the Tree
void build(){
	for(int i=st_size-1; i>0; i--){
		st[i] = st[i<<1] + st[i<<1|1]; 
		max_lsum[i] = max(max_lsum[i<<1], st[i<<1]+max_lsum[i<<1|1]);
		max_rsum[i] = max(max_rsum[i<<1|1], st[i<<1|1]+max_rsum[i<<1]);
		max_sum[i] = max(max(max_sum[i<<1], max_sum[i<<1|1]), max_rsum[i<<1]+max_lsum[i<<1|1]);
	}
}

//Set value at Position p
void modify(int p, int value)	{
	p+=st_size;
	for (st[p] = max_sum[p] = max_lsum[p] = max_rsum[p] = value; p>1; p>>=1) {
		st[p>>1] = st[p] + st[p^1];
		int i=p>>1;
		max_lsum[i] = max(max_lsum[i<<1], st[i<<1]+max_lsum[i<<1|1]);
		max_rsum[i] = max(max_rsum[i<<1|1], st[i<<1|1]+max_rsum[i<<1]);
		max_sum[i] = max(max(max_sum[i<<1], max_sum[i<<1|1]), max_rsum[i<<1]+max_lsum[i<<1|1]);
	}
}

//Sum on interval [l, r)
int query(int l, int r) {
	int resl=INT_MIN>>1, resr=INT_MIN>>1, res_li=INT_MIN>>1, res_ri=INT_MIN>>1;
	for (l += st_size, r += st_size; l < r; l >>= 1, r >>= 1){
		if (l&1) {
			res_li = max(max(res_li, max_sum[l]), resl+max_lsum[l]);
			resl = max(max_rsum[l], resl+st[l]);
			l++;
		}
		if (r&1){
			r--;
			res_ri = max(max(res_ri, max_sum[r]), resr+max_rsum[r]);
			resr = max(max_lsum[r], resr+st[r]);
		}
	}
	int res = max(max(res_li, res_ri), resl+resr);
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
 	cin.tie(NULL);
	
	int n;
	cin >> n;
	st_size = n;
	for(int i=0; i<n; i++)
	{
		int a;
		cin >> a;
		set_node(i, a);
	}
	build();
	int m;
	cin >> m;
	while(m--)
	{
		int a;
		cin >> a;
		int x, y;
		cin >> x >> y;
		if(a==0)
			modify(x-1, y);
		else
			cout << query(x-1, y) << endl;
	}

	return 0;
}