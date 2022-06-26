#include<bits/stdc++.h>
#define M 200000
using namespace std;
int s[M],t[M],t1[M];
bool sortinrev(const pair<int,int> &a,  
               const pair<int,int> &b) 
{ 
       return (a.first > b.first); 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	sort(s,s+n);
	vector <pair<int,int>> a;
	int ctr=1;
	for(int i=0;i<n;i++)
	{
		if(i!=n-1)
		{
			if(s[i]==s[i+1])
				ctr++;
			else
			{
                a.push_back(make_pair(ctr,s[i]));
                ctr=1;
			}
		}
		else if(i==n-1)
		{
			a.push_back(make_pair(ctr,s[i]));
		}
	}
	sort(a.begin(),a.end(),sortinrev);
	
   ctr=0;
   bool check=true;
   int temp;
   for(int i=1;i<=n;i++) 
   {
   	if(!check)
   		break;
   	ctr=0;

   	   for(int j=0;j<n;j++)
   	   {
   	   	if(a[j].first<i)
   	   		break;
   	   	if(ctr==k)
   	   		break;
   	   	temp=a[j].first;
   	   	while(temp>=i)
   	   	{
   	   		t1[ctr++]=a[j].second;
   	   		temp-=i;
   	   	}
   	   }
   	   if(ctr>=k)
   	   {
   	   	for(int j=0;j<k;j++ )
   	   	{
   	   		t[j]=t1[j];
   	   	}
   	   }
   	   else if(ctr<k)
   	   	check=false;


   }
   for(int i=0;i<k;i++)
   {
   	cout<<t[i]<<" ";
   }

}