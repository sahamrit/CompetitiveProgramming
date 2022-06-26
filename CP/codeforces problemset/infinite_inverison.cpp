#include<bits/stdc++.h>
using namespace std;
map<long long,long long> position_of_element;
map<long long,pair<long long ,long long>>element_at_pos;
long long arr[200002];
long long  mergingandsplitcount(long long A[],long long B[],long long C[],long long m,long long n)
{    long long ctr=0;
    long long i=0,j=0,k=0;
    while(i<m&&j<n)
    {
        if(A[i]<B[j])
            C[k++]=A[i++];
        else if(A[i]>B[j])
        {C[k++]=B[j++];
        ctr+=m -i;}
        else {C[k++]=A[i++];
              C[k++]=B[j++];
        }

    }
    while(i<m)
        C[k++]=A[i++];
    while(j<n)
         C[k++]=B[j++];
         return ctr;

}

long long  mergesortandnonsplit(long long A[],long long n)
{
    if(n<=1)return 0;
    long long i=n/2;
    long long *B=new long long [n];
   long long x= mergesortandnonsplit(A,i) ;
   long long y= mergesortandnonsplit(A+i,n-i);
    long long z=mergingandsplitcount(A,A+i,B,i,n-i);
    for(i=0;i<n;i++)
        A[i]=B[i];
    return x+y+z;
}
int main()
{
	
    long long n,a,b,inversions;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a>>b;
		if(!position_of_element[a])
			position_of_element[a]=a;
		if(!position_of_element[b])
			position_of_element[b]=b;
		swap(position_of_element[a],position_of_element[b]);
	}
	vector<pair<long long,long long>>a1;
	for(auto u:position_of_element)
	{
		a1.push_back(make_pair(u.second,u.first));
	}
	sort(a1.begin(),a1.end());
	long long ctr=0;
	for(auto u:a1)
	{
		element_at_pos[u.first]=make_pair(u.second,ctr);
		arr[ctr++]=u.second;
	}
	inversions=mergesortandnonsplit(arr,ctr);
	for(auto u:element_at_pos)
	{
		if(u.first!=(u.second).first)
		{
			inversions+=abs(u.first-(u.second).first)-1;
			inversions-=abs((u.second).second-element_at_pos[(u.second).first].second)-1;
		}
	}
	cout<<inversions<<endl;
    
} 