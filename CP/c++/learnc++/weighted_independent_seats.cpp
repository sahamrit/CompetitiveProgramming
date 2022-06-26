#include<iostream>
using namespace std;
struct nodes{
int weight;
int index;};
void wis(nodes* arr,int v)
{
    int *memoic=new int[v+1];
    memoic[0]=0;
    memoic[1]=arr[0].weight;
    for(int i=2;i<=v;i++)
    {
        memoic[i]=max(memoic[i-1],memoic[i-2]+arr[i-1].weight);
    }

    int i=v;
        while(i>1)
        {
            if(memoic[i-1]>memoic[i-2]+arr[i-1].weight)
                i--;
            else {cout<<"weight is "<<arr[i-1].weight<<"index is"<<arr[i-1].index<<endl;
            i=i-2;
                 }
        }
        if(i==1)
            cout<<"weight is"<<arr[0].weight<<"index is"<<arr[0].index;

}
int main()
{
    int n;
    cout<<"enter nodes\n";
    cin>>n;
    cout<<"enter"<<n<<"datas(index and weight)\n";
    nodes *arr=new nodes[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].index>>arr[i].weight;
    }
    wis(arr,n);
}
