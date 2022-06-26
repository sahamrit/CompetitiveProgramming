#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,k,a,b;
	cin>>n>>k>>a>>b;
	long long int x=LLONG_MAX,y=LLONG_MIN,res;
	
	for(int i=0;i<n;i++)
	{
		res=n*k/__gcd(n*k,i*k+(a+b)%k);
		if(x>res)
			x=res;
		if(y<res)y=res;

		res=n*k/__gcd(n*k,i*k+(k+a-b)%k);
		if(x>res)
			x=res;
		if(y<res)y=res;

		res=n*k/__gcd(n*k,i*k+(k+b-a)%k);
		if(x>res)
			x=res;
		if(y<res)y=res;

		res=n*k/__gcd(n*k,i*k+(2*k-a-b)%k);
		if(x>res)
			x=res;
		if(y<res)y=res;	
	}
	cout<<x<<" "<<y<<endl;
}