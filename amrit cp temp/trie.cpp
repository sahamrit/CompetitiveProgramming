#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define MAXN 2005 	// Number of Elements
#define BITS 5 		// Maximum Number of Bits in a String

struct node{
	int a[2]; 	// Size of a is 2 for Trie on Binary elements
};
struct Trie{
	int n_node = 0,root;
	node T[MAXN*(BITS+1)];
	// i stands for ith insertion in the Trie
	// val value to be inserted in the Trie
	void insert(ll val){
		if(!n_node)root=++n_node;
		int curr=root;
		for(int i=BITS-1; i>=0; i--){
			bool bit = val&((ll)1<<i);
			if(T[curr].a[bit]==0)
			T[curr].a[bit] = ++n_node; 	// Update location of the bit at current node
			curr = T[curr].a[bit];		// Update curr to next node
		}
	}

	// Find Maximum XOR trie
	ll MaxXORquery(ll x){
		int curr=root;
		ll res = 0;
		for(int i=BITS-1; i>=0; i--){
			bool bit = x&((ll)1<<i);
			if(T[curr].a[bit^1]){
				curr = T[curr].a[bit^1];
				res |= ((ll)1<<i);
			}
			else{
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
	TR.insert(0); 		// Insert an initial element to make a base comparision
	TR.insert(0b01000);	
	TR.insert(0b10111);
	TR.insert(0b11011);
	TR.insert(0b11001);
	TR.insert(0b01000);

	cout << TR.MaxXORquery(0b00100) << endl;

	return 0;
}