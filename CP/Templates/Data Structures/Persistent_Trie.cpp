#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define MAXN 2005 	// Number of Elements
#define BITS 5 		// Maximum Number of Bits in a String

struct node{
	int a[2], s; 	// Size of a is 2 for Trie on Binary elements
};

struct Trie{
	int root[MAXN], n_node = 0;
	node T[MAXN*(BITS+1)];

	// i stands for ith insertion in the Trie
	// val value to be inserted in the Trie
	void insert(int i, ll val){
		int prev;
		int curr;
		//here prev takes node value with "" prefix
		if(i==0)
			prev = root[0];
		else
			prev = root[i-1];
		curr = ++n_node;

		// Storing Root in order to ensure Persistent use of the Trie
		root[i] = curr; 
		//we start traversing from previous and current root
		for(int i=BITS-1; i>=0; i--){
			bool bit = val&((ll)1<<i);
			T[curr] = T[prev]; 			// Store the previous location of a similar prefix
			T[curr].a[bit] = ++n_node; 	// Update location of the bit at current node
			T[curr].s += 1; 			// increase occurece of similar prefix by 1
			prev = T[prev].a[bit];		// Update Prev to previously occuring similar prefix node
			curr = T[curr].a[bit];		// Update curr to next node
		}
		T[curr] = T[prev];
		T[curr].s += 1;
	}

	// Find Maximum XOR A[i] in a range [l, r] with value x i.e. (A[i]^x)
	ll MaxXORquery(int l, int r, ll x){
		int prev = root[l-1];
		int curr = root[r];
		ll res = 0;
		for(int i=BITS-1; i>=0; i--){
			bool bit = x&((ll)1<<i);
			if(T[T[curr].a[bit^1]].s>T[T[prev].a[bit^1]].s){
				prev = T[prev].a[bit^1];
				curr = T[curr].a[bit^1];
				res |= ((ll)1<<i);
			}
			else{
				prev = T[prev].a[bit];
				curr = T[curr].a[bit];
			}
		}
		return res;
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Trie TR;
	TR.insert(0, 0); 		// Insert an initial element to make a base comparision

	TR.insert(1, 0b01000);	
	TR.insert(2, 0b10111);
	TR.insert(3, 0b11011);
	TR.insert(4, 0b11001);
	TR.insert(5, 0b01000);

	cout << TR.MaxXORquery(2, 5, 0b00100) << endl;

	return 0;
}