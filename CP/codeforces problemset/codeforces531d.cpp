#include<bits/stdc++.h>
#define p (int)(1e9+7)
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
    cin>>n;
	vector<int>a(n);
	char s;
	int cnt[3];
	 cnt[0]=0,cnt[1]=0,cnt[2]=0;
	for(int i=0;i<n;i++)
	{
      cin>>s;
      a[i]=s-'0';
      if(a[i]==0)cnt[0]++;
      else if(a[i]==1)cnt[1]++;
      else if(a[i]==2) cnt[2]++;

	}
	int mean=n/3;
 int low,mid,high;
 if(cnt[0]<=cnt[1]&&cnt[0]<=cnt[2])
 {
 	low=0;
 	if(cnt[1]>=cnt[2]){high=1;mid=2;}
 	else{high=2;mid=1;}
 }
 else if(cnt[1]<=cnt[0]&&cnt[1]<=cnt[2])
 {
 	low=1;
 	if(cnt[0]>=cnt[2]){high=0;mid=2;}
 	else{high=2;mid=0;}
 }
 else if(cnt[2]<=cnt[1]&&cnt[2]<=cnt[0])
 {
 	low=2;
 	if(cnt[1]>=cnt[0]){high=1;mid=0;}
 	else{high=0;mid=1;}
 }
 cout<<low<<" "<<mid<< " "<<high;
if(!(cnt[high]==mean && cnt[low]==mean))
{
	if(cnt[mid]<mean)
	{
		for(int i=0;i<n;i++)
		{
			if(cnt[high]==mean)break;
			if(a[i]==high)
			{
				if(cnt[low]<mean)
				{
					a[i]=low;cnt[low]++;cnt[high]--;
				}
				else if(cnt[mid]<mean)
				{
                    a[i]=mid;cnt[mid]++;cnt[high]--;
				}
			}
		}

	}
	else if(cnt[mid]==mean)
	{   if(low<high)
		{for(int i=0;i<n;i++)
         { if(cnt[high]==mean)break;
          if(a[i]==high)
          {
          	a[i]=low;cnt[low]++;cnt[high]--;
          }
         }
        }  
        else
        {
        	for(int i=n-1;i>=0;i--)
         { if(cnt[high]==mean)break;
          if(a[i]==high)
          {
          	a[i]=low;cnt[low]++;cnt[high]--;
          }
         }
        }
	}
	else if(cnt[mid]>mean)
	{for(int i=0;i<n;i++){
          if(cnt[high]==mean&&cnt[mid]==mean)
          	break;
          if(a[i]==high){a[i]=low;cnt[low]++;cnt[high]--;}
          else if(a[i]==mid){a[i]=low;cnt[low]++;cnt[mid]--;}}
	}
}





	
for(int i=0;i<n;i++)cout<<a[i];

	

}