
#include<bits/stdc++.h>

using namespace std;
#define NIL -1
struct nodes
{
    list<int>adjlistofedges;

    int numberofnodes;

};

struct edges
{
    int index;
    int v1,v2;
    long long int v1vertex,v2vertex;
    bool edgeifincycle;
 long long int score;
};
class Graph
{
    private:
    int no_of_vertices,no_of_edges;
    nodes * nodearray;
    list<int> *adj;

    int root;
    void bridgeUtil(int , bool *, int *,int *, int *);
  public:
     edges * edgearray;
    Graph(int n,int m):no_of_vertices(n),no_of_edges(m)
    {   adj = new list<int>[no_of_vertices];
        nodearray =new nodes[no_of_vertices];
        for(int i=0;i<no_of_vertices;i++)
        {
            nodearray[i].numberofnodes=0;
        }

        edgearray=new edges[no_of_edges];
        for(int i=0;i<no_of_edges;i++)
        {
            edgearray[i].index=i;
            edgearray[i].edgeifincycle=true;
               edgearray[i].score=0;
        }

    }

    void addEdge(int m,int n,int ctr)
    {
       adj[m-1].push_back(n-1);
       adj[n-1].push_back(m-1);
       nodearray[m-1].adjlistofedges.push_back(ctr);
        nodearray[n-1].adjlistofedges.push_back(ctr);

        edgearray[ctr].v1=m-1;
        edgearray[ctr].v2=n-1;



    }
    void bridge();

    void lonely_cycles();
    void dfs(int ,bool *,stack <int>&);
    void graphbreak(int,int ,Graph &,bool *,bool *,bool *,unordered_set<int>&);
    void dfstwo(int,Graph &,bool *,bool *,bool *,unordered_set<int>&);
    void DFSUtil(int , bool *,vector<unordered_set<int>>&,int,Graph *);
    void numberOfNodes(int ,int);
    void numberOfNodes1(int ,int);

};
//function used from geeksforgeeks https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
void Graph::dfs(int u, bool * visited,stack<int>&s)
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
void Graph::bridgeUtil(int u, bool *visited, int * disc,
                                  int *low, int* parent)
{

    static int time = 0;

    visited[u] = true;

    disc[u] = low[u] = ++time;

    list<int>::iterator it;
    for (it = adj[u].begin(); it != adj[u].end(); ++it)
    {
        int v=*it ;
        if (!visited[v])
        {
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent);

            low[u]  = min(low[u], low[v]);
            if (low[v] > disc[u])
             {
              edgearray[*it].edgeifincycle=false;
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

            delete []visited;
            delete []disc;
            delete []low;
            delete [] parent;


}
void Graph::graphbreak(int counter,int l,Graph &g,bool *visited1,bool *visitededges,bool *dfsvertexdone,unordered_set<int>&s)
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
            s.insert(edgearray[*it].index);
            graphbreak(counter,v,g,visited1,visitededges,dfsvertexdone,s);


        }


        }





}
void Graph::dfstwo(int l,Graph &g,bool *visited1,bool *visitededges,bool *dfsvertexdone,unordered_set<int>&s)
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
          if( edgearray[*it].edgeifincycle )
            continue;


            g.addEdge(l+1,v+1,edgearray[*it].index);


            visitededges[edgearray[*it].index]=true;
            s.insert(edgearray[*it].index);
            dfstwo(v,g,visited1,visitededges,dfsvertexdone,s);


        }
        }
}
void Graph::DFSUtil(int u, bool* visited,vector<unordered_set<int>>&edgesintree,int iteration,Graph *g)
{

    visited[u] = true;



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
           int p;
          for( p=0;p<iteration;p++)
          {
              if(edgesintree[p].find(edgearray[*it].index)!=edgesintree[p].end())
                   break;
          }
          int ctr=0;
          unordered_set<int>::iterator itt;
          if(p!=iteration)
         {


          for(itt=edgesintree[iteration].begin();itt!=edgesintree[iteration].end();itt++)
          {
              if(edgesintree[p].find(*itt)!=edgesintree[p].end())
               ctr++;

          }

         }
         g->edgearray[edgearray[*it].index].score+=edgearray[*it].v1vertex*edgearray[*it].v2vertex-ctr;


            DFSUtil(v,visited,edgesintree,iteration,g);




      }


     }


}
void Graph::numberOfNodes(int s, int e)
{
   list<int>:: iterator it;
    nodearray[s].numberofnodes=1;
    for (it = nodearray[s].adjlistofedges.begin(); it !=nodearray[s].adjlistofedges.end(); ++it)
    {
      {


         int v ;
        if(edgearray[*it].v1==s)
            v=edgearray[*it].v2;
        else
            v=edgearray[*it].v1;

        if (v== e)
            continue;


        numberOfNodes(v, s);


        nodearray[s].numberofnodes += nodearray[v].numberofnodes;
      }
    }

}
void Graph::numberOfNodes1(int s, int e)
{
   list<int>:: iterator it;

    for (it = nodearray[s].adjlistofedges.begin(); it !=nodearray[s].adjlistofedges.end(); ++it)
    {
      {


         int v ;
        if(edgearray[*it].v1==s)
            v=edgearray[*it].v2;
        else
            v=edgearray[*it].v1;
        // condition to omit reverse path
        // path from children to parent
        if (v== e)
            continue;

        if(edgearray[*it].v1==s)
            {
                 edgearray[*it].v1vertex=nodearray[root].numberofnodes-nodearray[v].numberofnodes;
                edgearray[*it].v2vertex=nodearray[v].numberofnodes;
            }
        else
            {

                 edgearray[*it].v2vertex=nodearray[root].numberofnodes-nodearray[v].numberofnodes;
                edgearray[*it].v1vertex=nodearray[v].numberofnodes;
            }



        numberOfNodes1(v, s);



      }
    }

}


void Graph::lonely_cycles()
{
    this->bridge();
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
    vector<unordered_set<int>> edgesintree;


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
               unordered_set<int>s;

            graphbreak(0,l,g1,visited1,visitededges,dfsdonevertex,s);
            edgesintree.push_back(s);
             trees.push_back(g1);
           }



       }
   }

   for(int i=0;i<no_of_vertices;i++)
   {
       if(!dfsdonevertex[i])
       {
           Graph g1(no_of_vertices,no_of_edges);

           if(!dfsdonevertex[i])
           {for(int j=0;j<no_of_vertices;j++)
               visited1[j]=false;
               g1.root=i;
             unordered_set<int>s;
            graphbreak(0,i,g1,visited1,visitededges,dfsdonevertex,s);
            edgesintree.push_back(s);
             trees.push_back(g1);
           }



       }


   }



   for(int i=0;i<no_of_edges;i++)
   {
       if(!visitededges[i])
       {
           Graph g1(no_of_vertices,no_of_edges);

           for(int j=0;j<no_of_vertices;j++)
               visited1[j]=false;
               unordered_set<int>s;

          dfstwo(edgearray[i].v1,g1,visited1,visitededges,dfsdonevertex,s);
            for(int j=0;j<no_of_vertices;j++)
               visited1[j]=false;
            visited1[edgearray[i].v1]=true;
            g1.addEdge(edgearray[i].v1+1,edgearray[i].v2+1,edgearray[i].index);
             visitededges[edgearray[i].index]=true;
             s.insert(edgearray[i].index);


               g1.root=edgearray[i].v1;

               if(edgearray[i].edgeifincycle)
            graphbreak(1,edgearray[i].v2,g1,visited1,visitededges,dfsdonevertex,s);
            else
                graphbreak(0,edgearray[i].v2,g1,visited1,visitededges,dfsdonevertex,s);
             edgesintree.push_back(s);
           trees.push_back(g1);
       }

   }


   for(int i=0;i<trees.size();i++)
   {
     trees[i].numberOfNodes(trees[i].root,-1);


     trees[i].numberOfNodes1(trees[i].root,-1);



     for(int j=0;j<no_of_vertices;j++)
               visited1[j]=false;
    trees[i].DFSUtil(trees[i].root,visited1,edgesintree,i,this);

   }

delete []dfsdonevertex;
delete []visited1;
delete []visitededges;}
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
       for(int j=0;j<m;j++)
       {
           cout<<g.edgearray[j].score<<endl;
       }


    }





    return 0;
}
