#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	int p1,p2,k;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>p1>>p2>>k;
		if((p1+p2)%k==0)
		{
			if(((p1+p2)/k)%2==0)
			{
				cout<<"CHEF"<<endl;
			}
			else
			{
				cout<<"COOK"<<endl;
			}
		}
		else
		{
			if(((p1+p2)/k)%2==0)
			{
				cout<<"CHEF"<<endl;
			}
			else
			{
				cout<<"COOK"<<endl;
			}

		}

	}
}