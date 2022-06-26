#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,n1;
	string s;
	cin>>t;
	n=t;
	while(t--)
	{
		cout<<"Case #"<<n-t<<" ";
		cin>>n1;
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='E')cout<<'S';
			else cout<<'E';
		}
		cout<<endl;
	}
}