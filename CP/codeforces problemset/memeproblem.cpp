#include<bits/stdc++.h>
using namespace std;

int main()
{
int t,d;
double a,b;
cin>>t;
for(int i=0;i<t;i++)
{
	cin>>d;
	if(4*d>d*d)
	{
		cout<<"N"<<endl;
	}
	else
	{
		double l=0,h=(double)d/2;
		double mid;
		while(l<h||fabs(l-h)<1e-9)
		{
			mid=l+(h-l)/2;
			a=mid;b=d-mid;
			if(fabs(a+b-d)<1e-9&&fabs(a+b-a*b)<1e-9)
			{
				a=mid;
				break;
			}
			else if(mid*(d-mid)>d)
			{
                h=mid; 
			}
			else
			{
				l=mid;
			}


		}
		b=d-a;
		if(a>b)
		cout<<"Y "<<setprecision(9)<<fixed<<a<<" "<<b<<endl;
	   else
	   	cout<<"Y "<<setprecision(9)<<fixed<<b<<" "<<a<<endl;
	}
}
}