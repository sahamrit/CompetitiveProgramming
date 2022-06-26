#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
void multiply(long long a[2][2],long long b[2][2])
{
	long long m[2][2]={{0,0},{0,0}};
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				m[i][j]=(m[i][j]%M+((a[i][k]%M)*(b[k][j]%M))%M)%M;
			}

		}

	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			a[i][j]=(m[i][j])%M;
		}
	}
}
long long pow(long long a[2][2],int n)
{
	long long m[2][2]={{0,3},{1,2}};
	if(n==1)
		return a[0][0]%M;
	pow(a,n/2);
	multiply(a,a);
	if(n%2!=0)
		multiply(a,m);
	return a[0][0]%M;

}
int main()
{
	int n;
	cin>>n;
	long long a[2][2]={{0,3},{1,2}};
	cout<<pow(a,n);
}