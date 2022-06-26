#include<bits/stdc++.h>
using namespace std;
long long count_tasty(int l,int r,int k,vector<int>&a)
{
	long long cnt_tasty=0;
	if(l>=r)
		return 0;
	int min=l;
	int mid=(l+r)/2;
	for(int i=l+1;i<=r;i++)
	{
		if(a[i]<a[min])
			min=i;
		else if(a[i]==a[min])
		{
			if(abs(mid-min)>abs(mid-i))
				min=i;
		}
	}
	int sum=0;
	map<int,long long>temp;
	for(int i=min-1;i>=l;i--)
	{
		sum=(sum%k+a[i]%k)%k;
		if(sum==0)
			cnt_tasty++;
		temp[sum]++;
	}
	sum=0;
	for(int i=min+1;i<=r;i++)
	{
		sum=(sum%k+a[i]%k)%k;
		if(sum==0)
			cnt_tasty++;
		cnt_tasty+=temp[(k-sum)%k];

	}
	return cnt_tasty+count_tasty(l,min-1,k,a)+count_tasty(min+1,r,k,a);

}
int main()
{
	int n ,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<count_tasty(0,n-1,k,a)<<endl;
}