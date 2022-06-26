#include<bits/stdc++.h>
using namespace std;
double distance(int x1,int y1,int x2,int y2)
{
	return sqrt((double)(x1-x2)*(x1-x2)+(double)(y1-y2)*(y1-y2));
}
tuple<int,int,int>a[1000];
pair<int,char>prefixsum[2000000];
int prefixsum1[2000000];
	int ctr=0,ctr1=0;
int b_search(int key)
{    
int beg=0;
int end=ctr-1;
int res=-1;
while(beg<=end)
{
	int mid=beg+(end-beg)/2;
	if(prefixsum[mid].first<=key)
	{
		beg=mid+1;
		res=mid;
	}
	else
	{
		end=mid-1;
	}
	
}
return res;
}	
int main()
{
	int n,q,k;
	double alpha;
	cin>>n>>q;
	int x,y,r1,m,z,r2;

	for(int i=0;i<n;i++)
	{
		cin>>x>>y>>r1;
		a[i]=make_tuple(x,y,r1);

	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			tie(x,y,r1)=a[i];
			tie(m,z,r2)=a[j];
			alpha=distance(x,y,m,z);
			if(abs(alpha-r1-r2)<1e-9)
			{
				//circles touch
				prefixsum[ctr++]=make_pair(0,'s');
				prefixsum[ctr++]=make_pair(floor(alpha+r1+r2)+1,'e');


			}		
			else if(abs(alpha-abs(r1-r2))<1e-9)
			{
				//circle is  just within another
				prefixsum[ctr++]=make_pair(0,'s');
				prefixsum[ctr++]=make_pair(floor(alpha+r1+r2)+1,'e');
				


			}
			else if(alpha>r1+r2)
			{
				//circles are apart 
				prefixsum[ctr++]=make_pair(ceil(alpha-r1-r2),'s');
				prefixsum[ctr++]=make_pair(floor(alpha+r1+r2)+1,'e');

			}
		    else if(alpha<abs(r1-r2))
		    {
		       prefixsum[ctr++]=make_pair(ceil(abs(r1-r2)-alpha),'s');
				prefixsum[ctr++]=make_pair(floor(alpha+r1+r2)+1,'e');


		    }
			else
			{
				//circles intersect
				prefixsum[ctr++]=make_pair(0,'s');
				prefixsum[ctr++]=make_pair(floor(alpha+r1+r2)+1,'e');

			}
		}
		sort(prefixsum,prefixsum+ctr);
		for(int i=0;i<ctr;i++)
		{
			if(prefixsum[i].second=='s')
			{
				ctr1++;
				prefixsum1[prefixsum[i].first]=ctr1;
			}
			if(prefixsum[i].second=='e')
			{
				ctr1--;
				prefixsum1[prefixsum[i].first]=ctr1;
			}

		}
		for(int i=0;i<q;i++)
		{
			cin>>k;
			int result=b_search(k);
			if(result==-1)
				cout<<0<<endl;
			else
			cout<<prefixsum1[prefixsum[result].first]<<endl;

		}



}