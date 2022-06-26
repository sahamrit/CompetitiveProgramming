#include<bits/stdc++.h>
using namespace std;
int arr[100002],b[100002];
int tree[300000];
map<int,vector<int>>pos_of_element;
void update(int node,int l,int r,int idx,int val)
{
	if(l>idx||r<idx)
		return;
	if(l==r)
	{
		tree[node]=val;
		return;
	}
	else
	{
	int mid=(l+r)/2;
	if(l<=idx&&idx<=mid)
	{
		update(2*node,l,mid,idx,val);
	}
	else
	{
		update(2*node+1,mid+1,r,idx,val);
	}
	tree[node]=max(tree[2*node],tree[2*node+1]);
    }

}
int query(int node,int l,int r,int ql,int qr)
{
	if(r<ql||qr<l)
		return 0;
	if(ql<=l&&r<=qr)
		return tree[node];
	int mid=(l+r)/2;
	int p1=query(2*node,l,mid,ql,qr);
	int p2=query(2*node+1,mid+1,r,ql,qr);
	return(max(p1,p2));
}
bool possible(int k,map<int,vector<int>>pos_of_element,int s,int n)
{
	if(k>n)
		return false;

	memset(tree,0,sizeof(tree));
	int d ;
	long long sum=0;
	
	for(auto u:pos_of_element)
	{
       if((u.second).size()!=0)
       {
       	
       	for(int j=0;j<(u.second).size();j++)
       	{
       		int st=j;
       		while(j+1<(u.second).size()&&((u.second)[j+1]-(u.second)[j])<=k)
       			j++;
       		d=query(1,1,n,max(1,(u.second)[st]-k),min(n,(u.second)[j]+k))+1;
       		
          for(int w=st;w<=j;w++)       
       		{update(1,1,n,(u.second)[w],d);
       			b[(u.second)[w]]=d;}

       	}

       }
	}
	bool check=true;
	for(int i=1;i<=n;i++)
	{
		sum+=b[i];
		if(sum>s)
		{
			check=false;
			break;

		}
	}
	return check;
}
int main()
{
	
	int t;
	int n,s;
	cin>>t;
	while(t--)
	{
       pos_of_element.clear();
         cin>>n>>s;    
		
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
		}
		
		for(int i=1;i<=n;i++)
		{
			pos_of_element[arr[i]].push_back(i);
		}


		int x=-1;
		for(int b=n+1;b>=1;b/=2)
		{
			
			while(possible(x+b,pos_of_element,s,n))
				{
				x+=b;
			}
		}
		int k=x+1;
		cout<<k<<endl;

	}
}