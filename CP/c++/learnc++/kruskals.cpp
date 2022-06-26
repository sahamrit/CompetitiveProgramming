#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int *SIZE;
struct edge{
int src;
int dest;
int length;
};
struct vertex{
int index;
list<edge> adj_edge;
};
class graph
{
private:
    int no_vertices;
    int no_edges;
    vertex * arr_vertices;
    edge *arr_edges;
public:
    graph(int v,int m)
    {
        no_vertices=v;
        no_edges=m;
        arr_vertices=new vertex[v];
        arr_edges=new edge[m];
    }
    void addedge(int&,int,int ,int);
    void kruskals();
};
void graph::addedge(int &ctr,int m,int n,int l)
{arr_edges[ctr].src=m;
arr_edges[ctr].dest=n;
arr_edges[ctr].length=l;
arr_vertices[m].adj_edge.push_back(arr_edges[ctr]);
arr_vertices[n].adj_edge.push_back(arr_edges[ctr]);
ctr++;
}
void initialize(int *ar,int v)
{
    for(int i=0;i<v;i++)
        ar[i]=i;
}
int root(int *ar,int i)
{
    while(i!=ar[i])
    {
        ar[i]=ar[ar[i]];
        i=ar[i];
    }
}
bool connected(int *ar,int p,int q)
{
    if(root(ar,p)==root(ar,q))
        return true;
    else return false;
}
void union_(int *ar,int p,int q)
{
    if(SIZE[p]<=SIZE[q]){ar[root(ar,p)]=root(ar,q);
        SIZE[q]+=SIZE[p];
    }else
    {ar[root(ar,q)]=root(ar,p);
        SIZE[p]+=SIZE[q];
    }
}
int comp(const void *a,const void *b)
{
    edge*p=(edge *)a;
    edge*q=(edge *)b;
    return p->length-q->length;
}
void graph::kruskals()
{
    int *arr_uf;
    arr_uf=new int[no_vertices];
    SIZE=new int [no_edges];
    for(int i=0;i<no_vertices;i++)
    {arr_uf[i]=i;
    SIZE[i]=1;
    }
    qsort((void*)arr_edges,no_edges,sizeof(edge),comp);
    for(int i=0;i<no_edges;i++)
    {
        if(!connected(arr_uf,arr_edges[i].dest,arr_edges[i].src))
        {cout<<arr_edges[i].src<<"-"<<arr_edges[i].dest<<endl;
        union_(arr_uf,arr_edges[i].dest,arr_edges[i].src);

        }
    }
}
int main()
{
    int ctr=0;
    graph g(9,14);
    g.addedge(ctr, 0, 1, 4);
    g.addedge(ctr, 0, 7, 8);
    g.addedge(ctr, 1, 2, 8);
    g.addedge(ctr, 1, 7, 11);
    g.addedge(ctr, 2, 3, 7);
    g.addedge(ctr, 2, 8, 2);
    g.addedge(ctr, 2, 5, 4);
    g.addedge(ctr, 3, 4, 9);
    g.addedge(ctr, 3, 5, 14);
    g.addedge(ctr, 4, 5, 10);
    g.addedge(ctr, 5, 6, 2);
    g.addedge(ctr, 6, 7, 1);
    g.addedge(ctr, 6, 8, 6);
    g.addedge(ctr, 7, 8, 7);
    g.kruskals();
}
