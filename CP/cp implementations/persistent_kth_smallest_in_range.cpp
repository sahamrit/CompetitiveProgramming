#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int count_[N];
vector<int> arr(N),compressed(N),decompress(N),temp(N);

struct Vertex {
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

Vertex* build(int tl, int tr) {
    if (tl == tr)
        return new Vertex(0);
    int tm = (tl + tr) / 2;
    return new Vertex(build(tl, tm), build(tm+1, tr));
}
Vertex* update(Vertex* v, int tl, int tr, int val) {
    if (tl == tr)
        return new Vertex(count_[val]);
    int tm = (tl + tr) / 2;
    if (val<= tm)
        return new Vertex(update(v->l, tl, tm, val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, val));
}
//root l represents number in 0..l-1;
int get_kth(Vertex* vl,Vertex*vrp1, int tl, int tr, int k) {//assume k is in range 1 to N
    int current_count_,left_count_,right_count_;
    current_count_=vrp1->sum-vl->sum;
    if(k>current_count_)return -1;
    if (tl==tr)
    	return tl;
    left_count_=vrp1->l->sum-vl->l->sum;
    right_count_=current_count_-left_count_;

    int tm = (tl + tr) / 2;
    if(k<=left_count_) return get_kth(vl->l,vrp1->l,tl,tm,k);
    else return get_kth(vl->r,vrp1->r,tm+1,tr,k-left_count_);

}
vector<Vertex*>root(N+1);
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		temp[i]=arr[i];
	}
	sort(temp.begin(),temp.begin()+n);
	for(int i=0;i<n;i++){
		compressed[i]=lower_bound(temp.begin(),temp.begin()+n,arr[i])-temp.begin();
		decompress[compressed[i]]=arr[i];
		count_[compressed[i]]++;
	}	
 	root[0]=build(0,N-1);
	for(int i=1;i<=n;i++)
	{
		root[i]=update(root[i-1],0,N-1,compressed[i-1]);
		//cout<<root[i]->sum<<" for 0..."<<i-1<<endl;
	}
	int l,r,k;
	cin>>l>>r>>k;
	if(l>r||l>=n||r>=n||k>n||k>r-l+1)cout<<"invalid query;l,r should be between 0 and "<<n-1<<"and k should be 1 to"<<r-l+1<<endl;
	else
	{
		int res=get_kth(root[l],root[r+1],0,N-1,k);
		if(res==-1)cout<<"no such element"<<endl;
		else
			cout<<decompress[res];
	}

}