#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >adj;

int a[200001];
string abit[200001];
int time_in[200001];
int time_out[200001];
vector<bool>visited;
vector<int>euler;

vector<unordered_map<int,int> >t;

struct trie
{
	trie *child[2];
	int mark;
	trie()
	{
		for(int i=0;i<2;++i)
			child[i] = NULL;
		mark=-1;
	}	
	trie(int t)
	{
		for(int i=0;i<2;++i)
			child[i] = NULL;
		mark=t;
	}
};
trie main_trie;
void insert(trie *root, int mark,string s)
{
	for(int i=0; i<20;++i)
	{
		int pos = s[i] - '0';
		if(root->child[pos] == NULL)
			root->child[pos] = new trie(mark);
		root = root->child[pos];
	}
}
void dfs_init(int u,int p)
{
	visited[u]=true;
	insert(&main_trie,u,abit[u]);			
	time_in[u]=euler.size();	
	euler.push_back(u);
	for(auto v:adj[u])
	{
		if(v==p)continue;
		if(visited[v])continue;
		dfs_init(v,u);
	}
	time_out[u]=euler.size()-1;

	
}
bool isancestor(int u,int v)
{
	return (time_in[u]<=time_in[v])&&(time_out[u]>=time_out[v]);
}
void build(int a[], int v, int tl, int tr) {
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
string xormax(trie* root, int mark,string query) 
{ 
    string ans=query;
	for(int i=0; i<20;++i)
	{
		int pos = query[i] - '0';
		if(root==NULL )
			break;
		if(root->child[1]==NULL && root->child[0]==NULL)
			break;
		if(pos==0)
		{
			if(root->child[1]!=NULL && isancestor(mark,root->child[1]->mark))
			{
				root=root->child[1];
				ans[i]='1';
			}
			else
			{
				root=root->child[0];
				ans[i]='0';
			}
		}
		else
		{
			if(root->child[0]!=NULL && isancestor(mark,root->child[0]->mark))
			{
				root=root->child[0];
				ans[i]='0';
			}
			else
			{
				root=root->child[1];
				ans[i]='1';
			}			
		}
	}    
 	return ans;
}
int bits2Integer(string bitString){
     int ret = 0;
     for(int i = 0; i < 20; i++)
          if(bitString[i] == '1')
            ret |= 1 << (19-i);

     return ret;
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
		visited.resize(n+1);
		fill(visited.begin(),visited.end(),false);
		adj.clear();adj.resize(n+1);		
		euler.clear();
		t.clear();t.resize(8*(n+1));
		main_trie.child[0]=main_trie.child[1]=NULL;
		main_trie.mark=1;
		for(int i=1;i<=n;i++)
			{
				cin>>a[i];
				abit[i]=bitset<20>(a[i]).to_string();				
			}	
		for(int i=1;i<n;i++)
		{
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}		
		dfs_init(1,-1);
		xl=vl=0;
		build(a,1,time_in[1],time_out[1]);
		while(q--)
		{
			cin>>a1>>b;
			vl=a1^vl;k=b^xl;
			query1=bitset<20>(k).to_string();	
			ans=xormax(&main_trie,vl,query1);
			xl=bits2Integer(ans);
			vl=query(1,time_in[1],time_out[1],time_in[vl],time_out[vl],xl);		
			xl=xl^k;
			cout<<vl<<" "<<xl<<"\n";

		}		

	}
}