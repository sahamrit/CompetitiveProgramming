#include<bits/stdc++.h>
using namespace std;
pair<int,int>animals[100001];
bool possible(long long rmodified,int n)
{
	
	double r=(double)rmodified*(1e-8);
	double temp,temp1,temp2;
	pair<double,double>segment,temp_segment;
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			if(fabs(r-animals[i].second)>r)
				return false;
			temp=(double)fabs(r-animals[i].second);
			if(fabs(r*r-temp*temp)<1e-9)
				temp2=0;
			else 
				temp2=r*r-temp*temp;
			segment.first=(double)animals[i].first-sqrt(temp2);
			segment.second=(double)animals[i].first+sqrt(temp2);
			continue;
		}
		if(fabs(r-animals[i].second)>r)
				return false;
			temp1=(double)fabs(r-animals[i].second);
			if(fabs(r*r-temp1*temp1)<1e-9)
				temp2=0;
			else 
				temp2=r*r-temp1*temp1;
		temp_segment.first=(double)animals[i].first-sqrt(temp2);
		temp_segment.second=(double)animals[i].first+sqrt(temp2);
		if(temp_segment.second<segment.first||temp_segment.first>segment.second)
			return false;
		else 
		{
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
	bool positive=false,negative=false;
	int maxy=0;
	for(int i=0;i<n;i++)
	{
		cin>>animals[i].first>>animals[i].second;
		if(animals[i].second >0)
			positive=true;
		else if(animals[i].second<0)
			negative=true;
		if(positive&&negative)
			break;
	}
	if(positive&&negative)
		cout<<-1<<endl;
	else if(n==1)
		cout<<(double)animals[0].second/2<<endl;
	else
	{
		if(negative)
		{
			for(int i=0;i<n;i++)
			{
               animals[i].second=animals[i].second*(-1);
			}
		}
		for(int i=0;i<n;i++)
			{
               if(maxy<animals[i].second)
               	maxy=animals[i].second;
			}

		long long x = 0;
		int ctr1=0; 
		for (long long b = 2*(long long )maxy*(100000000); b >= 1; b /= 2)
		 { 
		 	ctr1=0;
		 	while (!possible(x+b,n)) 
		 		{if (ctr1>2)
		 			break;
		 			x += b;
		 			ctr1++;
		 		}
		 }
		  long long k = x+1;
		  if(k==0||k==1)
		  cout<<-1<<endl;
		  else 
		  cout<<((double)k)*(1e-8)<<endl;	

	}

}