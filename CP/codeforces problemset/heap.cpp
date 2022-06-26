#include<bits/stdc++.h>
using namespace std;
int parent(int i){return i/2;}
int lchild(int i){return 2*i;}
int rchild(int i){return 2*i+1;}

void heapify(int *h,int *n,int i)//max heap
{
	if(i>*n)return;
	int l=lchild(i),r=rchild(i);
	if(l>*n)return;
	int idx=i;
	if(l<=*n && r>*n)
	{
		if(h[l]>h[i])
		{
			swap(h[l],h[i]);
			idx=l;
		}
	}
	else
	{
		idx=h[l]>h[r]?l:r;
		if(h[i]<h[idx])
		{
			swap(h[i],h[idx]);

		}
	}
	if(idx==i)return;
	heapify(h,n,idx); 
}
void pushup(int *h,int i)
{
	int p=parent(i);
	while(i>=1&&p>=1&&h[p]<h[i])
	{
		swap(h[i],h[p]);
		i=p;
		p=parent(i);
	}
}
void makeheap(int *h,int *n)
{
	for(int i=parent(*n);i>=1;i--)
		heapify(h,n,i);
}
int getmax(int *h)
{
	return h[1];
}
int extractmax(int *h,int *n)
{
	int p=h[1];
	h[1]=h[*n];
	(*n)--;
	heapify(h,n,1);
	return p;

}
void increasekey(int *h,int idx,int val)//assuming val>=h[idx]
{
	h[idx]=val;
	pushup(h,idx);
}
void deletekey(int *h,int *n,int idx)
{
	increasekey(h,idx,INT_MAX);
	extractmax(h,n);

}
void insertkey(int *h,int *n,int key)
{
	(*n)++;
	h[*n]=key;
	pushup(h,*n);
}
int main()
{
	srand(time(0));
	int n;
	cin>>n;//n=100;
	int *h=new int[n+1];//1 based index;
	int size=5;

	for(int i=1;i<=size;i++){h[i]=rand()%1001;cout<<h[i]<<" ";}
	cout<<endl;	
	makeheap(h,&size);
	cout<<"extractmax first "<<extractmax(h,&size)<<endl;
	cout<<"extractmax second "<<extractmax(h,&size)<<endl;	
	insertkey(h,&size,3);
	insertkey(h,&size,11);
	insertkey(h,&size,11);
	insertkey(h,&size,99);
	cout<<"size:"<<size<<endl;
	deletekey(h,&size,1);
	cout<<"size:"<<size<<endl;
	cout<<"extractmax third"<<extractmax(h,&size)<<endl;
	cout<<"extractmax fourth "<<extractmax(h,&size)<<endl;
	cout<<"extractmax fifth "<<extractmax(h,&size)<<endl;
	cout<<"extractmax sixth "<<extractmax(h,&size)<<endl;	
				


}