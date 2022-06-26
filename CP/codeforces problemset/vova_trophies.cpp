#include<bits/stdc++.h>
using namespace std;
char trophies[100001];
vector<pair<int,int>> ranges;
bool possible(int len,int n)
{
    if(ranges.size()==1)
    {
    	if(ranges[0].second-ranges[0].first+1>=len)
    		return true;
    	return false;

    }
    else if(ranges.size()==2)
    {
    	int len1,len2;
    	len1=ranges[0].second-ranges[0].first+1;
    	len2=ranges[1].second-ranges[1].first+1;
    	if(len1>=len||len2>=len)
    		return true;
    	else if(ranges[0].second+2==ranges[1].first)
    	{
    		if(len1+len2>=len)
    			return true;
    	}
    	else
    	{
    		if(ranges[1].first-ranges[0].second>2)
    			{if(len1+1>=len||len2+1>=len)
    				return true;
    			}
    		if(n-ranges[1].second>1)
    		   {if(len2+1>=len)
    				return true;
    		   }
    		    	
    	}
    	return false;
    		
    }
    else if(ranges.size()>=3)
    {
    	for(int i=0;i<ranges.size()-1;i++)
    	{
    		int len1,len2;
    	len1=ranges[i].second-ranges[i].first+1;
    	len2=ranges[i+1].second-ranges[i+1].first+1;
    	if(len1>=len||len2>=len)
    		return true;
    	else if(ranges[i].second+2==ranges[i+1].first)
    	{
    		if(len1+len2+1>=len)
    			return true;
    	}
    	else
    	{
    		if(ranges[i+1].first-ranges[i].second>2)
    			{if(len1+1>=len||len2+1>=len)
    				return true;
    			}
    		if(i==ranges.size()-2)
    		{
    		if(n-ranges[i+1].second>1)
    		   {if(len2+1>=len)
    				return true;
    		   }
    		}  
    		    	
    	}

    	}
    	return false;

    }
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>trophies[i];
	}
	int low=-1,high=-1;
	for(int i=0;i<n;i++)
	{
	     if(low==-1&&trophies[i]=='G')
	     	low=i;
	     if(i==n-1&&low!=-1&&trophies[i]=='G')
	     	high=i;
	     else
	     {
	     	if(low!=-1&&high==-1&&trophies[i]=='G'&&trophies[i+1]=='S')
	     		high=i;
	     }
	     if(low!=-1&&high!=-1)
	     {
	     	ranges.push_back(make_pair(low,high));
	     	low=-1;high=-1;
	     }
	}
	if(ranges.size()==0)
		cout<<0<<endl;
	else
	{	
	int x=0;
	for(int b=n;b>=1;b/=2)
	{

		while(possible(x+b,n))
			x+=b;

	}
	cout<<x<<endl;
    }
}