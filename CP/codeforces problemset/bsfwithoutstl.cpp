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
struct  queue_
{
	node *head,*tail;
	void pushback(int val)
	{
		if(head==NULL && tail==NULL)
		{
			node *temp=Newnode(val);
			head=tail=temp;
		}
		else
		{
			node *temp=Newnode(val);
			tail->next=temp;
			tail=temp;
		}
	}
	int front()
	{
		if(head==NULL)cout<<"empty queue_"<<endl;
		else return head->nodeidx;
	}
	bool isnull()
	{
		return (head==NULL&&tail==NULL);
	}
	void pop()
	{
		if(isnull())return;
		if(head==tail)
		{
			free(head);
			head=tail=NULL;
			return;
		}
		node *temp=head;
		head=head->next;
		free(temp);
	}

};
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
void bfs(int v,node **g,queue_ &Q,bool visited[])
{
	Q.pushback(v);
	visited[v]=true;
	cout<<v<<" is visited"<<endl;
	while(!Q.isnull())
	{
		int u=Q.front();
		Q.pop();
		node *temp=g[u];
		while(temp!=NULL)
		{
			if(!visited[temp->nodeidx])
			{
				cout<<temp->nodeidx<<" is visited"<<endl;
				visited[temp->nodeidx]=true;
				Q.pushback(temp->nodeidx);
			}
			temp=temp->next;
		}
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
	queue_ Q;
	Q.head=Q.tail=NULL;
	bfs(1,g,Q,visited);

}

 