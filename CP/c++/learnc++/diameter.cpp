#include<bits/stdc++.h>
using namespace std;
vector <int> adj[8];
pair<int,int> toleaf[8];
int diameter[8];
int maximum=0;
void dfs(int s,int p)
{ 
	toleaf[s].first=0;
	toleaf[s].second=-1;
	diameter[s]=0;
  for(auto u:adj[s])
  {
  	if(u!=p)
  	{
  		dfs(u,s);
  	  if(toleaf[s].first<toleaf[u].first+1)
  	    {
  	    	toleaf[s].first=toleaf[u].first+1;
  	    	toleaf[s].second=u;

  	    }
    }
  }
  diameter[s]=toleaf[s].first;
  for(auto u:adj[s])
  {
  	if(u!=p && toleaf[s].second!=u)
  	{
  		dfs(u,s);
  	diameter[s]=max(diameter[s],toleaf[u].first+toleaf[s].first+1);
  	maximum=diameter[s];
    }
  }

}

int main()
{
	
	adj[6].push_back(2);
	adj[2].push_back(6);
	adj[2].push_back(5);
	adj[5].push_back(2);
	adj[2].push_back(1);
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[3].push_back(1);
	adj[1].push_back(4);
	adj[4].push_back(1);
	adj[4].push_back(7);
	adj[7].push_back(4);

	dfs(2,0);
	cout<<maximum<<endl;

   for(int i=1;i<=7;i++)
   {
   	cout<<i<<" "<<diameter[i]<<endl;
   }


}
