#include<bits/stdc++.h>
using namespace std;
int a[51][51];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n,m;
	cin>>t;
	while(t--)
	{

		cin>>n>>m;
		memset(a,0,sizeof(a[0][0])*m*n);
		vector<pair<int,int>> v; vector<int>w;
		int max_global=INT_MIN;
		if(m==1)
		{
			for(int i=0;i<n;i++ )
			{
				int p=i%4;
				if(p==0||p==1)a[i][1]=1;
				else a[i][1]=2;
				if(max_global<a[i][1])max_global=a[i][1];
			}
            cout<<max_global<<endl;
			for(int i=0;i<n;i++ )cout<<a[i][1]<<endl;
			
		}
	    else if(n==2||m==2)
	    {
            if(n==2)
                {
                   for(int i=0;i<2;i++)
                   {
                   	for(int j=0;j<m;j++)
                   	{
                   		int p=j%3;
                   		a[i][j]=p+1;
                   		if(max_global<a[i][j])max_global=a[i][j];

                   	}
                   } 
                   cout<<max_global<<endl;
                   for(int i=0;i<2;i++)
                   {
                   	for(int j=0;j<m;j++)
                   	{
                   		cout<<a[i][j]<<" ";

                   	}
                   	cout<<endl;
                   } 

                }
            else if(m==2)
                {
                	for(int i=0;i<n;i++)
                	{
                		for(int j=0;j<2;j++)
                		{
                			int p=i%3;
                   		     a[i][j]=p+1;
                   		if(max_global<a[i][j])max_global=a[i][j];

                		}
                	}
                	cout<<max_global<<endl;
                	for(int i=0;i<n;i++)
                   {
                   	for(int j=0;j<2;j++)
                   	{
                   		cout<<a[i][j]<<" ";

                   	}
                   	cout<<endl;
                   } 

                }
	    }
	    else{
		for(int i=0;i<n;i+=2)
		{
            if(i%4==0)
            {
              for(int j=0;j<m;j++)
              {
              	int p=j%4;
              	if(p==0||p==1)a[i][j]=1;
              	else a[i][j]=2;
                if(max_global<a[i][j])max_global=a[i][j]; 
              }
            }
            else if(i%4==2)
            {
            	for(int j=0;j<m;j++)
            	{
            		int p=j%4;
            		if(p==0||p==1)a[i][j]=2;
              	else a[i][j]=1;
              	if(max_global<a[i][j])max_global=a[i][j]; 
            	}

            }
		}
		int x,y;
		for(int i=1;i<n;i+=2)
		{
			for(int j=0;j<m;j++)
			{
               
               
               v.push_back(make_pair(i,j-2));
               v.push_back(make_pair(i-1,j-1));
               v.push_back(make_pair(i-1,j+1));
               v.push_back(make_pair(i+1,j-1));
               v.push_back(make_pair(i+1,j+1));
               v.push_back(make_pair(i-2,j));
              
               for(auto u:v){x=u.first;y=u.second;
                  if(x>=0 && y>=0 &&x<=n-1&&y<=m-1)
                  {
               	     w.push_back(a[x][y]);
                  }
                }
                sort(w.begin(),w.end());
                bool check=false;
                for(int k=0;k<w.size()-1;k++)
                {
                	if(w.size()==0)break;
                	if(w[0]>1){a[i][j]=1;check=true;break;}
                	if((w[k]!=w[k+1]-1)&&w[k]!=w[k+1]){a[i][j]=w[k]+1;check=true;break;}
                	
                }
                if(!check){
                	if(w.size()==0)a[i][j]=1;
                	else
                	a[i][j]=w[w.size()-1]+1;
                }
               
              if(max_global<a[i][j])max_global=a[i][j];
              v.clear();
              w.clear();
              }

		}

		cout<<max_global<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
	}
   }
}