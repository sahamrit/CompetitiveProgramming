#include<bits/stdc++.h>
using namespace std;
struct node
{
    pair<char,char>p1;
    pair<char,char>p2;
    pair<char,char>p3;
};
int main()
{
    vector<node> v;
    int no;
    cin>>no;
    string str;
    for(int i=0;i<no;i++)
    {node n1;
        cin>>str;
        n1.p1.first=str[0];
        n1.p2.first=str[1];
        n1.p3.first=str[2];

        cin>>str;
        n1.p1.second=str[0];
        n1.p2.second=str[1];
        n1.p3.second=str[2];
        v.push_back(n1);

    }
    for(int i=0;i<no;i++)
    {
      if(v[i].p1.first=='o'||v[i].p1.second=='o')
      {
          if((v[i].p2.first=='b'||v[i].p2.second=='b')&&(v[i].p3.first=='b'||v[i].p3.second=='b'))
          {
              cout<<"yes"<<endl;
              continue;
          }
      }
      if(v[i].p2.first=='o'||v[i].p2.second=='o')
      {
          if((v[i].p1.first=='b'||v[i].p1.second=='b')&&(v[i].p3.first=='b'||v[i].p3.second=='b'))
          {
              cout<<"yes"<<endl;
              continue;
          }
      }
       if(v[i].p3.first=='o'||v[i].p3.second=='o')
      {
          if((v[i].p2.first=='b'||v[i].p2.second=='b')&&(v[i].p1.first=='b'||v[i].p1.second=='b'))
          {
              cout<<"yes"<<endl;
              continue;
          }
      }
      cout<<"no"<<endl;
    }
}
