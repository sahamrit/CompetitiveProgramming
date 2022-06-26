#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct vertex{
vector <int> adjlist;};
class graph{
private:
    int no_nodes;
    int *dist;
    vertex *nodes;
public:
    graph(int n):no_nodes(n){
    dist=new int[no_nodes];
    nodes=new vertex[no_nodes];
    }
    void bfs(int);
    void addedge(int,int);
};
void graph::addedge(int m,int n)
{
    nodes[m].adjlist.push_back(n);
    nodes[n].adjlist.push_back(m);
}
void graph::bfs(int s)
{
    bool *visited=new bool [no_nodes];
    for(int i=0;i<no_nodes;i++)
    {
        visited[i]=false;

    }
    queue<int> q;
    q.push(s);
    visited[s]=true;
    dist[s]=0;
    vector<int>::iterator it;
    while(!q.empty()){
        int poped=q.front();
        q.pop();
        for(it=nodes[poped].adjlist.begin();it!=nodes[poped].adjlist.end();it++){
            if(!visited[*it]){
                visited[*it]=true;
                dist[*it]=dist[poped]+1;
                q.push(*it);

            }
        }
    }
    for(int i=0;i<no_nodes;i++)
        cout<<i<<":"<<dist[i]<<endl;

}
int main()
{

    int n;
    cout<<"enter no of nodes";
    cin>>n;
    graph g(n);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,4);
    g.addedge(2,3);
    g.addedge(3,4);
    g.addedge(3,5);
    g.addedge(4,5);
    g.addedge(2,4);
    g.bfs(0);
}
