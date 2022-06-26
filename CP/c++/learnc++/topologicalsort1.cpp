// A C++ program to print topological sorting of a DAG
#include<iostream>
#include <list>
#include <stack>
using namespace std;

struct vertices{
    int no;
    list<int> l;
    list<int>::iterator i;
};
class Graph
{
	int V; // No. of vertices'
	vertices *vertex;

	// Pointer to an array containing adjacency listsList


	// A function used by topologicalSort
	void topologicalSortUtil(int v, bool visited[]);
public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);

	// prints a Topological Sort of the complete graph
	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	vertex=new vertices[V];

}

void Graph::addEdge(int v, int w)
{
	vertex[v].l.push_back(w);
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[])
{static int global=V;
	// Mark the current node as visited.
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex

	for (vertex[v].i=vertex[v].l.begin() ; vertex[v].i!=vertex[v].l.end(); ++(vertex[v].i))
		if (!visited[*(vertex[v].i)])
			topologicalSortUtil(*(vertex[v].i), visited);

	// Push current vertex to stack which stores result
	vertex[v].no=global;
	global --;
}

// The function to do Topological Sort. It uses recursive
// topologicalSortUtil()
void Graph::topologicalSort()
{


	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function to store Topological
	// Sort starting from all vertices one by one
	for (int i = 0; i < V; i++)
	if (visited[i] == false)
		topologicalSortUtil(i, visited);

	// Print contents of stack
	for(int i=0;i<V;i++)
	cout<<"v["<<i<<"]="<<vertex[i].no<<endl;
}

// Driver program to test above functions
int main()
{
	// Create a graph given in the above diagram
	Graph g(8);
	g.addEdge(1, 0);
	g.addEdge(1, 2);
	g.addEdge(3, 2);
	g.addEdge(3, 4);
	g.addEdge(5, 4);
	g.addEdge(5, 6);
	g.addEdge(7, 6);

    g.addEdge(0, 2);
	g.addEdge(3, 1);
	g.addEdge(4, 2);
	g.addEdge(3, 5);
	g.addEdge(4, 6);
	g.addEdge(7, 5);
	cout << "Following is a Topological Sort of the given graph \n";
	g.topologicalSort();

	return 0;
}

