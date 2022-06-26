
#include<bits/stdc++.h>
using namespace std;

struct vertices{

    vector<int> l;
    vector<int>::iterator i;
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

	void topologicalSort(int &,int &,vector<int>);
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

void Graph::topologicalSort(int & ctr,int &maximum_sum,vector<int>v)
{


	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	for (int i = 0; i < V; i++)
	if (visited[i] == false)
		topologicalSortUtil(i, visited);
for(int i=0;i<v.size()-1;i++)
{
    if(v[i]==v[i+1]&&(vertex[i].score>vertex[i+1].score))
           vertex[i+1].score=vertex[i].score;

}
for(int i=v.size()-1;i>0;i--)
{
    if(v[i]==v[i-1]&&(vertex[i].score>vertex[i-1].score))
        vertex[i-1].score=vertex[i].score;
}

	int sum=0;
	for(int i=0;i<V;i++)
	  {sum+=vertex[i].score;

cout<<vertex[i].score<< " ";
	  }
cout<<endl;


	if(sum<=maximum_sum)
        ctr++;
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
    {   int prev=0;
        int ctr=0;
        int oldctr;
        Graph g(t[i].no_elements);

        for(int k=0;k<=t[i].no_elements;k++)
        {

            oldctr=ctr;

           for(int j=0;j<t[i].no_elements;j++ )
           {
               for(int p=max(0,j-k);p<min(t[i].no_elements-1,j-prev);p++)
               {
                   if(t[i].a[p]<t[i].a[j])
                     g.addEdge(j,p);
               }
                for(int p=max(0,j+prev+1);p<=min(t[i].no_elements-1,j+k);p++)
               {
                   if(t[i].a[p]<t[i].a[j])
                     g.addEdge(j,p);
               }
           }

           g.topologicalSort(ctr,t[i].maximum_sum,t[i].a);
           if(k!=0)
          prev++;

           if(oldctr==ctr)
            break;
        }
        cout<<ctr<<endl;

    }
	return 0;
}
