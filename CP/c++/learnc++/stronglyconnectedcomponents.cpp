#include<iostream>
#include<list>
using namespace std;
int s=0;
class Graph
{private:
    int v;
    list <int> *adj;
    public:
    Graph(int vertices)
    {
        v=vertices;
        adj=new list<int>[v];
    }

    void addedge(int v,int w)
    {adj[v].push_back(w);

    }

    Graph reversegraph()
    {Graph grev(v);
        list <int>::iterator it;
        for(int i=0;i<v;i++)
        {
            for(it=adj[i].begin();it!=adj[i].end();it++)
            {
                grev.addedge(*it,i);
            }
        }
        return grev;
    }



   void Dfsone(int p,int *timerank,bool *visited)
   {visited[p]=true;
       list<int>::iterator it;
       for(it=adj[p].begin();it!=adj[p].end();it++)
       {
           if(!visited[*it])
           {
              this->Dfsone(*it,timerank,visited);
           }
       }
       timerank[s]=p;
       s++;

   }
   void Dfstwo(int p ,bool *visited)
   {
       visited[p]=true;
              list<int>::iterator it;
       cout<<p;
         for(it=adj[p].begin();it!=adj[p].end();it++)
       {
           if(!visited[*it])
           {
              this->Dfstwo(*it,visited);
           }
       }


   }
    void connectedcomp()
   {
       bool *visited=new bool[v];
       int *timerank=new int [v];

       Graph g=this->reversegraph();


       for(int i=v-1;i>=0;i--)
       {
        visited[i]=false;
       }

       for(int i=v-1;i>=0;i--)
       {
           if(!visited[i])
           {
               g.Dfsone(i,timerank,visited);
           }
       }
        for(int i=v-1;i>=0;i--)
       {
        visited[i]=false;
       }
      cout<<"the connected components are";
       for(int i=v-1;i>=0;i--)
       {
           if(!visited[timerank[i]])
           {this->Dfstwo(timerank[i],visited);cout<<endl;}
       }


   }
};
int main()
{
    Graph g(9);
    g.addedge(6,0);

    g.addedge(0,3);

    g.addedge(3,6);

    g.addedge(8,6);

    g.addedge(8,2);
    g.addedge(2,5);
    g.addedge(5,8);
    g.addedge(7,5);

    g.addedge(1,7);
    g.addedge(4,1);
    g.addedge(7,4);


g.connectedcomp();
return 0;
}
