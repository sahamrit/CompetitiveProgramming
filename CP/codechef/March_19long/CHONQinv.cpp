#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int main()
{
	int diff[N],a[N],alpha,ctr,xold,x,upidx,temp,n,k,fract,sum,anger[N],t;
	long double inv[N];
	bool check;	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;

	for(int i=1;i<=100000;i++)
	{
		inv[i]=(long double)1/(i+1e-12);
	}

	while(t--)
	{	
		cin>>n>>k;
 		cin>>a[1];
 		sum=a[1];
		for(int i=2;i<=n;++i) {cin>>a[i];
			sum+=a[i]/(i);
			diff[i]=-a[i-1]/(i-1);}
        diff[1]=anger[1]=sum;

 	   for(int i=n;i>=2;--i){
 	   	alpha=min(i,a[i]); 	   	
			xold=a[i]/i;

 	   	while(alpha>=1){
			x=a[i]*inv[alpha];
			ctr=x-xold;
 	   		diff[i-alpha+1]+=ctr;	
			alpha=a[i]*inv[x+1];
 		   	diff[i-alpha+1]-=ctr;
 		   		}
 	   		}   	   		   			
        	check=false;
 	   		for(int i=1;i<=n;++i){
           	anger[i]=anger[i-1]+diff[i];  
           	if(anger[i]<=k){cout<<i<<endl;check=true;break;}           
 	   		} 
      		if(check==false)cout<<n+1<<endl;
	}
}