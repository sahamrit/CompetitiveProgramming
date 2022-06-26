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


	bool topologicalSort(int,vector<int> );
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


bool Graph::topologicalSort(int maximum_sum,vector<int>v )
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
cout<<vertex[i].score<<" ";
}
cout<<endl;
	int sum=0;
	for(int i=0;i<V;i++)
	  {sum+=vertex[i].score;

	  }



	if(sum<=maximum_sum)
        return true;
      return false;
}
bool kcompress(int k,vector<int>v,int maximum_sum)
{
     Graph g(v.size());


           for(int j=0;j<v.size();j++ )
           {
               for(int p=max(0,j-k);p<=min((int)v.size()-1,j+k);p++)
               {
                   if(v[p]<v[j])
                     g.addEdge(j,p);
               }
           }

         return g.topologicalSort(maximum_sum,v);
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
    {if(!kcompress(0,t[i].a,t[i].maximum_sum))
    {
        cout<<0<<endl;
        continue;

    }
    int kk=1;
    bool res;
    while(1)
    {res=kcompress(kk,t[i].a,t[i].maximum_sum);
        if(!res)
            break;
            if(kk==t[i].no_elements||kk==t[i].no_elements-1)
                break;
            kk=min(2*kk,t[i].no_elements);
    }
    if((kk==t[i].no_elements||kk==t[i].no_elements-1)&&res)
        cout<<t[i].no_elements+1<<endl;

    else{

     int low=kk/2,k;
     int high=kk;
     bool check=false;
     while (low<=high)
     {
         bool r1,r2;


         k=low+(high-low)/2;
         r1=kcompress(max(k-1,0),t[i].a,t[i].maximum_sum);
         r2=kcompress(k,t[i].a,t[i].maximum_sum);
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

    }
	return 0;
}
