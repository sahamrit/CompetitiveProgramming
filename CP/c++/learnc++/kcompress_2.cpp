#include<bits/stdc++.h>
using namespace std;

struct vertices{

    list<int> l;
    list<int>::iterator i;
    int index;
    int score;
};
struct test_cases{
    int no_elements;
    int maximum_sum;
    vector <int> a;


};
class Graph
{
	int V;
	vertices *vertex;


	void topologicalSortUtil(int v, bool visited[]);
public:
	Graph(int V);


	void addEdge(int v, int w);


	bool topologicalSort(int );
};

Graph::Graph(int V)
{
	this->V = V;
	vertex=new vertices[V];
	for(int i=0;i<V;i++)
        {vertex[i].score=0;
        vertex[i].index=i;}
}

void Graph::addEdge(int v, int w)
{
	vertex[v].l.push_back(w);
}


void Graph::topologicalSortUtil(int v, bool visited[])
{

	visited[v] = true;



	for (vertex[v].i=vertex[v].l.begin() ; vertex[v].i!=vertex[v].l.end(); ++(vertex[v].i))
		if (!visited[*(vertex[v].i)])
			topologicalSortUtil(*(vertex[v].i), visited);

  int maxima=1;

	for (vertex[v].i=vertex[v].l.begin() ; vertex[v].i!=vertex[v].l.end(); ++(vertex[v].i))
    {

        if(visited[*(vertex[v].i)])
        {

            if(maxima<vertex[*(vertex[v].i)].score+1)
                maxima=vertex[*(vertex[v].i)].score+1;
        }
    }
    vertex[v].score=maxima;

}


bool Graph::topologicalSort(int maximum_sum )
{



	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;


	for (int i = 0; i < V; i++)
	if (visited[i] == false)
		topologicalSortUtil(i, visited);

	int sum=0;
	for(int i=0;i<V;i++)
	  {sum+=vertex[i].score;

	  }



	if(sum<=maximum_sum)
        return true;
      return false;
}
bool kcompress(int k,test_cases *t,int i)
{
     Graph g(t[i].no_elements);


           for(int j=0;j<t[i].no_elements;j++ )
           {
               for(int p=max(0,j-k);p<=min(t[i].no_elements-1,j+k);p++)
               {
                   if(t[i].a[p]<t[i].a[j])
                     g.addEdge(j,p);
               }
           }

         return g.topologicalSort(t[i].maximum_sum);
}


int main()
{


	int no_of_testcases;
	cin>>no_of_testcases;
	test_cases * t=new test_cases[no_of_testcases];
	for(int i=0;i<no_of_testcases;i++)
    {   int temp;
        cin>>t[i].no_elements;
        cin>>t[i].maximum_sum;
        for(int j=0;j< t[i].no_elements;j++)
        {cin>>temp;
         t[i].a.push_back(temp);

        }
    }
    for(int i=0;i<no_of_testcases;i++)
    {
     int low=0,k;
     int high=t[i].no_elements;
     bool check=false;
     while (low<=high)
     {
         bool r1,r2;


         k=low+(high-low)/2;
         r1=kcompress(max(k-1,0),t,i);
         r2=kcompress(k,t,i);
         if((r1==true&&r2==false)||(r2==true&&(k==t[i].no_elements||k==t[i].no_elements-1)))
           { check=true;
           if(k==t[i].no_elements||k==t[i].no_elements-1)

            cout<<t[i].no_elements+1<<endl;
           else
           cout<<k<<endl;
           break;
           }
         else if(r1==true && r2==true)
            low=k+1;
         else if(r1==false && r2==false)
            high=k-1;

     }
     if(check==false)
        cout<<0<<endl;



    }
	return 0;
}

