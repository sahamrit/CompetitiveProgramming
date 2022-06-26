#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int st_size; //Input Array Size in main()
int st[2*N];

//Set the value at each node
void set_node(int p, int val){
	st[st_size+p] = val;
}

//Build the Tree
//Left node has even index and right node has odd index
void build(){
	for(int i=st_size-1; i>0; i--)
		st[i] = st[i<<1] + st[i<<1|1]; 
}

//Set value at Position p
void modify(int p, int value){
	for (st[p+=st_size]=value; p>1; p>>=1) 
		st[p>>1] = st[p] + st[p^1]; // (p>>1) is the parent of p and p^1
}

//Sum on range [l, r)
int range_sum(int l, int r) {
	int res = 0;
	for (l += st_size, r += st_size; l < r; l >>= 1, r >>= 1){
		if (l&1) res += st[l++];
		if (r&1) res += st[--r];
	}
	return res;
}	

int main()
{
	int n;
	cin >> n;
	st_size = n;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		set_node(i, a);
	}
	build();
	cout << range_sum(3, 11) << endl;

	return 0;
}

//Input
// 15
// 1 2 3 4 5 6 7 8 9 10 11 12

//Output
// 60