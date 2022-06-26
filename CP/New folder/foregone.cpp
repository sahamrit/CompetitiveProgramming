#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int t;
	int n;
	cin>>t;
	n=t;
	while(t--)
	{
		string s;			
		cin>>s;
		string a,b;
		a.assign(s.size(),'0');
		b.assign(s.size(),'0');
		cout<<"Case #"<<n-t<<": ";
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='4')
			{
				a[i]='1';
				b[i]='3';
			}
			else
			{
				a[i]=s[i];
				b[i]='0';
			}
		}
		bool check=false;
		for(int i=0;i<a.size();i++)
		{
			if(check)
			{
				cout<<a[i];continue;
			}
			if(a[i]!='0')
			{
				check=true;
				cout<<a[i];continue;
			}
		}
		cout<<" ";
		check=false;
		for(int i=0;i<b.size();i++)
		{
			if(check)
			{
				cout<<b[i];continue;
			}
			if(b[i]!='0')
			{
				check=true;
				cout<<b[i];continue;
			}
		}		
		cout<<endl;	

	}
}