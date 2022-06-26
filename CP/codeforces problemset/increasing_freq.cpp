#include<bits/stdc++.h>
using namespace std;
int a[500001],count_c[500001];
vector<pair<int,int>> range[500001];
unordered_set<int>s;
int main()
{
	int n,c,total_c=0;
	cin>>n>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==c)
			total_c++;
		s.insert(a[i]);
	}
	int start=0,end=0;
	count_c[0]=0;
	for(int i=1;i<=n;i++)
	{
        if(a[i]==c)
        	count_c[i]=count_c[i-1]+1;
        else
        	count_c[i]=count_c[i-1];

        if(start==0)
        	start=i;
        if(i!=n)
        {
        	if(start!=0)
        	{
        		if(a[i]!=a[i+1])
        			end =i;
        		else 
        			continue;
        	}

        }
        else
        {
        	if(start!=0)
        		end =i;

        }
        if(start!=0&&end!=0)
        {
        	range[a[start]].push_back(make_pair(start,end));
        	start=0;end=0;
        }
	}
	int max_c=0,max_till_now=0,max_end_here=0;
	unordered_set<int>::iterator it;
	int j;
	for(it=s.begin();it!=s.end();it++)
	{
		max_till_now=0,max_end_here=0;
		if(*it==c)
			continue;
		for(int i=0;i<range[*it].size();i++)
		{
			start=range[*it][i].first;
			end=range[*it][i].second;
			for(j=start;j<=end;j++)
			{
				max_end_here+=1;
			}
			if(max_till_now<max_end_here)
				max_till_now=max_end_here;
			if(i!=range[*it].size()-1)
			{
				max_end_here+=-(count_c[range[*it][i+1].first]-count_c[range[*it][i].second]);
				if(max_end_here<0)
					max_end_here=0;
				if(max_till_now<max_end_here)
				max_till_now=max_end_here;

		    }

        }
        if(max_c<total_c+max_till_now)
        	max_c=total_c+max_till_now;
	}
	if(max_c<total_c)
		max_c=total_c;

	cout<<max_c<<endl;
} 