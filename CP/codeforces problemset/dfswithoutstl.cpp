#include<bits/stdc++.h>
using namespace std;
struct node
{
	int nodeidx;
	node *next;
};
struct Edge
{
	int src,dest;
};
node *Newnode(int val)
{
	node *temp=new node;
	temp->nodeidx=val;
	temp->next=NULL;
	return temp;
}
node *insert(node *head,int val)
{
	node *temp=Newnode(val);
	temp->next=head;
	head=temp;
	return head;
}
node **init(int n,Edge edges[],int m)
{
	node **g=new node*[n];

	cout<<m<<endl;
	for(int i=0;i<m;i++)
	{
		g[edges[i].src]=insert(g[edges[i].src],edges[i].dest);
		g[edges[i].dest]=insert(g[edges[i].dest],edges[i].src);		
	}
	return g;
}
void dfs(int v,node **g,bool visited[])
{
	node *temp=g[v];
	if(temp==NULL)return;
	while(temp!=NULL)
	{
		if(!visited[temp->nodeidx]){
			cout<<temp->nodeidx<<"is visited"<<endl;
			visited[temp->nodeidx]=true;
			dfs(temp->nodeidx,g,visited);
		}	
		temp=temp->next;
	}
}
int main()
{
	Edge edges[] =
	    {
	        // pair (x, y) represents edge from x to y
	        { 0, 1 }, { 1, 2 }, { 2, 0 }, { 1, 5 },
	        { 5, 2 }, { 3, 2}, { 5, 4}
	    };
	int N=6;
	node** g;
	int m=sizeof(edges)/sizeof(edges[0]);	
	g=init(N,edges,m);
	//traverse the adjacency list
	for(int i=0;i<N;i++)
	{
		node *temp=g[i];
		cout<<"adj list of"<<i<<" ";
		while(temp!=NULL)
		{
			cout<<temp->nodeidx<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	bool *visited=new bool[N];
	for(int i=0;i<N;i++)
		visited[i]=false;
	visited[1]=true;
	cout<<"1 is visited"<<endl;
	dfs(1,g,visited);
}

 