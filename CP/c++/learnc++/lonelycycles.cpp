#include<bits/stdc++.h>
using namespace std;
#define NIL -1
struct nodes
{
    list<int>adjlistofedges;
    int index;

};

struct edges
{
    int index;
    int v1,v2;
    bool edgeifincycle;
};
class Graph
{
    public:
    int no_of_vertices,no_of_edges;
    nodes * nodearray;
    edges * edgearray;
    int root;

    Graph(int n,int m):no_of_vertices(n),no_of_edges(m)
    {
        nodearray =new nodes[no_of_vertices];
        for(int i=0;i<no_of_vertices;i++)
        {
            nodearray[i].index=i;
        }
        edgearray=new edges[no_of_edges];
        for(int i=0;i<no_of_edges;i++)
        {
            edgearray[i].index=i;
            edgearray[i].edgeifincycle=true;
        }

    }

    void addEdge(int m,int n,int ctr)
    {


        nodearray[m-1].adjlistofedges.push_back(ctr);
        nodearray[n-1].adjlistofedges.push_back(ctr);

        edgearray[ctr].v1=m-1;
        edgearray[ctr].v2=n-1;

    }
    void bridge();
    void bridgeUtil(int , bool *, int *,int *, int *);
    void lonely_cycles();
    void dfs(int ,bool *,stack <int>&);
    void graphbreak(int,int ,Graph &,bool *,bool *,bool *);
    void DFSUtil(int , bool *);


};
//function used from geeksforgeeks https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
void Graph::dfs(int u, bool visited[],stack<int>&s)
{
    visited[u] = true;

   if(nodearray[u].adjlistofedges.size()==1)
       s.push(u);
    list<int>::iterator it;
    for (it = nodearray[u].adjlistofedges.begin(); it !=nodearray[u].adjlistofedges.end(); ++it)
        {
            int v ;
        if(edgearray[*it].v1==u)
            v=edgearray[*it].v2;
        else
            v=edgearray[*it].v1;

            if (!visited[v])
            dfs(v, visited,s);


        }
}
//FUNCTION USED FROM GEEKSFORGEEKS https://www.geeksforgeeks.org/bridge-in-a-graph/
void Graph::bridgeUtil(int u, bool visited[], int disc[],
                                  int low[], int parent[])
{

    static int time = 0;

    visited[u] = true;

    disc[u] = low[u] = ++time;

    list<int>::iterator it;
    for (it = nodearray[u].adjlistofedges.begin(); it !=nodearray[u].adjlistofedges.end(); ++it)
    {
        int v ;
        if(edgearray[*it].v1==u)
            v=edgearray[*it].v2;
        else
            v=edgearray[*it].v1;





        if (!visited[v])
        {
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent);

            low[u]  = min(low[u], low[v]);


            if (low[v] > disc[u])
             {edgearray[*it].edgeifincycle=false;
             }
        }

        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);

    }

}
//FUNCTION USED FROM GEEKSFORGEEKS https://www.geeksforgeeks.org/bridge-in-a-graph/
void Graph::bridge()
{
    bool *visited = new bool[no_of_vertices];
    int *disc = new int[no_of_vertices];
    int *low = new int[no_of_vertices];
    int *parent = new int[no_of_vertices];

    for (int i = 0; i < no_of_vertices; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
    }

    for (int i = 0; i < no_of_vertices; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent);


}
void Graph::graphbreak(int counter,int l,Graph &g,bool *visited1,bool *visitededges,bool *dfsvertexdone)
{
     visited1[l] = true;
      dfsvertexdone[l]=true;


    list<int>::iterator it;
    for (it = nodearray[l].adjlistofedges.begin(); it !=nodearray[l].adjlistofedges.end(); ++it)
        {
            int v ;
        if(edgearray[*it].v1==l)
            v=edgearray[*it].v2;
        else
            v=edgearray[*it].v1;

            if(!visited1[v])
        {
          if(counter==1 && edgearray[*it].edgeifincycle )
            continue;
          if(edgearray[*it].edgeifincycle)
            counter++;

            g.addEdge(l+1,v+1,edgearray[*it].index);


            visitededges[edgearray[*it].index]=true;
            graphbreak(counter,v,g,visited1,visitededges,dfsvertexdone);


        }


        }





}
void Graph::DFSUtil(int u, bool visited[])
{
    // Mark the current node as visited and
    // print it
    visited[u] = true;
    cout << u << " ";

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator it;
     for (it = nodearray[u].adjlistofedges.begin(); it !=nodearray[u].adjlistofedges.end(); ++it)
        {
            int v ;
        if(edgearray[*it].v1==u)
            v=edgearray[*it].v2;
        else
            v=edgearray[*it].v1;
            if(!visited[v])
        {

            DFSUtil(v,visited);


        }


        }


}
void Graph::lonely_cycles()
{
    bridge();
    bool * dfsdonevertex;
    dfsdonevertex=new bool[no_of_vertices];
    for(int i=0;i<no_of_vertices;i++)
        dfsdonevertex[i]=false;
    stack<int> s;
    bool *visited1=new bool[no_of_vertices];
    bool *visitededges=new bool[no_of_vertices];
    for(int i=0;i<no_of_edges;i++)
    {
     visitededges[i]=false;
    }
    for(int i=0;i<no_of_vertices;i++)
        visited1[i]=false;
    dfs(0,visited1,s);
    vector<Graph> trees;


   if(s.size()!=0)
   {
       while(s.size()!=0)
       {Graph g1(no_of_vertices,no_of_edges);
           int l=s.top();
           s.pop();
           if(!dfsdonevertex[l])
           {for(int i=0;i<no_of_vertices;i++)
               visited1[i]=false;
               g1.root=l;
            graphbreak(0,l,g1,visited1,visitededges,dfsdonevertex);
             trees.push_back(g1);
           }


       }
   }

   for(int i=0;i<no_of_vertices;i++)
   {
       if(!dfsdonevertex[i])
       {Graph g1(no_of_vertices,no_of_edges);

           if(!dfsdonevertex[i])
           {for(int i=0;i<no_of_vertices;i++)
               visited1[i]=false;
               g1.root=i;

            graphbreak(0,i,g1,visited1,visitededges,dfsdonevertex);
           }

           trees.push_back(g1);

       }


   }



   for(int i=0;i<no_of_edges;i++)
   {
       if(!visitededges[i])
       {
           Graph g1(no_of_vertices,no_of_edges);

           for(int i=0;i<no_of_vertices;i++)
               visited1[i]=false;

            visited1[edgearray[i].v1]=true;
            g1.addEdge(edgearray[i].v1+1,edgearray[i].v2+1,edgearray[i].index);
             visitededges[edgearray[i].index]=true;


               g1.root=edgearray[i].v1;
               if(edgearray[i].edgeifincycle)
            graphbreak(1,edgearray[i].v2,g1,visited1,visitededges,dfsdonevertex);
            else
                graphbreak(0,edgearray[i].v2,g1,visited1,visitededges,dfsdonevertex);

           trees.push_back(g1);
       }

   }


   for(int i=0;i<trees.size();i++)
   {
      for(int i=0;i<no_of_vertices;i++)
               visited1[i]=false;
       trees[i].DFSUtil(trees[i].root,visited1);
       cout<<endl;
   }

}
int main()
{
    int testcases;
    cin>>testcases;
    for(int i=0;i<testcases;i++)
    {
        int n, m;
        cin>>n>>m;
        Graph g(n,m);
       for(int j=0;j<m;j++)
       {
           int u, v;
           cin>>u>>v;
           g.addEdge(u,v,j);

       }
       g.lonely_cycles();
       cout<<endl;

    }





    return 0;
}
