#include<bits/stdc++.h>
using namespace std;
int n,t,k;
long long fn[1001][1001];
#define M 1000000007
int main()
{
	

	cin>>t;
	for(int i=0;i<t;i++)
	{
     cin>>n>>k;
     for(int j=0;j<=k;j++)
     	for(int p=j;p<=min(n,j+n-k);p++)
     	{
     		if(j==0)
     		{
     			if(p==0)
     				fn[0][0]=0;
     			else
     			fn[0][p-(j)]=1;

     		}
     		else if(j==1)
     		{
     			fn[1][p-(j)]=(2*p)%M;
     		}
     		else if(p==j)
     		{
     			fn[j][p-(j)]=2;

     		}
     		else 
     		{
     			fn[j][p-(j)]=(fn[j][p-1-(j)]%M+fn[j-1][p-2-(j-1)]%M+fn[j-1][p-1-(j-1)]%M)%M;
     		}
     	}
     	
     	 for(int j=0;j<=k;j++)
     	 {
     	for(int p=j;p<=min(n,j+n-k);p++)
     	{
     	    cout<<fn[j][p-j]<<" ";
     	}
     	cout<<endl;
     	 }
     	 


	}


}