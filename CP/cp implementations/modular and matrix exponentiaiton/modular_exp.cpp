#include<bits/stdc++.h>
using namespace std;
int a[26];
int main()
{
	int n,loidx,hiidx;
	cin>>n;
	string s;

	for(int i=0;i<n;i++)
	{	for(int j=0;j<26;j++)a[i]=0;
		cin>>s;
				bool check=true;

		for(int j=0;j<s.size();j++)
		{
			if(a[s[j]-'a']==0)
				a[s[j]-'a']++;
			else {
				check=false;
				break;
			}
		}

		if(check==false)
			cout<<"No"<<endl;
		else
		{

			loidx=0;hiidx=25;

			for(int j=0;j<25;j++)
			{	
				if(a[0]==1){loidx=0;break;}
				if(a[j]==0 &&a[j+1]==1)
				{
					loidx=j+1;
					break;
				}
			}

			for(int j=0;j<25;j++)
			{
				if(a[j]==1 &&a[j+1]==0)
				{
					hiidx=j;
				}
			}
			if(a[25]==1)hiidx=25;
			for(int j=loidx;j<=hiidx;j++)
			{
				if(a[j]==0){check=false;break;}
			}
			if(check)cout<<"yes"<<endl;
			else cout<<"no"<<endl;

		}
	}
}