#include<bits/stdc++.h>
using namespace std;
vector<int>perm;
vector<pair<int,int>>left1,right1;
map<int,int>freqodd,freqeven;
//for left1,right1 0 is even
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int pos,x;
	for(int i=0;i<n;i++)
	{
       cin>>x;
       if(x==m)
       	pos=i;
       perm.push_back(x);
	}
	int small,large;
	for(int i=pos;i>=0;i--)
	{
		if(i==pos)
		{
			small=0;large=0;
			left1.push_back(make_pair(large-small,1));
		}
		else
		{
			if(perm[i]<m)
				small++;
			else
				large++;
			if((pos-i+1)%2==0)
			left1.push_back(make_pair(large-small,0));
		    else
		    left1.push_back(make_pair(large-small,1));	
		}

	}
	small=0;large=0;
	for(int i=pos+1;i<n;i++)
	{
		if(perm[i]<m)
			small++;
		else
			large++;
		if((i-pos)%2==0)
	    {
	    	right1.push_back(make_pair(large-small,0));
	    }
	    else
	    {
	    	right1.push_back(make_pair(large-small,1));
	    	
	    }	

	}
	long long ctr=0;
	for(int i=0;i<right1.size();i++)
	{
		if(right1[i].second==0)
		{
			freqeven[right1[i].first]++;
		}
		else
		{
			freqodd[right1[i].first]++;
		}
	}
	for(int i=0;i<left1.size();i++)
	{
		int p=left1[i].first;
		if(left1[i].second==0)
		{
            ctr+=freqodd[-p];
            ctr+=freqeven[1-p];
            if(p==1)
            	ctr++;
		}
		else
		{
			ctr+=freqeven[-p];
            ctr+=freqodd[1-p];
            if(p==0)
            	ctr++;

		}
	}
	cout<<ctr<<endl;


}