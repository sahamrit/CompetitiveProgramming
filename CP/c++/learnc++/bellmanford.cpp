#include<iostream>
#include<vector>
using namespace std;
struct edge{
int length;
int src;
int dest;};
struct node{
vector<edge> adjlist;};
class graph{
private:
    int no_nodes;
    node * point;
public:
    graph(int n):no_nodes(n){
    point=new node[no_nodes];
    }
    void addegde(int m,int n,int len){
    edge temp;
    temp.length=len;
    temp.src=m;
    temp.dest=n;
    point[m].adjlist.push_back(temp);
    point[n].adjlist.push_back(temp);
    }
    void bellmanford(int );
    int mini(int,int,int**);
};
int graph::mini(int n,int u,int **arr){
int minimum=100;
vector<edge>::iterator it;

for(it=point[u].adjlist.begin();it!=point[u].adjlist.end();it++)
    {
        if((*it).dest==u)
        {
        if(minimum>arr[n][(*it).src]+(*it).length)
          minimum=arr[n][(*it).src]+(*it).length;}
    }

    return minimum;
}

void graph::bellmanford(int s){
    int **arr;
    arr=new int*[no_nodes];
    for(int i=0;i<no_nodes;i++)
    arr[i]=new int[no_nodes];
    for(int i=0;i<no_nodes;i++)
        arr[0][i]=100;

    arr[0][s]=0;

    for(int i=1;i<no_nodes;i++)
    {

        for(int j=0;j<no_nodes;j++)
    {
        arr[i][j]=min(arr[i-1][j],mini(i-1,j,arr));
    }



    }
    for(int i=0;i<no_nodes;i++)
    {
       cout<<"minimum distance of"<<i<<"from"<<s<<":"<<arr[no_nodes-1][i]<<endl;

    }
}
int main()
{
    graph g(5);
    g.addegde(0,1,-1);
    g.addegde(0,4,4);
    g.addegde(1,4,3);
    g.addegde(1,2,2);
    g.addegde(1,3,2);
    g.addegde(3,1,1);
    g.addegde(3,4,5);
    g.addegde(2,3,-3);
g.bellmanford(0);

}
