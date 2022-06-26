#include<bits/stdc++.h>
using namespace std;
#define NIL -1

struct edges
{

   long long int v1score,v2score;
    int v1,v2;

    bool edgeifincycle;

};


int numberofnodes[1000000];
bool dfsdonevertex [1000000];
bool visitededges [1000000];
long long int score[1000000];
 edges edgearray[1000000];
 edges edgearray1[1000000];

class Graph1
{list<pair<int,int>> *adj1;
public:
   int root;
   Graph1(){}
    Graph1(int no_nodes){
        adj1=new list<pair<int,int>>[no_nodes];
    }
    void addEdge(int m,int n,int ctr )
    {
        adj1[m-1].push_back(make_pair(n-1,ctr));
    adj1[n-1].push_back(make_pair(m-1,ctr));
    }
     void DFSUtil(int , bool *,vector<unordered_set<int>>&,int,int);
    void numberOfNodes(int ,int);
    void numberOfNodes1(int ,int,bool check);



};


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
    void graphbreak(int*,int ,Graph1 *,bool *,unordered_set<int>*);
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
void Graph::graphbreak(int* counter,int l,Graph1 *g,bool *visited1,unordered_set<int>*s)
{
     visited1[l] = true;
      dfsdonevertex[l]=true;


    list<pair<int,int>>::iterator it;
    for (it = adj[l].begin(); it !=adj[l].end(); ++it)
        {
            int v =it->first;


            if(!visited1[v])
        {
          if((*counter)==1 && edgearray[it->second].edgeifincycle )
            continue;
          if(edgearray[it->second].edgeifincycle)
            (*counter)++;

            g->addEdge(l+1,v+1,it->second);


            visitededges[it->second]=true;
            s->insert(it->second);
            graphbreak(counter,v,g,visited1,s);


        }


        }






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
void Graph1::DFSUtil(int u, bool* visited,vector<unordered_set<int>>&edgesintree,int iteration,int nonodes)
{

    visited[u] = true;



    list<pair<int,int>>::iterator it;
     for (it =adj1[u].begin(); it !=adj1[u].end(); ++it)
        {
            int v=it->first ;


            if(!visited[v])
        {
           int p;
            int minus=0;
          unordered_set<int>::iterator itt;

          for( p=0;p<iteration;p++)
          { bool check1=true;
            Graph1 g11(nonodes);
              if(edgesintree[p].find(it->second)!=edgesintree[p].end())
              {
                 for(itt=edgesintree[iteration].begin();itt!=edgesintree[iteration].end();)
                    {
                        if(edgesintree[p].find(*itt)!=edgesintree[p].end())
                            { g11.addEdge(edgearray[*itt].v1+1,edgearray[*itt].v2+1,*itt);
                                if(check1)
                                  {g11.root=edgearray[*itt].v1;
                                    check1=false;

                                  }
                                  itt=edgesintree[iteration].erase(itt);
                            }
                            else
                                    ++itt;
                     }
                     cout<<g11.root<<" "<<check1<<endl;
                      g11.numberOfNodes(g11.root,-1);
                 g11.numberOfNodes1(g11.root,-1,true);
                 minus+=edgearray1[it->second].v1score*edgearray1[it->second].v2score;


               }

         }


         score[it->second]+=edgearray[it->second].v1score*edgearray[it->second].v2score-minus;
            DFSUtil(v,visited,edgesintree,iteration,nonodes);
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
void Graph1::numberOfNodes1(int s, int e,bool check)
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
            if(!check)
            {edgearray[it->second].v1score=numberofnodes[root]-numberofnodes[v];
            edgearray[it->second].v2score=numberofnodes[v];
            }
            else if(check)
            {edgearray1[it->second].v1score=numberofnodes[root]-numberofnodes[v];
            edgearray1[it->second].v2score=numberofnodes[v];

            }




        numberOfNodes1(v, s,false);



      }
    }
}

void Graph::lonely_cycles()
{
    bridge();

  bool *visited1=new bool[no_of_vertices];
    for(int i=0;i<no_of_vertices;i++)
       {
           visited1[i]=false;
        dfsdonevertex[i]=false;}
    stack<int> s;


    for(int i=0;i<no_of_edges;i++)
    {
     visitededges[i]=false;
    }

    dfs(0,visited1,s);
   vector<Graph1> trees;
    vector<unordered_set<int>> edgesintree;
    for(int i=0;i<no_of_vertices;i++)
       {
           visited1[i]=false;
       }

 int a=0;



       while(s.size()!=0)
       {
           int l=s.top();
           s.pop();
           if(!dfsdonevertex[l])
           {a=0;
            Graph1 g1(no_of_vertices);
               g1.root=l;
               unordered_set<int>s1;
               for(int j=0;j<no_of_vertices;j++)
                   {
                        visited1[j]=false;
                   }

            graphbreak(&a,l,&g1,visited1,&s1);
            edgesintree.push_back(s1);
             trees.push_back(g1);
           }

       }


  for(int i=0;i<no_of_vertices;i++)
   {
       if(!dfsdonevertex[i])
       {a=0;
           Graph1 g1(no_of_vertices);

           if(!dfsdonevertex[i])
           {
               g1.root=i;
             unordered_set<int>s1;
             for(int j=0;j<no_of_vertices;j++)
                   {
                        visited1[j]=false;
                   }

             graphbreak(&a,i,&g1,visited1,&s1);
            edgesintree.push_back(s1);
             trees.push_back(g1);
           }



       }


   }



   for(int i=0;i<no_of_edges;i++)
   {
       if(!visitededges[i])
       {
           Graph1 g1(no_of_vertices);


               unordered_set<int>s1;
                  for(int j=0;j<no_of_vertices;j++)
                   {
                        visited1[j]=false;
                   }

          dfstwo(edgearray[i].v1,&g1,visited1,&s1);

            visited1[edgearray[i].v1]=true;
            g1.addEdge(edgearray[i].v1+1,edgearray[i].v2+1,i);
             visitededges[i]=true;
             s1.insert(i);

            for(int j=0;j<no_of_vertices;j++)
                   {
                        visited1[j]=false;
                   }

               g1.root=edgearray[i].v1;

               if(edgearray[i].edgeifincycle)
           {a=1;
            graphbreak(&a,edgearray[i].v2,&g1,visited1,&s1);}
            else
              {a=0;
                graphbreak(&a,edgearray[i].v2,&g1,visited1,&s1);}
             edgesintree.push_back(s1);
           trees.push_back(g1);
       }

   }


   for(int i=0;i<trees.size();i++)
   {
     trees[i].numberOfNodes(trees[i].root,-1);


     trees[i].numberOfNodes1(trees[i].root,-1,false);



     for(int j=0;j<no_of_vertices;j++)
               visited1[j]=false;
    trees[i].DFSUtil(trees[i].root,visited1,edgesintree,i,no_of_vertices);

   }


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
        if(m==0)
            break;
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
           printf("%lld\n",score[j]);
       }


    }

    return 0;
}
