#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<pair<int,int>>>v;
    int p,s;
    cin>>p;
    cin>>s;
    int no;
    vector<pair<int,int>>temp;
    for(int i=0;i<s;i++)
        temp.push_back(make_pair(0,0));
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<s;j++)
        {
           cin>>no;
           temp[j].first=no;
        }
        for(int j=0;j<s;j++)
        {
            cin>>no;
            temp[j].second=no;
        }
        v.push_back(temp);
    }

    vector<pair<int,int>>result;
    for(int i=0;i<p;i++)
        result.push_back(make_pair(0,0));
    for(int i=0;i<p;i++)
    {
        sort(v[i].begin(),v[i].end());
    }

   for(int i=0;i<p;i++)
    {
        int score=0;
        for(int j=0;j<s-1;j++)
        {
            if(v[i][j].second>v[i][j+1].second)
                score++;
        }
        result[i].first=score;
        result[i].second=i;
    }

    sort(result.begin(),result.end());
    for(int i=0;i<p;i++)
        cout<<result[i].second+1<<endl;


}
