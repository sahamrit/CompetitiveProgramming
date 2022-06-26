#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
char ch[100][100];
int indeg[100][100];
int outdeg[100][100];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,n,m;
	cin>>t;
	while(t--)
	{
		m=0;
		cin>>n;
		vector<tuple<int,int,int>>ans;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>ch[i][j];
				indeg[i][j]=0;
				outdeg[i][j]=0;
				if(ch[i][j]=='O')
				{
					if(i-1>=0)
					{
						if(j-1>=0 && ch[i-1][j-1]=='O')
						{
							outdeg[i][j]++;
							indeg[i-1][j-1]++;
						}
						if(j+1<n && ch[i-1][j+1]=='O')
						{
							outdeg[i][j]++;
							indeg[i-1][j+1]++;
						}
					}
				}
			}
		}
		//indeg 2
		bool check=false;
		for(int i=n-1;i>=1;i--)
		{
			for(int j=0;j<n;j++)
			{
				check=false;
				if(ch[i][j]=='O' && indeg[i][j]==2 && outdeg[i][j]>0)
				{
					ch[i][j]='.';
					outdeg[i][j]=0;
					indeg[i][j]=0;
					outdeg[i+1][j-1]--;
					outdeg[i+1][j+1]--;
					if(i-1>=0)
					{
						if(j-1>=0 && ch[i-1][j-1]=='O')
						{
							indeg[i-1][j-1]--;
							if(!check)
							{
								check=true;
								ans.push_back(make_tuple(0,i,j));
								m++;
							}
						}
						if(j+1<n && ch[i-1][j+1]=='O')
						{
							indeg[i-1][j+1]--;
							if(!check)
							{
								check=true;
								ans.push_back(make_tuple(1,i,j));
								m++;
							}
						}
					}
				}
			}
		}
		//in1
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				check=false;
				if(ch[i][j]=='O'&& indeg[i][j]==1 && outdeg[i][j]>0)
				{
					ch[i][j]='.';
					outdeg[i][j]=0;
					indeg[i][j]=0;
					if(i+1<=n-1)
					{
						if(j-1>=0 && ch[i+1][j-1]=='O')
						{
							outdeg[i+1][j-1]--;
						}
						else if(j+1<n && ch[i+1][j+1]=='O')
						{
							outdeg[i+1][j+1]--;
						}

					}

					if(i-1>=0)
					{
						if(j-1>=0 && ch[i-1][j-1]=='O')
						{
							indeg[i-1][j-1]--;
							if(!check)
							{
								check=true;
								m++;
								ans.push_back(make_tuple(0,i,j));
							}
						}
						if(j+1<n && ch[i-1][j+1]=='O')
						{
							indeg[i-1][j+1]--;
							if(!check)
							{
								check=true;
								m++;
								ans.push_back(make_tuple(1,i,j));
							}
						}
					}
				}
			}
		}
		//in0
		for(int i=n-1;i>=1;i--)
		{
			for(int j=0;j<n;j++)
			{
				check=false;
				if(ch[i][j]=='O' && indeg[i][j]==0 && outdeg[i][j]>0)
				{
					ch[i][j]='.';
					outdeg[i][j]=0;
					if(i-1>=0)
					{
						if(j-1>=0 && ch[i-1][j-1]=='O')
						{
							indeg[i-1][j-1]--;
							if(!check)
							{
								check=true;
								m++;
								ans.push_back(make_tuple(0,i,j));
							}
						}
						if(j+1<n && ch[i-1][j+1]=='O')
						{
							indeg[i-1][j+1]--;
							if(!check)
							{
								check=true;
								m++;
								ans.push_back(make_tuple(1,i,j));
							}
						}
					}
				}
			}
		}
		cout<<m<<endl;
		for(int i=0;i<m;i++)
		{
			if(get<0>(ans[i])==0)
			{
				cout<<get<1>(ans[i])+1<<" "<<get<2>(ans[i])+1<<" "<<"L"<<endl;
			}
			else
			{
				cout<<get<1>(ans[i])+1<<" "<<get<2>(ans[i])+1<<" "<<"R"<<endl;
			}
		}
	}
}
