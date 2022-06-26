#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back

const int N = 3e5;
using namespace std;
int a[N];

//IMPLEMENTATION OF WAVELET TREE TAKEN FROM https://ideone.com/Tkters
struct wavelet_tree{
     
	int lo, hi;
	wavelet_tree *l, *r;
	vi b;
	
	//nos are in range [x,y]
	//array indices are [from, to)
	wavelet_tree(int *from, int *to, int x, int y){
		lo = x, hi = y;
		if(lo == hi or from >= to) return;
		int mid = (lo+hi)/2;
		auto f = [mid](int x){
			return x <= mid;
		};
		b.reserve(to-from+1);
		b.pb(0);
		for(auto it = from; it != to; it++)
			b.pb(b.back() + f(*it));
		//see how lambda function is used here	
		auto pivot = stable_partition(from, to, f);
		l = new wavelet_tree(from, pivot, lo, mid);
		r = new wavelet_tree(pivot, to, mid+1, hi);
	}
	//kth smallest element in [l, r]
	int kth(int l, int r, int k){
		if(l > r) return 0;
		if(lo == hi) { if(k>=1&&k<=2000)return lo;return 0;}
		int inLeft = b[r] - b[l-1];
		int lb = b[l-1]; //amt of nos in first (l-1) nos that go in left 
		int rb = b[r]; //amt of nos in first (r) nos that go in left
		if(k <= inLeft) return this->l->kth(lb+1, rb , k);
		return this->r->kth(l-lb, r-rb, k-inLeft);
	} 
	//count of nos in [l, r] equal to k
	int count(int l, int r, int k) {
		if(l > r or k < lo or k > hi) return 0;
		if(lo == hi){if(lo==k) return r - l + 1;return 0;}
		int lb = b[l-1], rb = b[r], mid = (lo+hi)/2;
		if(k <= mid) return this->l->count(lb+1, rb, k);
		return this->r->count(l-lb, r-rb, k);
	}
	~wavelet_tree(){
		free(this->l);
		free(this->r);
	}	

};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;i++) cin>>a[i+1];
		wavelet_tree T(a+1, a+n+1, 1, 2000);
		long long res=0;
        for(int i=1;i<=n;i++)
        {
        	for(int j=i;j<=n;j++)
        	{
        	      int l=i,r=j;
        	      int length=r-l+1;
        	      int m=ceil((double)k/length);
        	      int qr=ceil((double)k/m);
        	      int x=T.kth(l,r,qr);
        	      int f=T.count(l,r,x);
        	      int beauty=T.count(l,r,f);
        	      if(beauty>=1&&x&&f)
        	      	res++;

        	}
        }
        cout<<res<<endl;
	}

}