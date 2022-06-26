#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			cout<<a[i][j]<<":";
		}
		cout<<endl;
	}
    
    for(int k=0;k<n/2;k++)
    {int temp=0;
    	for(int i=0;i<n-2*k-1;i++)
    	{temp=a[k][i+k];
    		a[k][i+k]=a[k+i][n-k-1];
    		a[k+i][n-k-1]=a[n-k-1][n-k-1-i];
    		a[n-k-1][n-k-1-i]=a[n-k-1-i][k];
    		a[n-k-1-i][k]=temp;

    	}
    }
    cout<<"rotated matrix"<<endl;
    for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			
			cout<<a[i][j]<<":";
		}
		cout<<endl;
	}


}