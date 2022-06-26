#include<bits/stdc++.h>
using namespace std;
long long int A[1001][1001],S[1001][1001];
long long int dp[1001][1001];
bool P[1001][1001];
int main()
{
	string s;
	cin>>s;
	int n=s.size();
	memset(P,false,sizeof(P));
    
    for (int i= 0; i< n; i++) 
        {	P[i][i] = true;

        }	 
  
 
	for(int i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])
		{
			A[i][i+1]=1;
			S[i][i+1]=1;
			P[i][i+1]=true;
			dp[i][i+1]=1;

		}
	}
	for(int k=2;k<n;k++)
	{
		for(int i=0;i+k<n;i++)
		{
            if (s[i] == s[i+k] && P[i+1][i+k-1] ) 
                P[i][i+k] = true; 
  

            if (P[i][i+k] == true) 
                dp[i][i+k] = dp[i][i+k-1] + dp[i+1][i+k] + 1 - dp[i+1][i+k-1]; 
            else
                dp[i][i+k] = dp[i][i+k-1] + dp[i+1][i+k] - dp[i+1][i+k-1]; 

			A[i][i+k]=A[i][i+k-1]+A[i+1][i+k]-A[i+1][i+k-1];
			if(s[i]==s[i+k])
			{
				
				S[i][i+k]=S[i+1][i+k-1]+dp[i+1][i+k-1]-dp[i+2][i+k-1]
				+dp[i+1][i+k-1]-dp[i+1][i+k-2]+3;
				A[i][i+k]+=S[i][i+k];
	
			}
			else
			{
				S[i][i+k]=0;
			}
		}
	}
	cout<<A[0][n-1]<<endl;

}