#include<bits/stdc++.h>
using namespace std;
tuple<int,int,int>edges[200002],edges1[200002];
int parent[200002],sz[200002];
int depth_array[200002];
vector<pair<int,int>>adj[200002];
pair<int,int>parent_in_mst[200002];
int max_edge_len[200002][20],succ[200002][20];

struct pair_hash {
    inline size_t operator()(const pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};
unordered_set<pair<int,int>,pair_hash> set_of_edges;
bool sortbythird(const tuple<int, int, int>& a,  
               const tuple<int, int, int>& b) 
{ 
    return (get<2>(a) < get<2>(b)); 
}
int root(int a)
{
	if(a==parent[a])
		return a;
	return parent[a]=root(parent[a]);

}
void dfs(int s,int p)
{
	if(p)
		depth_array[s]=depth_array[p]+1;	
	for(auto u:adj[s])
	{
		if(u.first==p)
			continue;
		parent_in_mst[u.first]=make_pair(s,u.second);
		dfs(u.first,s);
			
	}
}
int query(int u, int v) 
{ 
	int max1=0;
    if (depth_array[v] < depth_array[u]) 
        swap(u, v);   
    int diff = depth_array[v] - depth_array[u]; 
     for (int i=0; i<19; i++)       
       {
       	if ((diff>>i)&1) 
            {
            	int temp=v;
            	v = succ[v][i];
            	if(max1<max_edge_len[temp][i])
            		max1=max_edge_len[temp][i];
            } 
        }    
    if (u == v) 
        return max1; 
    for (int i=17; i>=0; i--) 
        if (succ[u][i] != succ[v][i]) 
        { 
        	int temp1,temp2;
        	temp1=u;
        	temp2=v;
            u = succ[u][i]; 
            v = succ[v][i]; 
            max1=max(max1,max(max_edge_len[temp1][i],max_edge_len[temp2][i]));
        } 
        max1=max(max1,max(max_edge_len[u][0],max_edge_len[v][0]));
  
    return max1;
} 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>get<0>(edges[i])>>get<1>(edges[i])>>get<2>(edges[i]);
		edges1[i]=edges[i];
	}
	for(int i=1;i<=n;i++)
	{
		parent[i]=i;
		
	}
	long long weight_sum_mst=0;
	sort(edges,edges+m,sortbythird);
	int ctr1=0,y,o;
	for(int i=0;i<m;i++)
	{
		 y=root(get<0>(edges[i]));
		 o=root(get<1>(edges[i]));
		if(y!=o)
		{
			if(sz[y]<sz[o])
		    {parent[y]=o;sz[o]+=sz[y];}
	        else
		    {parent[o]=y;sz[y]+=sz[o];}
			weight_sum_mst+=get<2>(edges[i]);
			adj[get<0>(edges[i])].push_back(make_pair(get<1>(edges[i]),get<2>(edges[i])));
			adj[get<1>(edges[i])].push_back(make_pair(get<0>(edges[i]),get<2>(edges[i])));
			set_of_edges.insert(make_pair(get<0>(edges[i]),get<1>(edges[i])));
			ctr1++;
		}
		if(ctr1==n-1)
			break;
	}
	depth_array[1]=0;
	parent_in_mst[1]=make_pair(0,0);
	dfs(1,0);
	
	for(int k=0;k<19;k++)
	{
		
		for(int i=1;i<=n;i++)
		{
			if(pow(2,k)>depth_array[i])
			{
				succ[i][k]=succ[i][k-1];
				max_edge_len[i][k]=max_edge_len[i][k-1];
			}
			else if(k==0)
			{
				succ[i][k]=parent_in_mst[i].first;
				max_edge_len[i][k]=parent_in_mst[i].second;
			}
			else
			{
				succ[i][k]=succ[succ[i][k-1]][k-1];
				max_edge_len[i][k]=max(max_edge_len[i][k-1],max_edge_len[succ[i][k-1]][k-1]);
			}
		}
		
	}
	for(int i=0;i<m;i++)
	{
		if(set_of_edges.find(make_pair(get<0>(edges1[i]),get<1>(edges1[i])))!=set_of_edges.end())
		{
			cout<<weight_sum_mst<<endl;
		}
		else
		{
            int l=get<0>(edges1[i]);
            int r=get<1>(edges1[i]);
            int lca=query(l,r);
            cout<<weight_sum_mst+get<2>(edges1[i])-lca<<endl; 
		}

	}

}