#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int *SIZE;
struct cluster_ele{int parent;int index;int root;};
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
    void cluster(int);
};
void graph::addedge(int &ctr,int m,int n,int l)
{arr_edges[ctr].src=m;
arr_edges[ctr].dest=n;
arr_edges[ctr].length=l;
arr_vertices[m].adj_edge.push_back(arr_edges[ctr]);
arr_vertices[n].adj_edge.push_back(arr_edges[ctr]);
ctr++;
}

int root(cluster_ele *ar,int i)
{int x=i;
    while(i!=ar[i].parent)
    {
        ar[i].parent=ar[ar[i].parent].parent;
        i=ar[i].parent;
    }


    return i;
}
bool connected(cluster_ele *ar,int p,int q)
{
    if(root(ar,p)==root(ar,q))
        return true;
    else return false;
}
void union_(cluster_ele *ar,int p,int q)
{
    if(SIZE[p]<=SIZE[q]){ar[root(ar,p)].parent=root(ar,q);
        SIZE[q]+=SIZE[p];
    }else
    {ar[root(ar,q)].parent=root(ar,p);
        SIZE[p]+=SIZE[q];
    }
}
int comp(const void *a,const void *b)
{
    edge*p=(edge *)a;
    edge*q=(edge *)b;
    return p->length-q->length;
}
int compar(const void*a,const void*b)
{
    cluster_ele*p=(cluster_ele*)a;
    cluster_ele*q=(cluster_ele*)b;
    return p->root-q->root;

}
void graph::cluster(int k)
{int no_cluster=no_vertices;
    cluster_ele *arr_uf;
    arr_uf=new cluster_ele[no_vertices];
    SIZE=new int [no_edges];
    for(int i=0;i<no_vertices;i++)
    {arr_uf[i].index=i;
    arr_uf[i].parent=i;
    arr_uf[i].root=i;
    SIZE[i]=1;
    }
    qsort((void*)arr_edges,no_edges,sizeof(edge),comp);


    for(int i=0;i<no_edges&&no_cluster>k;i++)
    {
        if(!connected(arr_uf,arr_edges[i].dest,arr_edges[i].src))
        {
        union_(arr_uf,arr_edges[i].dest,arr_edges[i].src);

         no_cluster--;

        }
    }
    for(int i=0;i<no_vertices;i++)
        arr_uf[i].root=root(arr_uf,i);
    qsort((void*)arr_uf,no_vertices,sizeof(cluster_ele),compar);
    for(int i=0;i<no_vertices;i++)
    {
       if(arr_uf[i].root==arr_uf[i+1].root)
          cout<<arr_uf[i].index<<" ";
        else cout<<arr_uf[i].index<<endl;

    }
}
int main()
{
    int ctr=0;
    int k;
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
    cout<<"enter no of clusters"<<endl;
    cin>>k;
    g.cluster(k);
}
