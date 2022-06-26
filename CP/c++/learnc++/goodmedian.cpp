#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
int a[1000];
tuple<int,int,int>b[1000];
long long binomialCoeffarray[1000][1000];
void binomialCoeff(int n, int k) 
{ 
     
    int i, j; 
  
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= min(i, k); j++) 
        { 
            
            if (j == 0 || j == i) 
                binomialCoeffarray[i][j] = 1; 
            else
                binomialCoeffarray[i][j] = (binomialCoeffarray[i-1][j-1]%M + binomialCoeffarray[i-1][j]%M)%M; 
        } 
    } 
  
} 

//https://math.stackexchange.com/questions/964149/calculating-a-b-mod-p
long long  power(long long x, long long y, long long p) 
{ 
    __int128_t res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return (long long)(res%p); 
} 

int main()
{
	int t,n;
	cin>>t;
	binomialCoeff(1000,1000);
	for(int i=0;i<t;i++)
	{
		cin>>n;
		for(int j=0;j<n;j++)
			cin>>a[j];
		sort(a,a+n);
	int ctrb=0,start=-1,end=-1;
	for(int j=0;j<n;j++)
	 { 
		if(j==0)
		{
			if(a[j]==a[j+1])
			{
				start=j;
			}

		}
		else if(j==n-1)
		{
			if(a[j]==a[j-1])
				end=j;
		}
		else
		{
            if(a[j-1]!=a[j]&&a[j]==a[j+1])
            	start=j;
            if(a[j]==a[j-1]&&a[j]!=a[j+1])
            	end=j;
		}
		if(start!=-1&&end!=-1)
		{
			b[ctrb++]=make_tuple(start,end,end-start+1);
			start=-1;
			end=-1;
		}
     }
     __int128_t sum=0;
     sum=(sum%M+power(2,n-1,M))%M;
     int p,q,len,m;
    
     for(int j=0;j<ctrb;j++)
     {
     	
     	len=get<2>(b[j]);
     	p=get<0>(b[j]);
     	q=n-1-(get<1>(b[j]));
     	m=min(p,q);
     	sum=(sum%M+binomialCoeffarray[n-len][m])%M;
     	if(len>2&&m<=n-2&&m+len-2<=n-2)
     		sum=(sum%M+binomialCoeffarray[n-2][m]+binomialCoeffarray[n-2][m+len-2])%M;
     	for(int k=1;k<=len-3;k++)
     	{
     		if(k+m<=n-2)
     		sum=(sum%M+(2*binomialCoeffarray[n-2][k+m])%M)%M;
     	}

     }
     cout<<(long long)sum<<endl;
    } 
}