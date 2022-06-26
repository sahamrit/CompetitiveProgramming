#include<bits/stdc++.h>
using namespace std;
pair<long long,int>begin_end[400004];
long long freq[200002];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int ctr=0;
	for(int i=1;i<=n;i++)
	{
		long long x,y;
		cin>>x>>y;
		begin_end[++ctr]=make_pair(x,0);
		begin_end[++ctr]=make_pair(y,1);
	}
	memset(freq,0,sizeof(freq));
	sort(begin_end+1,begin_end+2*n+1);
	long long current;
	pair<long long,int>prev;
    ctr=0;
	for(int i=1;i<=2*n;i++)
	{
		if(i==1)
		{
			prev=make_pair(begin_end[1].first,0);
			
		}
		if(begin_end[i].second==0)
		{
            current=begin_end[i].first;
            if(prev.second==0)
                freq[ctr]+=current-prev.first;
            else
            	freq[ctr]+=current-prev.first-1;


            ctr++;
            prev=make_pair(current,0);
		}
		else
		{
			current=begin_end[i].first;
			if(prev.second==0)
			    freq[ctr]+=current-prev.first+1;
		    else
		    	freq[ctr]+=current-prev.first;
			ctr--;
			prev=make_pair(current,1);
		}

	}
	for(int i=1;i<=n;i++)
	{
		cout<<freq[i]<<" ";
	}

}