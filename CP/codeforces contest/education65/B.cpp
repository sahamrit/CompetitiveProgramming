#include <bits/stdc++.h>
using namespace std;

#define MAXN 500005
vector < int > parent(MAXN, -1);
vector <int > size(MAXN,1);

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        make_set(i);
    for(int i=0;i<m;i++)
    {
        cin>>k;
        vector <int> v(k);
        for(int j=0;j<k;j++)
        {
            cin>>v[j];
        }
        for(int j=1;j<k;j++)
        {
            union_sets(v[j],v[j-1]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<size[find_set(i)]<<" ";
    }
    cout<<endl;

}