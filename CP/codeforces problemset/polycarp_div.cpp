#include<bits/stdc++.h>
using namespace std;
string s;
int last_idx[3],dp[200002];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>s;
  memset(last_idx,-1,sizeof(last_idx));
  int rem=0;
  for(int i=0;i<s.size();i++)
  {
  	rem=(rem+s[i]-'0')%3;
  	if(last_idx[rem]==-1)
  	{
  		last_idx[rem]=i;
  		if(rem==0)
  		    {  if(i==0)
  				dp[i]=1;
  			   else
  			   	dp[i]=max(dp[i-1],1);

  			}
  		else
  		{
  			if(i==0)
  				dp[i]=0;
  			else
  				dp[i]=max(dp[i-1],0);
  		}
  	}
  	else
  	{
  		dp[i]=max(dp[i-1],dp[last_idx[rem]]+1);
  		last_idx[rem]=i;
  	}

  }
  cout<<dp[s.size()-1]<<endl;
}