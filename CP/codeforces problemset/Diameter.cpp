#include<bits/stdc++.h>
using namespace std;
int degree[501];
vector<pair<int,int>> edgelist;
vector<int>backbone;
vector<int>leafs;
int main()
{
	int n,sumdegree=0,no_edges=0,diameter;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>degree[i];
		sumdegree+=degree[i];
	}
	if(sumdegree<2*(n-1))
		cout<<"NO"<<endl;
	else
	{
		for(int i=1;i<=n;i++)
	{
		if(degree[i]>=2)
		{
			backbone.push_back(i);
		}
		else
			leafs.push_back(i);
	}
	    
	    for(int i=0;i<backbone.size()-1;i++)
	    {
	    	edgelist.push_back(make_pair(backbone[i],backbone[i+1]));
	    	degree[backbone[i]]--;
	    	degree[backbone[i+1]]--;
	    	no_edges++;
	    }

    if(leafs.size()==0)
    {
    	cout<<"YES"<<" "<<(n-1)<<endl;
    	cout<<no_edges<<endl;
    } 
	else if(leafs.size()==1||leafs.size()==2)
	{
		edgelist.push_back(make_pair(leafs[0],backbone[0]));
		no_edges++;
		if(leafs.size()==2)
		{
			edgelist.push_back(make_pair(leafs[1],backbone[backbone.size()-1]));
			no_edges++;

		}
		cout<<"YES"<<" "<<(n-1)<<endl;
		cout<<no_edges<<endl;
	}
	else
	{
		int ctr=2;
		diameter=no_edges+2;
		edgelist.push_back(make_pair(leafs[0],backbone[0]));
		no_edges++;
		degree[backbone[0]]--;

		
		edgelist.push_back(make_pair(leafs[1],backbone[backbone.size()-1]));
		no_edges++;
		degree[backbone[backbone.size()-1]]--;

		
		for(int i=0;i<backbone.size();i++)
		{
			if(degree[backbone[i]]>=1&&backbone[i]!=leafs[ctr])
			{
				while(degree[backbone[i]]!=0)
				{
					edgelist.push_back(make_pair(leafs[ctr++],backbone[i]));
					no_edges++;
					degree[backbone[i]]--;
					if(ctr>=leafs.size())
						break;
				}
			}
			if(ctr>=leafs.size())
						break;
		}
		cout<<"YES"<<" "<<diameter<<endl;
		cout<<no_edges<<endl;
	}

    for(int i=0;i<edgelist.size();i++) 
    {
    	cout<<edgelist[i].first<<" "<<edgelist[i].second<<endl;
    }	


	}

} 	