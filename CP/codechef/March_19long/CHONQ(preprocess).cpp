#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int diff[N],a[N],alpha,ctr,xold,x,upidx,loidx,upidx1;
long long anger[N],sum,temp;
int preprocess[10001][801];
int n,k,fract;
bool check;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
 	   for(int i=10000;i>=2;i--){
 	   	x=0;
 	   	while(x<=800&&i>=(x+1)){
 	   		preprocess[i][x]=i/(x+1)+1;
 	   		x++;
 	   			}

 	  	}		
	while(t--)
	{	
		cin>>n>>k;
 		sum=0;
 		cin>>a[1];
 		sum+=a[1];
		for(int i=2;i<=n;i++) {cin>>a[i];sum+=a[i]/(i);diff[i]=-a[i-1]/(i-1);}
        temp=diff[1]=anger[1]=sum;

 	   for(int i=n;i>=2;i--){
 	   	alpha=i;
 	   	xold=a[i]/i;
 	   	while(alpha>=1){
 	   		x=a[i]/alpha;
 	   		if(x<=800&&a[i]>=(x+1)&&a[i]<=10000)
 	   		{
 	   			ctr=x-xold;
	  		loidx=i-alpha+1;
	  		upidx=i-preprocess[a[i]][x]+1;
	  		diff[loidx]+=ctr;
	  		diff[upidx+1]-=ctr;
	  		alpha=preprocess[a[i]][x]-1;

 	   		}
 	   		else{
			ctr=x-xold;
	  		loidx=i-alpha+1;
 	   		upidx1=a[i]/(x+1)+1;
 	   		upidx=i-upidx1+1;
 	   		diff[loidx]+=ctr;
 	   		diff[upidx+1]-=ctr;
 	   		alpha=upidx1-1;
 	   			}
 	   		}	
 	  	}	
         	check=false;
 	   		for(int i=1;i<=n;i++){
           	anger[i]=anger[i-1]+diff[i];  
           	if(anger[i]<=k){cout<<i<<endl;check=true;break;}           
 	   		} 
      		if(check==false)cout<<n+1<<endl;
	}
}