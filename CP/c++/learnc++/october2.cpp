#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	int n;
	int r,q;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		r=n%26;
		q=n/26;
		if(r==0)
		{
			cout<<0<<" "<<0<<" "<<(long long )pow(2,q-1)<<endl;
		}
		else
		{
			if(r>=1&&r<=2)
			{
				cout<<(long long)pow(2,q)<<" "<<0<<" "<<0<<endl;
			}
			else if(r>=3&&r<=10)
			{
				cout<<0<<" "<<(long long)pow(2,q)<<" "<<0<<endl; 
			}
			else if(r>=11&&r<=25)
			{
				cout<<0<<" "<<0<<" "<<(long long )pow(2,q)<<endl;
			}
		}

	}
	
}