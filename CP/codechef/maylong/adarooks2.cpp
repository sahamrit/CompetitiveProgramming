#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,n,temp;
	cin>>t;
	while(t--)
	{	
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				temp=j-i;
				if(temp==0||temp==10||temp==25||temp==41||temp==62||temp==84||temp==-8||temp==-13||temp==-17||temp==-19||temp==-20)
				{
					cout<<'O';
				}
				else
				{
					cout<<'.';
				}
			}
			cout<<endl;
		}

	}	
}