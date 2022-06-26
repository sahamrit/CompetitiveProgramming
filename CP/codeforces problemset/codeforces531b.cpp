#include<bits/stdc++.h>
#define p (int)(1e9+7)
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,k;
	cin>>n>>k;
	vector<unordered_set<int>>s(k+1);
	vector<int>a(n);
	vector<int>res;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ctr=0;
	int  check=0;

	for(int i=0;i<n;i++)
	{
		if(check==n)
			break;
		ctr=0;
		for(int j=0;j<k;j++)
		{
			if(s[j].find(a[i])==s[j].end()&& s[j].size()==0)
			{
				s[j].insert(a[i]);
				res.push_back(j);
				check++;
				break;
			}
			ctr++;
		}
		if(ctr==k){break;}
	}
	for(int i=check;i<n;i++)
	{
		if(check==n)
			break;
		ctr=0;
		for(int j=0;j<k;j++)
		{
			if(s[j].find(a[i])==s[j].end())
			{
				s[j].insert(a[i]);
				res.push_back(j);
				check++;
				break;
			}
			ctr++;
		}
		if(ctr==k){break;}
	}
	if(check<n)
		cout<<"NO";
	else if(check==n)
	{
		cout<<"YES"<<endl;
		for(int i=0;i<res.size();i++)
			cout<<res[i]+1<<" ";
	}
}
