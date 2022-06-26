#include<iostream>
#include<list>
#include<queue>
using namespace std;
struct edge{
    int length;
    int src;
    int dest;};
struct vertex{
    int index;
    int key;
    bool visited;
    list<edge> edge_list;
};

struct comparator{
    bool operator()(const vertex &p,const vertex &q){
    return p.key>q.key;
    }
};

class graph{
public:
    int no_vertex;
    vertex* vertex_list;
         graph(int n){
    no_vertex=n;
    vertex_list=new vertex[n];
    }

    void addedge(int m,int n,int l){
        edge temp;
        temp.src=m;
        temp.dest=n;
        temp.length=l;
        vertex_list[m].index=m;
        vertex_list[n].index=n;
        vertex_list[m].visited=false;
        vertex_list[n].visited=false;
        vertex_list[m].key=INT_MAX;
        vertex_list[n].key=INT_MAX;
        vertex_list[m].edge_list.push_back(temp);
        vertex_list[n].edge_list.push_back(temp);

    }
void dijkstras(int s){

priority_queue<vertex,vector<vertex>,comparator> h;
vertex_list[s].key=0;
h.push(vertex_list[s]);
while(!h.empty())
{
    vertex temp;
    temp=h.top();
    h.pop();
    int u;
    u=temp.index;
    vertex_list[u].visited=true;


    list<edge>:: iterator it;
    for(it=vertex_list[u].edge_list.begin();it!=vertex_list[u].edge_list.end();it++){
        if((*it).src!=u && !vertex_list[(*it).src].visited)
        {
            if(vertex_list[(*it).src].key>vertex_list[u].key+(*it).length)
            vertex_list[(*it).src].key=vertex_list[u].key+(*it).length;
            h.push(vertex_list[(*it).src]);

        }
        if((*it).dest!=u && !vertex_list[(*it).dest].visited)
        {
            if(vertex_list[(*it).dest].key>vertex_list[u].key+(*it).length)
            vertex_list[(*it).dest].key=vertex_list[u].key+(*it).length;
            h.push(vertex_list[(*it).dest]);
        }
    }


}
cout<<"shortest distance from"<<s<<":"<<endl;
for(int i=0;i<no_vertex;i++)
{cout<<vertex_list[i].index<<":"<<vertex_list[i].key<<endl;

}

}



};
int main(){
graph g(9);
g.addedge( 0, 1, 4);
    g.addedge( 0, 7, 8);
    g.addedge( 1, 2, 8);
    g.addedge( 1, 7, 11);
    g.addedge( 2, 3, 7);
    g.addedge( 2, 8, 2);
    g.addedge( 2, 5, 4);
    g.addedge( 3, 4, 9);
    g.addedge( 3, 5, 14);
    g.addedge( 4, 5, 10);
    g.addedge( 5, 6, 2);
    g.addedge( 6, 7, 1);
    g.addedge( 6, 8, 6);
    g.addedge( 7, 8, 7);
g.dijkstras(6);

}



