#include<bits/stdc++.h>
using namespace std;
const int N=200000;
int diff[N],a[N],alpha,x,tempidx,sum,n,k,fract;
long long anger[N];
int preprocess[100001][1001];

int main()
{  	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	for(int i=1;i<=100000;i++)
	{
		for(int j=1;j<=min(i,1000);j++)
		{
			preprocess[i][j]=i/j;
		}
	}
	while(t--)
	{	
		cin>>n>>k;
		memset(diff,0,sizeof(diff));
		memset(anger,0,sizeof(anger));

		for(int i=1;i<=n;i++)cin>> a[i];

 	   for(int i=n;i>=2;i--){
 	   		x=a[i];
 	   		diff[i]+=x;
 	   	for(alpha=1;alpha<=min(i,a[i]);alpha++){
 	   		diff[i-alpha+1]-=x; 
	   		if(alpha<=1000)
	   			x=preprocess[a[i]][alpha];
	   		else x=a[i]/alpha;
 	   		diff[i-alpha+1]+=x;
 	   		if(x<=1000)
 	   			alpha=preprocess[a[i]][x];
 	   		else
 	   		alpha=a[i]/x;
 	   			}
 	   	 	 diff[i-alpha+1]-=x;
 	  	}
 	  		tempidx=n+1;
 	   		for(int i=n;i>=1;i--){
           	anger[i]=anger[i+1]+diff[i];
           	if(anger[i]<=k)tempidx=i;
 	   		}    
 		cout<<tempidx<<endl;
	}
}