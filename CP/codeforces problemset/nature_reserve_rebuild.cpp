#include<bits/stdc++.h>
using namespace std;
pair<int,int> animals[100001];
bool possible(long double rmodified,int n)
{
	long double r=rmodified*(1e-8),sqrdxdiff,sqrdxdifftemp;
	pair<long double,long double>segment,temp_segment;
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			if(fabs(animals[i].second-r)>r)
				return false;
		 sqrdxdiff=fabs(animals[i].second*(animals[i].second-2*r));
			segment.first=animals[i].first-sqrt(sqrdxdiff);
			segment.second=animals[i].first+sqrt(sqrdxdiff);
		}
		else{
		if(fabs(animals[i].second-r)>r)
				return false;
		    sqrdxdifftemp=fabs(animals[i].second*(animals[i].second-2*r));
			temp_segment.first=animals[i].first-sqrt(sqrdxdifftemp);
			temp_segment.second=animals[i].first+sqrt(sqrdxdifftemp);

		 if(segment.first>temp_segment.second||segment.second<temp_segment.first)
		 	return false;
		 segment.first=max(segment.first,temp_segment.first);
		 segment.second=min(segment.second,temp_segment.second);
		}
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	bool negative=false,positive=false;
	for(int i=0;i<n;i++)
	{
		cin>>animals[i].first>>animals[i].second;
		if(animals[i].second>0)
			positive=true;
		else if(animals[i].second<0)
			negative=true;

	}
	if(positive&&negative)
		cout<<-1<<endl;
	else if(n==1)
	{
		cout<<(double)animals[0].second/2<<endl;
	}
	else
	{
		if(negative)
		{
			for(int i=0;i<n;i++)
			{
				animals[i].second=-animals[i].second;
			}
		}

    // if(possible(50000000000000.4949989318847656*(1e8),n))
     //	cout<<"yes"<<endl;
		long double x = 0;
		int ctr1=0;
		for (long double b = (1e+16)*(1e+8); b >= 1; b /= 2)
		 { 
		   ctr1=0;
		 	while (!possible(x+b,n)) 
		 			{
		 				x += b;
		 				ctr1++;
		 				if(ctr1>2)
		 				break;
		 			}
		  }
		  long double k = x+1;
		  if(k==0)
		  cout<<-1<<endl;
		  else 
		  cout<<fixed<<setprecision(20)<<(k)*(1e-8)<<endl;

	}
}