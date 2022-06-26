#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int diff[N],a[N],alpha,ctr,xold,x,upidx,temp;
long long anger[N],sum;
int n,k,fract;
bool check;
long double preprocess[100005];
bool modulo[100001][1001]; 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=100000;i++)
	{	
		for(int j=1;j<=1000;j++)
		{
			modulo[i][j]=i%j?false:true;
		}
		preprocess[i]=(long double)1/i;
	}

	while(t--)
	{	
		cin>>n>>k;
 		sum=0;
 		cin>>a[1];
 		sum+=a[1];
		for(int i=2;i<=n;i++) {cin>>a[i];sum+=a[i]/(i);diff[i]=-a[i-1]/(i-1);}
        diff[1]=anger[1]=sum;

 	   for(int i=n;i>=2;i--){
 	   	alpha=i;
 	   	ctr=0;
 	   	xold=a[i]/i;
 	   	while(alpha>=1){
 	   			if(alpha<=1000){
 	   				if(modulo[a[i]][alpha])
 	   				x=round(a[i]*preprocess[alpha]);
 	   				else
 	   				x=(int)(a[i]*preprocess[alpha]); 	   					
				 	}
 	   			else{
 	   				if(a[i]%alpha==0)
 	   					x=round(a[i]*preprocess[alpha]);
 	   				else
 	   					x=(int)(a[i]*preprocess[alpha]);
 	   				}
			ctr=x-xold;
					if(x<1000){
						if(modulo[a[i]][x+1])
	   						upidx=i-round(a[i]*preprocess[x+1]);
	   					else 
	   						upidx=i-(int)(a[i]*preprocess[x+1]);
					}
					else{
						if(a[i]%(x+1)==0)
	   						upidx=i-round(a[i]*preprocess[x+1]);
	   					else 
	   						upidx=i-(int)(a[i]*preprocess[x+1]);
	   					}
 	   		diff[i-alpha+1]+=ctr;
 	   		diff[upidx+1]-=ctr;
 	   		alpha=i-upidx;
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