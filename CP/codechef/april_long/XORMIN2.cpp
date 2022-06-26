#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >adj;

vector<int>a(200001);
vector<string>abit(200001);
vector<int>time_in(200001);
vector<int>time_out(200001);
vector<bool>visited;
vector<int>euler;

struct trie
{
	trie *child[2];
	trie()
	{
		for(int i=0;i<2;++i)
			child[i] = NULL;
	}
};
void insert(trie *root, int i,string s)
{
	for(; i<21;++i)
	{
		int pos = s[i] - '0';
		if(root->child[pos] == NULL)
			root->child[pos] = new trie;
		root = root->child[pos];
	}
}
void merge_(trie *mergeto,trie *mergefrom)
{

	if(mergefrom->child[0]==NULL && mergefrom->child[1]==NULL)
		return;

	if(mergefrom->child[0]!=NULL)
		{
			if(mergeto->child[0]==NULL)
			{
				mergeto->child[0]=mergefrom->child[0];
			}
			else
				merge_(mergeto->child[0],mergefrom->child[0]);
		}

	if(mergefrom->child[1]!=NULL)
		{
			if(mergeto->child[1]==NULL)
			{
				mergeto->child[1]=mergefrom->child[1];
			}
			else
				merge_(mergeto->child[1],mergefrom->child[1]);
		}			
	
}
vector<trie>trienode;

void dfs(long long int u,long long int p)
{
	visited[u]=true;
	time_in[u]=euler.size();	

	insert(&trienode[u],0,abit[u]);
	euler.push_back(u);
	for(auto v:adj[u])
	{
		if(v==p)continue;
		if(visited[v])continue;
		dfs(v,u);
		merge_(&trienode[u],&trienode[v]);
		euler.push_back(u);
	}
	time_out[u]=euler.size()-1;
}
vector<unordered_map<int,int> >t;

void build(vector<int> a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v][a[euler[tl]]]=euler[tl];
    } else { 
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v].insert(t[v*2].begin(),t[2*v].end());
        for(auto u:t[2*v+1])
        {
        	if(t[v].find(u.first)==t[v].end())
        	{
        		t[v].insert(make_pair(u.first,u.second));
	       	}
	       	else 
	       	{
	       		if(u.second < t[v][u.first])
	       			t[v][u.first]=u.second;
	       	}
        }
    }
}
int query(int v, int tl, int tr, int l, int r, int x) {
    if (l > r)
        return INT_MAX;
    if (l == tl && r == tr) {
        	if(t[v].find(x)==t[v].end())
        		return INT_MAX;
        	return t[v][x];
    }
    int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm), x), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r, x));
}
int xormax(trie*root,string arr)
{
	trie* temp=root;
	int val=0;
	for(int i=0;i<21;i++)
	{
		if(arr[i]){
			if(temp->child[0]!=NULL){
				temp=temp->child[0];
				val=val*2+1;
			}
			else
			{
				temp=temp->child[1];
				val=2*val;
			}
		}
		else
		{
			if(temp->child[1]!=NULL){
				temp=temp->child[1];
				val=val*2+1;
			}
			else
			{
				temp=temp->child[0];
				val=2*val;
			}	
		}
	}
	return val;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int testcase,n,q,x,y,a1,b,k;cin>>testcase;
	int xl=0,vl=0;
	string ans,query1;
	while(testcase--)
	{
		cin>>n>>q;
		visited.resize(n+1);fill(visited.begin(),visited.end(),false);
		adj.clear();adj.resize(n+1);		
		euler.clear();
		t.clear();t.resize(8*(n+1));
		trienode.clear();trienode.resize(n+1);
		for(int i=1;i<=n;i++)
			{
				cin>>a[i];
				abit[i]=bitset<21>(a[i]).to_string();
			}	
		for(int i=1;i<n;i++)
		{
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}		
		dfs(1,-1);
		xl=vl=0;
		build(a,1,time_in[1],time_out[1]);
		while(q--)
		{
			cin>>a1>>b;
			vl=a1^vl;k=b^xl;
			query1=bitset<21>(k).to_string();
			xl=xormax(&trienode[vl],query1);
			vl=query(1,time_in[1],time_out[1],time_in[vl],time_out[vl],xl);		
			xl=xl^k;
			cout<<vl<<" "<<xl<<endl;

		}		

	}
}