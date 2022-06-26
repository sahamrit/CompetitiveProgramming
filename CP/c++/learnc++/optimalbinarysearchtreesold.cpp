
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
void root(int *roots,int last,subproblem **arr,int start)
{
    static int ctr=0;
    if(start>last)return;
if(start==last){ roots[ctr++]=arr[start][start].root_value;
           cout<<arr[start][start].root_value<<" for"<<start<<","<<start<<endl;
           return;}
    else{

    roots[ctr++]=arr[start][last].root_value;
   cout<<arr[start][last].root_value<< " for"<<start<<","<<last<<endl;
   int a=roots[ctr-1];
    root(roots,a-1,arr,start);
    root(roots,last,arr,a+1);}
}
void optimal_bst(int *nodes,int *freq,int n)
{   int *ptr=new int;
    int *roots;
    roots=new int[n];
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
cout<<"hi";
 root(roots,n-1,arr,0);

}
int main()
{
    int *nodes,*freq,n;
    cout<<"enter no of nodes\n";
    cin>>n;
N=n;
    nodes=new int [n];
    freq=new int [n];
    for(int i=0;i<n;i++)
        nodes[i]=i;
    cout<<"Enter frequency for nodes\n";
    for(int i=0;i<n;i++)
        cin>>freq[i];
    optimal_bst(nodes,freq,n);
    return 0;
}

