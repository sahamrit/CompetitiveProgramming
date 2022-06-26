#include<iostream>
#include<list>
using namespace std;
const int N=9;

struct edge{
int length;
int src;
int dest;
};
struct vertices
{    int index;
    int key;
    list<edge> ed;
};


class minheap
{public:
    int h_size;
    int capacity;
    vertices * vertex;
    int *pos;

    minheap(int cap)
    {
        capacity=cap;
        h_size=0;
        vertex=new vertices[cap];
        pos=new int[cap];
    }
    int parent (int i)
    {return (i-1)/2;}

    int left(int i)
    {return 2*i+1;}

   int & sizeofheap()
   {
       return h_size;
   }

    int right (int i)
   {

    return 2*i+2;
   }

    void h_insert(vertices v)
    {if(h_size==capacity)
    cout<<"heap overflow";
    else if(h_size==0)
    {

        vertex[h_size++]=v;
        pos[v.index]=0;
    }
    else {

        vertex[h_size++]=v;
        pos[v.index]=h_size-1;
        int i=h_size-1;
        while(i!=0&&vertex[i].key < vertex[parent(i)].key)
         {
               swap(vertex[i],vertex[parent(i)]);
               pos[vertex[i].index]=i;
               pos[vertex[parent(i)].index]=parent(i);
               i=parent(i);


         }
       }
    }
    void minheapify(int i)
    { int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < h_size && vertex[l].key < vertex[i].key)
        smallest = l;
    if (r < h_size && vertex[r].key < vertex[smallest].key)
        smallest = r;
    if (smallest != i)
       {
        swap(vertex[smallest],vertex[i]);
        pos[vertex[smallest].index]=smallest;
        pos[vertex[i].index]=i;
        minheapify(smallest);
       }

    }

    vertices extractmin()
    {vertices v=vertex[0];
    swap(vertex[0],vertex[h_size-1]);
    pos[vertex[0].index]=0;
    pos[vertex[h_size-1].index]=h_size-1;
    h_size--;
    minheapify(0);
        return v;
    }
    void decrease_key(int i,int p)
    {
        vertex[i].key=p;
        while(i!=0&&vertex[i].key < vertex[parent(i)].key)
         {
               swap(vertex[i],vertex[parent(i)]);
                pos[vertex[i].index]=i;
               pos[vertex[parent(i)].index]=parent(i);
               i=parent(i);
         }

    }

    void deletevertex(int i)
    { decrease_key(i,INT_MIN);
    extractmin();

    }

};




class graph
{int v;
 vertices* arr;
 public:
 graph(int vert)
 {
     v=vert;
     arr=new vertices[v];
 }
void dijkstras(int);
void addedge(int source,int destination,int len)
 {
     edge e;
     e.length=len;
     e.src=source;
     e.dest=destination;
     arr[source].ed.push_back(e);
     arr[destination].ed.push_back(e);
     arr[source].key=INT_MAX;
     arr[destination].key=INT_MAX;
     arr[source].index=source;
     arr[destination].index=destination;
 }

};
void graph::dijkstras(int s)
{
    minheap h(N);
    h.sizeofheap()=v;
    bool *visited=new bool[v];
    for(int i=0;i<v;i++ )
    {   h.vertex[i]=arr[i];
        visited[i]=false;
        h.pos[i]=i;
    }
arr[s].key=0;
h.vertex[s].key=0;
for(int i=v/2-1;i>=0;i--)
    h.minheapify(i);

while(h.h_size!=0)
{
    int u;

    vertices ve=h.extractmin();
    u=ve.index;

    visited[u]=true;


    list<edge>::iterator it;
    edge *temp=NULL;
    int mini=INT_MAX;
for(it=arr[u].ed.begin();it!=arr[u].ed.end();it++)
{

    if(it->dest!=u){if(visited[it->dest]){
        if(mini>it->length)
            {  mini=it->length;
                temp=&(*it);

                }
        }}else if(it->src!=u){if(visited[it->src]){
        if(mini>it->length)
            {mini=it->length;
                temp=&(*it);

                }
    }
}}
if(temp!=NULL){
if(temp->dest!=u)
{
    cout<<temp->dest<<"-"<<u<<endl;
}else if(temp->src!=u)
{
    cout<<temp->src<<"-"<<u<<endl;
}
}
    for(it=arr[u].ed.begin();it!=arr[u].ed.end();it++)
    {
        if(it->dest!=u){if((!visited[it->dest])&& ((it->length)<(arr[it->dest].key)))

                    {arr[it->dest].key=it->length ;

                    h.decrease_key(h.pos[arr[it->dest].index],arr[it->dest].key);

                    }
                    }
                    else{if((!visited[it->src])&& ((it->length)<(arr[it->src].key)))
                    {arr[it->src].key=it->length ;

                    h.decrease_key(h.pos[arr[it->src].index],arr[it->src].key);
                    }

                    }
    }


}}


int main()
{graph g(9);

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

   g.dijkstras(0);


}
