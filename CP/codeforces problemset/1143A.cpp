#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,input;
	cin>>n;
	int last0,last1;
	for(int i=1;i<=n;i++)
	{
		cin>>input;
		if(input==0)
			last0=i;
		else last1=i;
	}
	cout<<min(last0,last1)<<endl;
}