#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define llu unsigned long long
#define ld long double
#define INF 0x3f3f3f3f
#define shout()  {cout << "I'm Here...!!!" << endl;}
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }

typedef struct _node{
	int key;
	struct _node *L;
	struct _node *R;
}BSTnode;

typedef BSTnode *BST;

// Preorder Print BST
void print_preorder(BST A){
	if(A==NULL)
		return;
	cout << A->key << " ";
	print_preorder(A->L);
	print_preorder(A->R);
}

//Left rotate
BST rrotate(BST u){
	BST v = u->L;
	BST M = v->R;

	v->R = u;
	u->L = M;

	return v;
}

//Right Rotate
BST lrotate(BST u){
	BST v = u->R;
	BST M = v->L;

	v->L = u;
	u->R = M;

	return v;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	

	return 0;
}