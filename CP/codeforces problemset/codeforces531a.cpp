#include<bits/stdc++.h>
#define p (int)(1e9+7)
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	cin>>n;
	long long x=n%4;
	if(x==1||x==2)
		cout<<1;
	else cout<<0;
}
