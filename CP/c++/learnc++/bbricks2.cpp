#include<bits/stdc++.h>
using namespace std;
int n,t,k;
int fn[2][1000001];
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
     			fn[1][p-(j)]=2;

     		}
     		else 
     		{
     			fn[1][p-(j)]=fn[1][p-1-(j)]%M+fn[0][p-2-(j-1)]%M+fn[0][p-1-(j-1)]%M;
     		}
     	}
     	cout<<fn[k][n-(k)]<<endl;


	}


}