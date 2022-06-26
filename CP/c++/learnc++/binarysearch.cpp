#include<iostream>
#include<vector>

using namespace std;
int binarysearch(int key,vector <int> &v)
{
    int mid,lo=0,hi=v.size()-1;
    while(lo<=hi){    mid=lo+(hi-lo)/2;

    if(key<v[mid])hi=mid-1;
    else if(key>v[mid])lo=mid+1;
    else return mid; }
    return -1;
}
int main()
{
    vector <int> v;
    v.push_back(33);
    v.push_back(34);
    v.push_back(39);
    v.push_back(41);
    v.push_back(63);
    v.push_back(103);
    v.push_back(673);
    v.push_back(1324);
    cout<<binarysearch(34,v);

}
