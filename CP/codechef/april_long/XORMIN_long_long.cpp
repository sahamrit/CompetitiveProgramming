#include<bits/stdc++.h>
using namespace std;
vector<vector<long long int> >adj;

vector<long long int>a(200001);
vector<string>abit(200001);
vector<long long int>time_in(200001);
vector<long long int>time_out(200001);
vector<bool>visited;
vector<long long int>euler;

struct trie
{
	trie *child[2];
	trie()
	{
		for(long long int i=0;i<2;++i)
			child[i] = NULL;
	}
};
void insert(trie *root, long long int i,string s)
{
	for(; i<20;++i)
	{
		long long int pos = s[i] - '0';
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
vector<unordered_map<long long int,long long int> >t;

void build(vector<long long int> a, long long int v, long long int tl, long long int tr) {
    if (tl == tr) {
        t[v][a[euler[tl]]]=euler[tl];
    } else { 
        long long int tm = (tl + tr) / 2;
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
long long int query(long long int v, long long int tl, long long int tr, long long int l, long long int r, long long int x) {
    if (l > r)
        return  LLONG_MAX;
    if (l == tl && r == tr) {
        	if(t[v].find(x)==t[v].end())
        		return LLONG_MAX;
        	return t[v][x];
    }
    long long int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm), x), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r, x));
}
string xormax(trie* root, string query) 
{ 
    string ans(query.begin(),query.end());
	for(long long int i=0; i<20;++i)
	{
		long long int pos = query[i] - '0';
		if(root==NULL )
			break;
		if(root->child[1]==NULL && root->child[0]==NULL)
			break;
		if(pos==0)
		{
			if(root->child[1]!=NULL)
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
			if(root->child[0]!=NULL)
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
long long int bits2integer(string bitString){
     long long int ret = 0;
     for(long long int i = 0; i < 20; i++)
          if(bitString[i] == '1')
            ret |= 1 << (19-i);

     return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long int testcase,n,q,x,y,a1,b,k;cin>>testcase;
	long long int xl=0,vl=0;
	string ans,query1;
	while(testcase--)
	{
		cin>>n>>q;
		visited.resize(n+1);fill(visited.begin(),visited.end(),false);
		adj.clear();adj.resize(n+1);		
		euler.clear();
		t.clear();t.resize(8*(n+1));
		trienode.clear();trienode.resize(n+1);
		for(long long int i=1;i<=n;i++)
			{
				cin>>a[i];
				abit[i]=bitset<20>(a[i]).to_string();
			}	
		for(long long int i=1;i<n;i++)
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
			query1=bitset<20>(k).to_string();
			if(vl>n || vl<=0)continue;
			ans=xormax(&trienode[vl],query1);
			xl=bits2integer(ans);
			vl=query(1,time_in[1],time_out[1],time_in[vl],time_out[vl],xl);		
			xl=xl^k;
			cout<<vl<<" "<<xl<<endl;

		}		

	}
}