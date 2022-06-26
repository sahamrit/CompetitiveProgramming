#include<bits/stdc++.h>

using namespace std;
struct pair_hash {
    inline size_t operator()(const pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};
int ids[300001],low[300001],visited[300001],parent[300001],maxlength[300001],size[300001];
vector<int> adj[300001],bridgetree[300001];
pair<int,int>edgelist[300001];

int id=0,bridge=0;
unordered_set <pair<int,int>,pair_hash> bridgelist;
 int root(int i)
  {   while (i != parent[i]) 
    {    parent[i] = parent[parent[i]]; 
         i = parent[i]; 
    }   return i; 
  }  

void union_(int p,int q)
{
	int i = root(p); 
	 int j = root(q); 
	if(i == j)
	 return;
	if  (size[i] < size[j]) 
	 	{ parent[i] = j;
	 	 size[j] += size[i]; } 
	else  
	    { parent[j] = i;
	     size[i] += size[j]; } 
}

void dfs(int at,int parent)
{
	visited[at]=true;
	id++;
	low[at]=id;
	ids[at]=id;
	for(auto to:adj[at])
	{
		if(to==parent)
			continue;
		if(!visited[to])
		{
			dfs(to,at);
			low[at]=min(low[at],low[to]);
			if(ids[at]<low[to])
				{bridgelist.insert(make_pair(at,to));
					bridge++;}

		}
		else
		{
			low[at]=min(low[at],ids[to]);
		}
	}
}
int main()
{
	int n,m,x,y;
	cin>>n>>m;
   
     for(int i=1;i<=n;i++)
     	{visited[i]=false;
     		maxlength[i]=0;}
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		edgelist[i]=make_pair(x,y);
		parent[x]=x;
		parent[y]=y;
		size[x]=1;
		size[y]=1;

	}
	dfs(x,-1);
	if(bridge==0)
	{
		cout<<0;
		exit(0);
	}
	for(int i=0;i<m;i++)
	{
		if(bridgelist.find(edgelist[i])==bridgelist.end()&&bridgelist.find(make_pair(edgelist[i].second,edgelist[i].first))==bridgelist.end())
		{
			union_(edgelist[i].first,edgelist[i].second);
		}
	}
	
    for(auto u:bridgelist)
    {
    	x=root(u.first);
    	y=root(u.second);

    	bridgetree[x].push_back(y);
    	bridgetree[y].push_back(x);
    }
    queue<int>q,q1;
    for(int i=1;i<=n;i++)
     	visited[i]=false;
     q.push(x);
     pair<int,int>max2=make_pair(-1,-1);
     int l;
     visited[x]=true;
     while(!q.empty())
     { l=q.front();
     	q.pop();
     	visited[l]=true;
     	for(auto u:bridgetree[l])
     	{
     		if(!visited[u])
     		{
     			q.push(u);
     			maxlength[u]=maxlength[l]+1;
     			if(max2.first<maxlength[u])
     			{
     				max2.first=maxlength[u];
     				max2.second=u;
     			}

     		}
     	}

     }
     for(int i=1;i<=n;i++)
     	{visited[i]=false;
     		maxlength[i]=0;}
     q1.push(max2.second);
     int max1=-1;
     
     visited[max2.second]=true;
     while(!q1.empty())
     { l=q1.front();
     	q1.pop();
     	visited[l]=true;
     	for(auto u:bridgetree[l])
     	{
     		if(!visited[u])
     		{
     			q1.push(u);
     			maxlength[u]=maxlength[l]+1;
     			if(max1<maxlength[u])
     				max1=maxlength[u];

     		}
     	}

     }

     cout<<max(max1,max2.first)<<endl;

    

	
}