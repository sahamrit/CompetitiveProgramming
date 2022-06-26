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
	int time;
	trie()
	{
		for(int i=0;i<2;++i)
			child[i] = NULL;
		time=-1;
	}	
	trie(int t)
	{
		for(int i=0;i<2;++i)
			child[i] = NULL;
		time=t;
	}
};
vector<trie>trienode;
void insert(trie *root, int time,string s)
{
	for(int i=0; i<20;++i)
	{
		int pos = s[i] - '0';
		if(root->child[pos] == NULL)
			root->child[pos] = new trie(time);
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

void dfs_merge(int u,int p)
{
	visited[u]=true;
	for(auto v:adj[u])
	{
		if(v==p)continue;
		if(visited[v])continue;
		dfs_merge(v,u);
		merge_(&trienode[u],&trienode[v]);
	}

}
void dfs_init(int u,int p)
{
	visited[u]=true;
	time_in[u]=euler.size();	
	euler.push_back(u);
	for(auto v:adj[u])
	{
		if(v==p)continue;
		if(visited[v])continue;
		dfs_init(v,u);
	}
	time_out[u]=euler.size()-1;
	trienode[u].time=time_out[u];
	insert(&trienode[u],time_out[u],abit[u]);	
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
string xormax(trie* root, string query) 
{ 
    string ans=query;
    int curr_time=root->time;
	for(int i=0; i<20;++i)
	{
		int pos = query[i] - '0';
		if(root==NULL )
			break;
		if(root->child[1]==NULL && root->child[0]==NULL)
			break;
		if(pos==0)
		{
			if(root->child[1]!=NULL && curr_time>=root->child[1]->time)
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
			if(root->child[0]!=NULL && curr_time>=root->child[0]->time)
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
		trienode.clear();trienode.resize(n+1);
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
		fill(visited.begin(),visited.end(),false);		
		dfs_merge(1,-1);
		xl=vl=0;
		build(a,1,time_in[1],time_out[1]);
		while(q--)
		{
			cin>>a1>>b;
			vl=a1^vl;k=b^xl;
			query1=bitset<20>(k).to_string();	
			ans=xormax(&trienode[vl],query1);
			xl=bits2Integer(ans);
			vl=query(1,time_in[1],time_out[1],time_in[vl],time_out[vl],xl);		
			xl=xl^k;
			cout<<vl<<" "<<xl<<"\n";

		}		

	}
}