#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF),idx(n+1,-1),parent(n+1,-1);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j])
            {
                d[j] = a[i];
                idx[j]=i;
                parent[i]=idx[j-1];

            }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    int pos=idx[ans];
    vector<int> subseq;
    while (pos != -1) {
        subseq.push_back(a[pos]);
        pos = parent[pos];
    }
    reverse(subseq.begin(), subseq.end());
    for(auto u:subseq){
        cout<<u<<" ";
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    lis(a);

    return 0;
}