#include<bits/stdc++.h>
using namespace std;
#define NIL -1

struct edges
{

   long long int v1score,v2score;
    int v1,v2;

    bool edgeifincycle;

};


int numberofnodes[1000];
bool dfsdonevertex [1000];
bool visitededges [1000];
long long int score[1000];
 edges edgearray[1000];
class Graph1
{list<pair<int,int>> adj1[1000];
public:
   int root;
    Graph1(){}
    void addEdge(int m,int n,int ctr )
    {
        adj1[m-1].push_back(make_pair(n-1,ctr));
    adj1[n-1].push_back(make_pair(m-1,ctr));
    }
     void DFSUtil(int , bool *,vector<unordered_set<int>>&,int);
    void numberOfNodes(int ,int);
    void numberOfNodes1(int ,int);


};
vector<Graph1> trees(1000);
    vector<unordered_set<int>> edgesintree;
    stack<int> s;
     unordered_set<int>s1;


class Graph
{list<pair<int,int>> *adj;
    public:
    int no_of_vertices,no_of_edges;




    Graph(int n,int m):no_of_vertices(n),no_of_edges(m)
    {adj=new list<pair<int,int>>[no_of_vertices];


        for(int i=0;i<no_of_edges;i++)
        {

            edgearray[i].edgeifincycle=true;

        }

    }

    void addEdge(int m,int n,int ctr)
    {
    adj[m-1].push_back(make_pair(n-1,ctr));
    adj[n-1].push_back(make_pair(m-1,ctr));


        edgearray[ctr].v1score=0;
        edgearray[ctr].v2score=0;

        edgearray[ctr].v1=m-1;
        edgearray[ctr].v2=n-1;



    }
    void bridge();
    void bridgeUtil(int , bool *, int *,int *, int *);
    void lonely_cycles();
    void dfs(int ,bool *,stack <int>&);
    void graphbreak(int,int ,Graph1 *,bool *,unordered_set<int>*);
    void dfstwo(int,Graph1 *,bool *,unordered_set<int>*);


};

//function used from geeksforgeeks https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
void Graph::dfs(int u, bool * visited,stack<int>&s)
{
    visited[u] = true;

   if(adj[u].size()==1)
       s.push(u);
    list<pair<int,int>>::iterator it;
    for (it =adj[u].begin(); it !=adj[u].end(); ++it)
        {
            int v =it->first;


            if (!visited[v])
            dfs(v, visited,s);


        }
        visited[u]=false;
}
//FUNCTION USED FROM GEEKSFORGEEKS https://www.geeksforgeeks.org/bridge-in-a-graph/
void Graph::bridgeUtil(int u, bool *visited, int * disc,
                                  int *low, int* parent)
{

    static int time = 0;

    visited[u] = true;

    disc[u] = low[u] = ++time;

    list<pair<int,int>>::iterator it;
    for (it = adj[u].begin(); it != adj[u].end(); ++it)
    {
        int v = it->first;


        if (!visited[v])
        {
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent);


            low[u]  = min(low[u], low[v]);


            if (low[v] > disc[u])
             {edgearray[it->second].edgeifincycle=false;
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
void Graph::graphbreak(int counter,int l,Graph1 *g,bool *visited1,unordered_set<int>*s)
{
     visited1[l] = true;
      dfsdonevertex[l]=true;


    list<pair<int,int>>::iterator it;
    for (it = adj[l].begin(); it !=adj[l].end(); ++it)
        {
            int v =it->first;


            if(!visited1[v])
        {
          if(counter==1 && edgearray[it->second].edgeifincycle )
            continue;
          if(edgearray[it->second].edgeifincycle)
            counter++;

            g->addEdge(l+1,v+1,it->second);


            visitededges[it->second]=true;
            s->insert(it->second);
            graphbreak(counter,v,g,visited1,s);


        }


        }
        visited1[l]=false;





}
void Graph::dfstwo(int l,Graph1 *g,bool *visited1,unordered_set<int>*s)
{
     visited1[l] = true;
    dfsdonevertex[l]=true;


    list<pair<int,int>>::iterator it;
    for (it = adj[l].begin(); it !=adj[l].end(); ++it)
        {
            int v=it->first ;


            if(!visited1[v])
        {
          if( edgearray[it->second].edgeifincycle )
            continue;


            g->addEdge(l+1,v+1,it->second);


            visitededges[it->second]=true;
            s->insert(it->second);
            dfstwo(v,g,visited1,s);


        }
        }

}
void Graph1::DFSUtil(int u, bool* visited,vector<unordered_set<int>>&edgesintree,int iteration)
{

    visited[u] = true;



    list<pair<int,int>>::iterator it;
     for (it =adj1[u].begin(); it !=adj1[u].end(); ++it)
        {
            int v=it->first ;


            if(!visited[v])
        {
           int p;
          for( p=0;p<iteration;p++)
          {
              if(edgesintree[p].find(it->second)!=edgesintree[p].end())
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

         score[it->second]+=edgearray[it->second].v1score*edgearray[it->second].v2score-ctr;
            DFSUtil(v,visited,edgesintree,iteration);




      }


     }



}
void Graph1::numberOfNodes(int s, int e)
{
   list<pair<int,int>>:: iterator it;
    numberofnodes[s]=1;

    for (it = adj1[s].begin(); it !=adj1[s].end(); ++it)
    {




         int v=it->first ;


        if (v== e)
            continue;


        numberOfNodes(v, s);


        numberofnodes[s] += numberofnodes[v];

    }

}
void Graph1::numberOfNodes1(int s, int e)
{
  list<pair<int,int>>:: iterator it;

    for (it =adj1[s].begin(); it !=adj1[s].end(); ++it)
    {
      {


         int v=it->first ;

        // condition to omit reverse path
        // path from children to parent
        if (v== e)
            continue;

            edgearray[it->second].v1score=numberofnodes[root]-numberofnodes[v];
            edgearray[it->second].v2score=numberofnodes[v];




        numberOfNodes1(v, s);



      }
    }
}

void Graph::lonely_cycles()
{
    bridge();

  bool *visited1=new bool[no_of_vertices];
    for(int i=0;i<no_of_vertices;i++)
       {
        dfsdonevertex[i]=false;}



    for(int i=0;i<no_of_edges;i++)
    {
     visitededges[i]=false;
    }

    dfs(0,visited1,s);



int no_of_trees=0;

       while(s.size()!=0)
       {
           int l=s.top();
           s.pop();
           if(!dfsdonevertex[l])
           {
               trees[no_of_trees].root=l;
           for(int i=0;i<no_of_vertices;i++)
            visited1[i]=false;

            graphbreak(0,l,&trees[no_of_trees],visited1,&s1);
            edgesintree.push_back(s1);
             no_of_trees++;
             s1.clear();

           }

       }



  for(int i=0;i<no_of_vertices;i++)
   {
       if(!dfsdonevertex[i])
       {


           if(!dfsdonevertex[i])
           {
               trees[no_of_trees].root=i;
                     for(int j=0;j<no_of_vertices;j++)
            visited1[j]=false;

             graphbreak(0,i,&trees[no_of_trees],visited1,&s1);
            edgesintree.push_back(s1);
          no_of_trees++;
          s1.clear();
           }



       }


   }



   for(int i=0;i<no_of_edges;i++)
   {
       if(!visitededges[i])
       {



 for(int j=0;j<no_of_vertices;j++)
            visited1[j]=false;

          dfstwo(edgearray[i].v1,&trees[no_of_trees],visited1,&s1);

            visited1[edgearray[i].v1]=true;
            trees[no_of_trees].addEdge(edgearray[i].v1+1,edgearray[i].v2+1,i);
             visitededges[i]=true;
             s1.insert(i);


               trees[no_of_trees].root=edgearray[i].v1;
               for(int j=0;j<no_of_vertices;j++)
            visited1[j]=false;

               if(edgearray[i].edgeifincycle)
            graphbreak(1,edgearray[i].v2,&trees[no_of_trees],visited1,&s1);
            else
                graphbreak(0,edgearray[i].v2,&trees[no_of_trees],visited1,&s1);
             edgesintree.push_back(s1);
           no_of_trees++;
           s1.clear();
       }

   }


   for(int i=0;i<no_of_trees;i++)
   {
     trees[i].numberOfNodes(trees[i].root,-1);


     trees[i].numberOfNodes1(trees[i].root,-1);



     for(int j=0;j<no_of_vertices;j++)
               visited1[j]=false;
    trees[i].DFSUtil(trees[i].root,visited1,edgesintree,i);

   }
edgesintree.clear();
trees.clear();
delete []visited1;
}
int main()
{
    int testcases;
    scanf("%d",&testcases);
    for(int i=0;i<testcases;i++)
    {
        int n, m;
       scanf("%d %d",&n,&m);
        Graph g(n,m);
        for(int j=0;j<m;j++)
        {
            numberofnodes[j]=0;
            score[j]=0;



           int u, v;
           scanf("%d %d",&u,&v);
           g.addEdge(u,v,j);

       }
       g.lonely_cycles();
       for(int j=0;j<m;j++)
       {
           printf("%lld \n",score[j]);
       }


    }

    return 0;
}
