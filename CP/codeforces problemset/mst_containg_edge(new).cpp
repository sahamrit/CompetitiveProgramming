#include<bits/stdc++.h>
using namespace std;
tuple<int,int,int>edges[200002],edges1[200002];
int parent[200002],sz[200002];
int dfs_array[400004],depth_dfs_array[400004],depth_array[200002];
vector<pair<int,int>>adj[200002];
pair<int,int>pos_of_nodes_in_dfsarr[200002],parent_in_mst[200002];
struct pair_hash {
    inline size_t operator()(const pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};
unordered_set<pair<int,int>,pair_hash> set_of_edges;
int sparse_table[400004][23];
int ctr=0;
bool sortbythird(const tuple<int, int, int>& a,  
               const tuple<int, int, int>& b) 
{ 
    return (get<2>(a) < get<2>(b)); 
}
int root(int a)
{
	while(a!=parent[a])
	{
		parent[a]=parent[parent[a]];
		a=parent[a];
	}
	return a;

}
bool connected(int a,int b)
{
	return root(a)==root(b);
}
void union_(int p,int q)
{
	int i=root(p);
	int j=root(q);
	if(sz[i]<sz[j])
	{
		parent[i]=j;sz[j]+=sz[i];
	}
	else
	{
		parent[j]=i;sz[i]+=sz[j];
	}
}
void dfs(int s,int p)
{
	if(p)
	{
		depth_array[s]=depth_array[p]+1;
	}
	
	dfs_array[++ctr]=s;
	depth_dfs_array[ctr]=depth_array[s];
	
	if(pos_of_nodes_in_dfsarr[s].first==-1)
	{
		pos_of_nodes_in_dfsarr[s].first=ctr;
		pos_of_nodes_in_dfsarr[s].second=ctr;
	}
	for(auto u:adj[s])
	{
		if(u.first==p)
			continue;
		parent_in_mst[u.first]=make_pair(s,u.second);
		dfs(u.first,s);
		dfs_array[++ctr]=s;
		depth_dfs_array[ctr]=depth_array[s];

		if(ctr>pos_of_nodes_in_dfsarr[s].second)
			pos_of_nodes_in_dfsarr[s].second=ctr;
	
	}
}
void pre_process(int n)
{
	for(int i=1;i<=n;i++)
	{
		sparse_table[i][0]=i;
	}
	for(int j=1;pow(2,j)<=n;j++)
	{
		for(int i=1;i+pow(2,j)-1<=n;i++)
		{
			if(depth_dfs_array[sparse_table[i][j-1]]<depth_dfs_array[sparse_table[i+(int)pow(2,j-1)][j-1]])
				sparse_table[i][j]=sparse_table[i][j-1];
			else
				sparse_table[i][j]=sparse_table[i+(int)pow(2,j-1)][j-1];
		}
	}
}
int query(int l,int r)
{
	int lenght=r-l+1;
	int k=floor(log2(lenght));
	if(depth_dfs_array[sparse_table[l][k]]<depth_dfs_array[sparse_table[l+lenght-(int)pow(2,k)][k]])
		return sparse_table[l][k];
	return sparse_table[l+lenght-(int)pow(2,k)][k];
}
int max_lenght_lca(int x,int s)
{
	int max=0;
	
	while(x!=s&&x!=1)
	{
		if(max<parent_in_mst[x].second)
			max=parent_in_mst[x].second;
		x=parent_in_mst[x].first;
	}
	return max;
}
int main()
{
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
		pos_of_nodes_in_dfsarr[i]=make_pair(-1,-1);
	}
	long long weight_sum_mst=0;
	sort(edges,edges+m,sortbythird);
	for(int i=0;i<m;i++)
	{
		if(!connected(get<0>(edges[i]),get<1>(edges[i])))
		{
			union_(get<0>(edges[i]),get<1>(edges[i]));
			weight_sum_mst+=get<2>(edges[i]);
			adj[get<0>(edges[i])].push_back(make_pair(get<1>(edges[i]),get<2>(edges[i])));
			adj[get<1>(edges[i])].push_back(make_pair(get<0>(edges[i]),get<2>(edges[i])));
			set_of_edges.insert(make_pair(get<0>(edges[i]),get<1>(edges[i])));
		}
	}
	depth_array[1]=0;
	parent_in_mst[1]=make_pair(0,0);
	dfs(1,0);
	//cout<<weight_sum_mst<<endl;
	/*for(int i=1;i<=ctr;i++)
	{
		cout<<dfs_array[i]<<" ";
	}*/
	cout<<endl;
	pre_process(ctr);
	for(int i=0;i<m;i++)
	{
		if(set_of_edges.find(make_pair(get<0>(edges1[i]),get<1>(edges1[i])))!=set_of_edges.end())
		{
			cout<<weight_sum_mst<<endl;
		}
		else
		{
			int maxi;
			int lca;
			int l=min(pos_of_nodes_in_dfsarr[get<0>(edges1[i])].first,pos_of_nodes_in_dfsarr[get<1>(edges1[i])].first);
			int r=max(pos_of_nodes_in_dfsarr[get<1>(edges1[i])].second,pos_of_nodes_in_dfsarr[get<0>(edges1[i])].second);

			int idx=query(l,r);
			lca=dfs_array[idx];
		   
		  
			maxi=max(max_lenght_lca(get<0>(edges1[i]),lca),max_lenght_lca(get<1>(edges1[i]),lca));
            cout<<weight_sum_mst+get<2>(edges1[i])-maxi<<endl; 
		}

	}

}