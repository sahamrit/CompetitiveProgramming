
#include<iostream>
#include<iomanip>
#include<limits.h>
using namespace std;
int N;
struct subproblem
{
    int value;
    int root_value;
};
struct nodes{int index;
nodes * left=nullptr;
nodes * right=nullptr;};

int minimum(int *freq,subproblem **arr,int i,int s,int *ptr)
{int mini=INT_MAX;
int freq_sum=0;
for(int j=0;j<=s;j++)
      freq_sum+=freq[j+i];
if(mini>freq_sum+arr[i+1][i+s].value)
    {mini=freq_sum+arr[i+1][i+s].value;
    *ptr=i;
    }
    if(mini>freq_sum+arr[i][i+s-1].value)
        {mini=freq_sum+arr[i][i+s-1].value;
        *ptr=i+s;
        }
    for(int r=i+1;r<i+s;r++)
        if(mini>freq_sum+arr[i][r-1].value+arr[r+1][i+s].value)
             {mini=freq_sum+arr[i][r-1].value+arr[r+1][i+s].value;
              *ptr=r;
             }
return mini;
}

nodes* root(int last,subproblem **arr,int start)
{  nodes *node=new nodes;



if(start>last )return nullptr;
if(start==last){
           cout<<arr[start][start].root_value<<" for"<<start<<","<<start<<endl;
           node->index=arr[start][start].root_value;
           node->left=nullptr;
           node->right=nullptr;
           return node;}
    else{

   cout<<arr[start][last].root_value<< " for"<<start<<","<<last<<endl;
   int a=arr[start][last].root_value;
  node->index=arr[start][last].root_value;
    node->left=root(a-1,arr,start);
    node->right=root(last,arr,a+1);
    return node;}
}
void printgraph(nodes *node)
{
    if (node==nullptr)
        return;
    else{cout<<node->index<<" ";
    if(node->left!=nullptr)
    {cout<<" left child of"<<node->index<<" is";
    printgraph(node->left);}
        if(node->right!=nullptr){cout<<" right child of"<<node->index<<" is";
           printgraph(node->right);}
           cout<<endl;
    }
}
void optimal_bst(int *nodes,int *freq,int n)
{   int *ptr=new int;

    subproblem **arr=new subproblem*[n];
    for(int i=0;i<n;i++)
        arr[i]=new subproblem [n];

    for(int i=0;i<n;i++)
        {arr[i][i].value=freq[i];
        arr[i][i].root_value=i;}
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i>j){arr[i][j].value=0;
            arr[i][j].root_value=-1;}

int s;
for( s=1;s<n;s++)
    for(int i=0;i<n;i++)
 {    if(i+s<n)
     arr[i][i+s].value=minimum(freq,arr,i,s,ptr);
     arr[i][i+s].root_value=*ptr;

 }
  for(int i=0;i<n;i++)
 {for(int j=0;j<n;j++)
    cout<<setw(12)<<arr[i][j].value<<","<<arr[i][j].root_value<<" ";
 cout<<endl;
 }
 cout<<"the optimal BST is"<<arr[0][n-1].value<<endl;

printgraph(root(n-1,arr,0));

}
int main()
{
    int *nodes1,*freq,n;
    cout<<"enter no of nodes\n";
    cin>>n;
N=n;
    nodes1=new int [n];
    freq=new int [n];
    for(int i=0;i<n;i++)
        nodes1[i]=i;
    cout<<"Enter frequency for nodes\n";
    for(int i=0;i<n;i++)
        cin>>freq[i];
    optimal_bst(nodes1,freq,n);
    return 0;
}

