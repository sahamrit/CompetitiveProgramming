#include<bits/stdc++.h>
#define endl "\n"
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int lcs[3001][3001];
char mov[3001][3001];
int main()
{
	fastio;
	string s,t;
	cin>>s>>t;
	int n=s.size(),m=t.size();
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0 || j==0)
				lcs[i][j]=0;
			else
			{
				if(s[i-1]==t[j-1])
				{
					lcs[i][j]=lcs[i-1][j-1]+1;
					mov[i][j]='y';
				}
				else
				{
					if(lcs[i-1][j]>lcs[i][j-1])
					{
						lcs[i][j]=lcs[i-1][j];
						mov[i][j]='u';
					}
					else
					{
						lcs[i][j]=lcs[i][j-1];
						mov[i][j]='l';
					}
				}
			}
		}
	}
	vector<char>ans;
	while(n>0&&m>0)
	{
		if(mov[n][m]=='y')
		{
			ans.push_back(s[n-1]);
			n--;m--;
		}
		else if(mov[n][m]=='u')
		{
			n--;
		}
		else if(mov[n][m]=='l')
		{
			m--;
		}
	}
	reverse(ans.begin(),ans.end());
	for(auto u:ans)
		cout<<u;	
}