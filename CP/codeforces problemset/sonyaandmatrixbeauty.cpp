#include<bits/stdc++.h>
using namespace std;
const long long md1=1e9+7;
const long long md2=1e9+87;
const long long key1=31,key2=419,key3=397;
int cnt[251][30],a[260][260],mask[260],d1[260],d2[260];
long long hash_[260],temp_hash[260],p[30];
void precompute_power()
{
	p[0]=1;
	for(int i=1;i<30;i++)
	{
		p[i]=(p[i-1]*key1)%md1;
	}
}
bool is_palindrome(int x)
{
	return(bool) ((x==0)||(x&(x-1))==0);
}
long long solve(int i1,int i2)
{
	int n=0;
	for(int i=i1;i<=i2;i++)
	{
		temp_hash[n++]=hash_[i];
	}
	long long res=0;
	for (int i=0,l=0,r=-1;i<n;i++) 
	{
        int k=(i>r)?1:min(d1[l+r-i],r-i);
        while (0<= i-k && i+k<n && temp_hash[i-k]==temp_hash[i+k])
        {
        	k++;
        }
    	d1[i]=k--;
    	res+=d1[i];
    	if (i+k>r) 
    	{
        	l=i-k;
        	r=i+k;
    	}
    }	
    for (int i=0,l=0,r=-1;i<n;i++) 
    {
    	int k=(i>r)?0:min(d2[l+r-i+1],r-i+1);
    	while (0<= i-k-1&& i+k<n && temp_hash[i-k-1]==temp_hash[i+k])
    	{
        k++;
    	}
    	d2[i]=k--;
    	res+=d2[i];
    	if (i+k>r) 
    	{
        l=i-k-1;
        r=i+k;
    	}
    }	
    return res;   
}

int main()
{
	int n,m;
	string s;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		for(int j=0;j<m;j++)
		{
            a[i][j+1]=s[j]-'a';
		}
	}
	precompute_power();
	int x,i1,i2;
	long long ans=0;
	for(int j1=1;j1<=m;j1++)
	{
		memset(mask,0,sizeof(mask));
		memset(hash_,0,sizeof(hash_));
		for(int i=1;i<=n;i++)memset(cnt[i],0,sizeof(cnt[i]));
		for(int j2=j1;j2<=m;j2++)
		{
			for(int i=1;i<=n;i++)
			{
                x=a[i][j2];
				if(cnt[i][x])
				{
					hash_[i]=(hash_[i]%md1-(cnt[i][x]*p[x+1])%md1)%md1;//remove the previous count corresponding value from hash
					if(hash_[i]<0)
						hash_[i]+=md1;

				}
				cnt[i][x]++;
				hash_[i]=(hash_[i]%md1+(cnt[i][x]*p[x+1])%md1)%md1;//add current count corresponding value to hash
				mask[i]^=(1<<x);

			}
			i1=1;
			while(i1<=n)
			{
				if(!is_palindrome(mask[i1]))
				{
					i1++;
					continue;
				}
				i2=i1;
				while(i2<=n&&is_palindrome(mask[i2]))i2++;
				i2--;
				ans+=solve(i1,i2);
				i1=i2+1;
			}


		}	
	}
	cout<<ans;


}