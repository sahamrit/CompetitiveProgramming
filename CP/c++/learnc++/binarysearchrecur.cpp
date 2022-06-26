#include<iostream>
#include<vector>

using namespace std;
int binarysearch(int l,int r,vector <int> &v,int key)
{int mid=l+(r-l)/2;
    if(l<=r){if(v[mid]<key) return binarysearch(mid +1,r,v,key);
    else if(key<v[mid])return binarysearch(l,mid-1,v,key);
    else return mid;

    }else return -1;
}
int main()
{
    vector <int> v;
    v.push_back(33);
    v.push_back(35);
    v.push_back(37);
    v.push_back(39);
    v.push_back(45);
    v.push_back(93);
    v.push_back(673);
    v.push_back(1024);
    cout<<binarysearch(0,v.size()-1,v,39);

}
