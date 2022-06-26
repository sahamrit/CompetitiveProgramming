#include<bits/stdc++.h>
using namespace std;
long long intlog(double base, double x) {
    return (long long )(log(x) / log(base));
}
int a[1000000];
long double b[10001][41];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	long long n,k,temp,temp1,genuine,temp3;
	cin>>t;
	for(int i=1;i<=1000000;i++)
	{
		a[i]=intlog(3,i);
	}

     for(int i=1;i<=10000;i++ )
     {
     	for(int k=0;k<=40;k++)
     	{
     		if(k==0)
		{
			b[i][k]=1/(long double)i;
		}
		else
		{
			if(i==1)
				b[i][k]=1;
		    else if(i==2)
		    	  b[i][k]=0.5;

		    if(i>=3)
		    {temp=i;temp1=i,genuine=0;
		    	for(int j=1;j<=k;j++)
		    	{
		    		if(j==1)
		    			temp=max((temp1/3)*2,temp1-(temp1/3)*2);
		    		else
		    		{  if(min(genuine,temp1)>1000000)
		    			temp3=(long long )pow(3,intlog(3,min(genuine,temp1)));
		    			else 
		    				temp3=(long long )pow(3,a[min(genuine,temp1)]);
		    		temp=min(max((temp1/3)*2,temp1-(temp1/3)*2),max(temp3,temp1-temp3));
		    	    }  
		    	     genuine+=temp1-temp;
		    	     temp1=temp;

		    		if(temp==0||temp==1||j>100)
		    			break;

		    	}
		    	if(temp==0)
		    	b[i][k]=1;
		    else
		    {
		    	b[i][k]=1/(long double)temp;
		    }


		    }
		   
     	}
     }
 }

	for(int i=0;i<t;i++)
	{
		cin>>n>>k;
		if(k==0)
		{
			cout<<1/(long double)n<<endl;
		}
		else
		{
			if(n==1)
				cout<<1<<endl;
		    else if(n==2)
		    	cout<<0.5<<endl;

		    if(n>=3)
		    {temp=n;temp1=n,genuine=0;
		    	for(int j=1;j<=k;j++)
		    	{
		    		if(j==1)
		    			temp=max((temp1/3)*2,temp1-(temp1/3)*2);
		    		else
		    		{  if(min(genuine,temp1)>1000000)
		    			temp3=(long long )pow(3,intlog(3,min(genuine,temp1)));
		    			else 
		    				temp3=(long long )pow(3,a[min(genuine,temp1)]);
		    		temp=min(max((temp1/3)*2,temp1-(temp1/3)*2),max(temp3,temp1-temp3));
		    	    }  
		    	     genuine+=temp1-temp;
		    	     temp1=temp;
		    	     if(temp<10000)
		    	     {
		    	     	cout<<b[temp][min(k,(long long)40)-j]<<endl;
		    	     	break;
		    	     }

		    		

		    	}
		    	


		    }
		   

		}
	}
}