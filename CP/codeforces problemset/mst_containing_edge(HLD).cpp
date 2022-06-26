#include<bits/stdc++.h>
#define max_n 200010
using namespace std;
int n,m;
int parent[max_n],sz[max_n],head_to[max_n],child[max_n],depth_array[max_n];
int parent_mst[max_n],sz_mst[max_n],top[max_n],edge_idx[max_n],chd_edge_idx[max_n];
tuple<int,int,int>e[max_n*2];
int cnt,pos,tree[max_n<<2];
vector<tuple<int,int,int>> edges,original,mst;
bool sortbythird(const tuple<int, int, int>& a,  
               const tuple<int, int, int>& b) 
{ 
    return (get<2>(a) < get<2>(b)); 
}
void update(int node, int start, int end, int idx, int val)
{
    if(start>end)
    	return;
    if(start == end)
        tree[node] = val;
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
            update(2*node, start, mid, idx, val);
        else
            update(2*node+1, mid+1, end, idx, val);
      
        tree[node]=max(tree[2*node],tree[2*node+1]);
    }
}
int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
        return 0;
    if(l <= start and end <= r)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return max(p1,p2);
}
int mst_cont_edge(int u,int v)
{
	int maxi=0;
	int f1=top[u],f2=top[v];
	while(f1!=f2)
	{
		if(depth_array[f1]<depth_array[f2])
        {
            swap(f1, f2);
            swap(u, v);
        }
        maxi=max(maxi,query(1,0,pos-1,edge_idx[f1],edge_idx[u]));
        u=parent_mst[f1];f1=top[u];
	}
	if(u==v)
		return maxi;
	if(depth_array[u]>depth_array[v])
		swap(u,v);
	return(max(maxi,query(1,0,pos-1,edge_idx[child[u]],edge_idx[v])));
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
void process(int u,int v,int w)
{
	get<0>(e[cnt])=v;
	get<2>(e[cnt])=w;
	get<1>(e[cnt])=head_to[u];
	head_to[u]=cnt++;
}
//construct heavy paths
void dfs1(int u,int par,int d)
{
	parent_mst[u]=par;sz_mst[u]=1;depth_array[u]=d;
	for(int i=head_to[u];i!=-1;i=get<1>(e[i]))
	{
		int v=get<0>(e[i]);
		if(v==par)continue;
		dfs1(v,u,d+1);
		sz_mst[u]+=sz_mst[v];
		if(child[u]==-1)
			child[u]=v;
		else if(sz_mst[v]>sz_mst[child[u]])
			child[u]=v;
	}

}
void dfs2(int u,int ancenstor)
{
    top[u]=ancenstor;
    if(child[u]!=-1)
    {
    	edge_idx[u]=pos++;
    	chd_edge_idx[edge_idx[u]]=u;
    	dfs2(child[u],ancenstor);

    }
    else
    {
    	edge_idx[u]=pos++;
    	chd_edge_idx[edge_idx[u]]=u;
    	return;

    }
    for(int i=head_to[u];i!=-1;i=get<1>(e[i]))
    {
    	int v=get<0>(e[i]);
    	if(v!=parent_mst[u]&&v!=child[u])
    		dfs2(v,v);
    }
}
long long kruskal()
{long long weight_sum_mst=0;
	sort(edges.begin(),edges.end(),sortbythird);
	int ctr1=0,p,q;
	for(int i=0;i<m;i++)
	{
		 p=root(get<0>(edges[i]));q=root(get<1>(edges[i]));
		if(p!=q)
		{
			if(sz[p]<sz[q])
		    {parent[p]=q;sz[q]+=sz[p];}
	        else
		    {parent[q]=p;sz[p]+=sz[q];}
			weight_sum_mst+=get<2>(edges[i]);
			mst.push_back(make_tuple(get<0>(edges[i]),get<1>(edges[i]),get<2>(edges[i])));	
			ctr1++;
		}
		if(ctr1==n-1)
			break;
	}
	return weight_sum_mst;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edges.push_back(make_tuple(u,v,w));
		original.push_back(make_tuple(u,v,w));		
	}
	for(int i=1;i<=n;i++)
	{
		parent[i]=i;
		sz[i]=1;
	}
	long long weight_sum_mst=kruskal();
	cnt=0;pos=0;memset(head_to,-1,sizeof(head_to));memset(child,-1,sizeof(child));
	for(int i=0;i<mst.size();i++)
	{
		int u=get<0>(mst[i]),v=get<1>(mst[i]),w=get<2>(mst[i]);
		process(u,v,w);
		process(v,u,w);

	}

	dfs1(1,-1,0);
	dfs2(1,1);
	memset(tree,0,sizeof(tree));
	for(int i=0;i<mst.size();i++)
	{
		int u=get<0>(mst[i]),v=get<1>(mst[i]),w=get<2>(mst[i]);
		if(depth_array[u]>depth_array[v])swap(u,v);
		update(1,0,pos-1,edge_idx[v],w);

	}
	for(int i=0;i<m;i++)
	{
		int u=get<0>(original[i]),v=get<1>(original[i]),w=get<2>(original[i]);
		int maxi=mst_cont_edge(u,v);
		cout<<weight_sum_mst+w-maxi<<endl;
	}


}