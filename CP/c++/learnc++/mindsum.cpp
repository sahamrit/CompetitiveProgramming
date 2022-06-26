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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	long long n,d,temp;
	for(int i=0;i<t;i++)
	{
		int ctr=0;
		cin>>n>>d;
		temp=n;
		if(d%9==0)
		{

			
			while(temp>=10)
			{
				temp=digitsum(temp);
				ctr++;
			}
			cout<<digitsum1(n)<<" "<<ctr<<endl;

		}
		else if(d%9!=3&&d%9!=6)
		{
			temp=n;
			while(digitsum1(temp)!=1)
			{
				ctr++;
				temp=temp+d;


			}
			while(temp>=10)
			{
				temp=digitsum(temp);
				ctr++;
			}
			cout<<1<<" "<<ctr<<endl;

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

			temp=n;
			while(digitsum1(temp)!=minimum)
			{
				ctr++;
				temp=temp+d;


			}
			while(temp>=10)
			{
				temp=digitsum(temp);
				ctr++;
			}
			cout<<minimum<<" "<<ctr<<endl;
		}
	}
}