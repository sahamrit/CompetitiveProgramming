#include<bits/stdc++.h>
using namespace std;
long long digitsum1(long long a)
{
	if(a<10)
		return a;
	long long sum=0;
	while(a>0)
	{
		sum+=a%10;
		a/=10;
	}
	digitsum1(sum);
}
long long digitsum(long long a)
{
	
	long long sum=0;
	while(a>0)
	{
		sum+=a%10;
		a/=10;
	}
	return (sum);
}
pair<int,int> mindsum(long long n,long long d,int ctr)
{
    if(d%9==0)
		{
			if(n==digitsum1(n)||ctr>15)
				return make_pair(ctr,n);

			
			return min(mindsum(digitsum(n),d,ctr+1),mindsum(n+d,d,ctr+1));

		

		}
		else if(d%9!=3&&d%9!=6)
		{
			if(n==1||ctr>15)
				return make_pair(ctr,n);

			
			return min(mindsum(digitsum(n),d,ctr+1),mindsum(n+d,d,ctr+1));

		}
		else if(d%9==3||d%9==6)
		{
			int tempsum=digitsum1(n);
			int minimum;
			if(tempsum==1 || tempsum==4 || tempsum==7)
			{
				minimum=1;

			}
			else if(tempsum==2 || tempsum==5 || tempsum==8)
			{
				minimum=2;
			}
			else if(tempsum==3 || tempsum==6 || tempsum==9)
			{
				minimum=3;
			}
			if(n==minimum||ctr>15)
				return make_pair(ctr,n);

			
			return min(mindsum(digitsum(n),d,ctr+1),mindsum(n+d,d,ctr+1));

		}

		

			
		
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	long long n,d,temp;
	pair<int,int>p;
	for(int i=0;i<t;i++)
	{
		cin>>n>>d;
		p=mindsum(n,d,0);
		cout<<p.second<<" "<<p.first<<endl;
	}
}