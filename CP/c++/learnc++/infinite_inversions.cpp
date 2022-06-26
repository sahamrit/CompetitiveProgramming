
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> position_of_element;
unordered_map<int,pair<int ,int>>element_at_pos;
int arr[100005];
vector<pair<int,int>>a1;
long long  mergingandsplitcount(int A[],int B[],int C[],int m,int n)
{    long long ctr=0;
    int i=0,j=0,k=0;
    while(i<m&&j<n)
    {
        if(A[i]<B[j])
            C[k++]=A[i++];
        else if(A[i]>B[j])
        {C[k++]=B[j++];
        ctr+=(long long)m -i;}
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

int  mergesortandnonsplit(int A[],int n)
{
    if(n<=1)return 0;
    int i=n/2;
    int *B=new int [n];
   int x= mergesortandnonsplit(A,i) ;
   int y= mergesortandnonsplit(A+i,n-i);
    int z=mergingandsplitcount(A,A+i,B,i,n-i);
    for(i=0;i<n;i++)
        A[i]=B[i];
    delete [] B;
    return x+y+z;
}
int main()
{
	int n,a,b;
long long inversions=0;
	cin>>n;

	for(int i=1;i<=100000;i++)
	{
		a=i;
		b=1000000001-i;
		if(!position_of_element[a])
			position_of_element[a]=a;
		if(!position_of_element[b])
			position_of_element[b]=b;
		swap(position_of_element[a],position_of_element[b]);
	}

	for(auto u:position_of_element)
	{
		a1.push_back(make_pair(u.second,u.first));
	}
	sort(a1.begin(),a1.end());
	int ctr=0;
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
