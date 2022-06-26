#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int ans=0;
	string s;cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='+')ans++;
		else
		{
			ans--;
			if(ans<0)
				ans++;
		}
	}	
	cout<<ans<<endl;
}