#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarysearch(vector <int> &v,int key)
{
    int l=0,r=v.size()-1;
    int mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if(v[mid]>key) r=mid-1;
        else if(v[mid]<key) l=mid +1;
        else return mid;
    }return -1;
}

int main()
{
    vector <int> v;
    int ctr=0;

v.push_back(-1);
v.push_back(0);
v.push_back(0);
v.push_back(0);
v.push_back(1);
v.push_back(1);
v.push_back(2);
v.push_back(-1);
v.push_back(4);
v.push_back(4);
v.push_back(3);
v.push_back(-3);

 sort(v.begin(),v.end());


 int l=v.size();
 for(int i=0;i<l-2&&v[i]<=0;i++)
    for(int j=i+1;j<l-1&& v[i]+v[j]<=0;j++)
 {
    int k=binarysearch(v,-v[i]-v[j]);
    if((k>j && v[j]!=v[j+1]&&v[i]!=v[i-1])||(k>j&&v[i]!=v[i-1]&&v[i]==0&&v[i+1]==0)){cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<endl;
            ctr++;
           }

 }
 if(ctr==0)
    cout<<"no triplet";

}
