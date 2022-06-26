#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	vector<int> b(m);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)cin>>b[i];	
	int maxa=INT_MIN,minb=INT_MAX;
    int maxaidx,minbidx;
	for(int i=0;i<n;i++){
		if(maxa<a[i]){maxa=a[i];maxaidx=i;}
	}
	for(int i=0;i<m;i++){
		if(minb>b[i]){minb=b[i];minbidx=i;}
	}
	for(int i=0;i<m;i++)
	{
		cout<<maxaidx<<" "<<i<<endl;
	}
	for(int i=0;i<n;i++){
		if(i==maxaidx)continue;
		cout<<i<<" "<<minbidx<<endl;
	}

    

}