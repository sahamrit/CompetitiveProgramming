#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	long long n,k,temp;
	cin>>t;

	for(int i=0;i<t;i++)
	{
		cin>>n>>k;
		if(k==0)
		{
			cout<<1/(long double)n<<endl;
		}
		else
		{
			if(n==1)
				cout<<1<<endl;
		    else if(n==2)
		    	cout<<0.5<<endl;

		    if(n>=3)
		    {temp=n;
		    	for(int j=1;j<=k;j++)
		    	{
		    		temp=(temp/3)*2;
		    		if(temp==0)
		    			break;

		    	}
		    	if(temp==0)
		    	cout<<1<<endl;
		    else
		    {
		    	cout<<1/(long double)temp<<endl;
		    }


		    }
		   

		}
	}
}