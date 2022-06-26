#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int diff[N],a[N],alpha,x,tempidx,sum,n,k,fract,ctr;
long long anger[N];
struct ranges
{
	int alpha,x,next_alpha;
};
ranges temp;
int main()
{  	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<ranges>preprocess[N];
	int t;
	cin>>t;
	for(int i=100000;i>=1;i--){
		alpha=1;
		while(alpha<=i)
		{	x=i/alpha;
			temp.alpha=alpha;temp.x=x;temp.next_alpha=i/x+1;
			preprocess[i].push_back(temp);
			alpha=i/x+1;
		}
	}

	while(t--)
	{	
		cin>>n>>k;
		memset(anger,0,sizeof(anger));
		memset(diff,0,sizeof(diff));
		for(int i=1;i<=n;i++)cin>> a[i];

 	   for(int i=n;i>=1;i--){
 	   	alpha=1;
 	   	ctr=0;
 	   	while(alpha<=min(i,a[i])){
 	   		temp=preprocess[a[i]][ctr++];
 			alpha=temp.alpha;
 			x=temp.x;
 			diff[i-alpha+1]+=x;
 			alpha=temp.next_alpha;
 			diff[i-alpha+1]-=x;} 			
 	  	}
 	  		tempidx=n+1;
 	   		for(int i=n;i>=1;i--){
           	anger[i]=anger[i+1]+diff[i];
           	if(anger[i]<=k)tempidx=i;
 	   		}    
 		cout<<tempidx<<endl;
	}
}