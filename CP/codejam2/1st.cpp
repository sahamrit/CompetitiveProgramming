#include<bits/stdc++.h>
using namespace std;
const int SZ=100005;
int ax[SZ],diffx[SZ],ay[SZ],diffy[SZ];
int main()
{
	int t,p,q,x,y;cin>>t;
	int maxx,maxidxx,maxy,maxidxy;
	int n=t;
	char c;
	while(t--)
	{
		cin>>p>>q;
		for(int i=0;i<=q+5;i++)
		{
			diffy[i]=diffx[i]=0;
		}
		for(int i=0;i<p;i++)
		{
			cin>>x>>y;
			x++;y++;
			cin>>c;
			if(c=='N')
			{
				diffy[y+1]++;
			}
			else if(c=='S')
			{
				diffy[0]++;diffy[y]--;
			}
			else if(c=='E')
			{
				diffx[x+1]++;
			}
			else if(c=='W')
			{
				diffx[0]++;diffx[x]--;
			}						

		}
		ax[0]=0;ay[0]=0;

		for(int i=1;i<=q+1;i++)
		{

			ax[i]=ax[i-1]+diffx[i];
			ay[i]=ay[i-1]+diffy[i];
			if(i==1)
			{
				maxidxy=maxidxx=1;
				maxx=ax[1];maxy=ay[1];
			}
			else
			{
				if(ax[i]>maxx)
				{
					maxx=ax[i];
					maxidxx=i;
				}
				if(ay[i]>maxy)
				{
					maxy=ay[i];
					maxidxy=i;
				}

			}			
		}
		cout<<"Case #"<<n-t<<": "<<maxidxx-1<<" "<<maxidxy-1<<endl;
	}
}