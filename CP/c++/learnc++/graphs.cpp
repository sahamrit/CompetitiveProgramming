#include<iostream>
#include<vector>
using namespace std;

struct edge{int src;
int dest;

};
struct vertex{int index;
vector <edge> v;
};


class graph{
public:
    int no_vertex;
    int no_edges;
    edge * edge_list;
    vertex *vertex_list;

    graph(int n,int m ){
    no_vertex=n;
    no_edges=m;
    edge_list=new edge[m];
    vertex_list=new vertex[n];


    }
    void addedge(int v1,int v2)
    {
        static int ctr=0;
        vertex_list[v1].index=v1;
        vertex_list[v2].index=v2;
        edge_list[ctr].src=v1;
        edge_list[ctr].dest=v2;
        vertex_list[v1].v.push_back(edge_list[ctr]);
        vertex_list[v2].v.push_back(edge_list[ctr]);
    ctr++;
    }


};
int main(){
int m,n;
cout<<"enter no of edges and no of vertices\n";
cin>>m>>n;
graph g(n,m);
g.addedge(0,2);
g.addedge(0,1);
cout<<g.edge_list[1].dest;




}
