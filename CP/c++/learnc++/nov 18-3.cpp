#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n, x,diff;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		if(n==1)
			cout<<1<<" "<<2<<" ";
		else if(n==2)
			cout<<1<<" "<<4<<" ";
		else{
		       x=pow(2,n-1);
		       diff=pow(2,n-2)*(-1);
		       while(abs(diff)>=1)
		       {
		       	x+=diff;
		       	diff=(-1)*(diff/2);

		       }
		       cout<<x<<" "<<(long long)pow(2,n)<<" ";
	        }

	}
}