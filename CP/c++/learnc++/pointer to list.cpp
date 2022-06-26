#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> v;
    v.push_back(1);
    v.push_back(2);
    vector <int>*a=&v;
    (*a).push_back(3);
    cout<<(*a)[2];
}
