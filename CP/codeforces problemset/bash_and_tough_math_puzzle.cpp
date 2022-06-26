#include<bits/stdc++.h>
#define max_n 500200
using namespace std;
inline int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
int arr[max_n],tree[max_n<<2],ctr;
long long st_size;
int n;
int gcd(int a, int b) 
{ 
    if (a < b) 
        swap(a, b); 
    if (b==0) 
        return a; 
    return gcd(b, a%b); 
} 
void update(int node, int start, int end, int idx, int val)
{
    if(start>end)
    	return;
    if(start == end)
        tree[node] = val;
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx && idx <= mid)
            update(2*node, start, mid, idx, val);
        else
            update(2*node+1, mid+1, end, idx, val);
      
        tree[node]=gcd(tree[2*node],tree[2*node+1]);
    }
}
void build(int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = arr[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = gcd(tree[2*node],tree[2*node+1]);
    }
}
void query(int node, int start, int end, int l, int r,int x)
{
    if(ctr>=2)
    	return;
    if(start==end)
    {
    	ctr++;
    	return;
    }
    int mid = (start + end) / 2;
    if(2*node<=st_size&&tree[2*node]%x!=0&&l<=mid) query(2*node, start, mid, l, r,x);
    if(2*node+1<=st_size&&tree[2*node+1]%x!=0&&mid<r)query(2*node+1, mid+1, end, l, r,x);
    
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	n=read();
	for(int i=1;i<=n;i++)
	{
		arr[i]=read();
	}
	build(1,1,n);
	int q;
	q=read();
	st_size=((long long )(2*pow(2,ceil(log2(n)))-1));
	int decider,l,r,x,index,value;
	for(int i=1;i<=q;i++)
	{
		decider=read();
		if(decider==1)
		{
			l=read();
			r=read();
			x=read();
		}
		else
		{
			index=read();
			value=read();
		}
		if(decider==2)
			{
                arr[index]=value; 
				update(1,1,n,index,value);
				
			}	
		else
		{
			ctr=0;
			query(1,1,n,l,r,x);
			if(ctr<2)
				puts("YES");
			else if(ctr>=2)
				puts("NO");
			


		}
	}
}