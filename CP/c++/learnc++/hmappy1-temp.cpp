#include<bits/stdc++.h>
using namespace std;
int a[100000];
tuple<int,int,int>b[100000];
char c[300000];
int maxi(int n1,int n2,int n3)
{
	  if(n1 >= n2 && n1 >= n3)
    {
        return n1;
    }

    if(n2 >= n1 && n2 >= n3)
    {
        return n2;
    }

    if(n3 >= n1 && n3 >= n2) {
        return n3;
    }
	
	

}


int bsrch(int marker ,tuple<int,int,int> *x,int size,int n)
{
int start=0,end=size-1,mid;
if(get<1>(x[size-1])>=0&&get<1>(x[size-1])<get<0>(x[size-1]))
{
	if(marker>=get<0>(x[size-1])&&marker<=n-1)
	   		return size-1;
	   	else  if(marker<=get<1>(x[size-1])&&marker>=0)
	   			return size-1;

}
while(start<=end)
{
	mid=(start+end)/2;
	
	if(get<1>(x[mid])<=n-1&&get<0>(x[mid])<get<1>(x[mid]))
	{
		if(marker<get<0>(x[mid]))
	
		  end=mid-1;
	
		if(marker>get<1>(x[mid]))
			start=mid+1;
		if(marker>=get<0>(x[mid])&&marker<=get<1>(x[mid]))
			return mid;
	}
	else if(get<1>(x[mid])>=0&&get<1>(x[mid])<get<0>(x[mid]))
	{
		if(marker>get<1>(x[mid])&&marker<get<0>(x[mid]))
			start=mid+1;
		else if(marker<get<0>(x[mid])&&marker>get<1>(x[mid]))
		end=mid-1;
	   else 
	   {
	   	
	   	if(marker>=get<0>(x[mid])&&marker<=n-1)
	   		return mid;
	   	else  if(marker<=get<1>(x[mid])&&marker>=0)
	   			return mid;
	   	  	
	   		
	   }
	   

	}

}
return -1;
}

int main()
{
	int n,q,k,ctrones=0;
	cin>>n>>q>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
			ctrones++;
	}
	for(int i=0;i<q;i++)
	{
		cin>>c[i];
	}
	int start=-2,end=-2,startold=-1,endold=-1,len,max1=0,max2=0;
	tuple<int,int,int>temp;
	int ctrb=0;
	int marker=n-1;
	temp=make_tuple(-1,0,0);
	if(ctrones==n)
	{
		for(int i=0;i<q;i++)
		{
			if(c[i]=='?')
				cout<<min(k,n)<<endl;
		}
	}
	else if(ctrones==0)
	{
		for(int i=0;i<q;i++)
		{
			if(c[i]=='?')
				cout<<0<<endl;
		}
	}
	else
	{
		if(a[0]==1&&a[n-1]==1)
		{
			for(int i=0;i<n-1;i++)
			{
				if(a[i]==1&&a[i+1]==0)
				{
					end=i;
					break;
				}
			}
			for(int i=n-1;i>0;i--)
			{
				if(a[i]==1&&a[i-1]==0)
				{
					start=i;
					break;
				}
			}
			len=end+1+n-start;
			temp=make_tuple(start,end,len);
			int end1=end,start1=start;

			for(int i=end1+1;i<start1;i++)
			{
			if (a[i-1]==0&&a[i]==1&&a[i+1]==1)
			            start=i;
			 if(a[i-1]==1&&a[i]==1&&a[i+1]==0)
			             end=i;

			       if(end>start&&start!=startold&&end!=endold&&end!=-2&&start!=-2)
			       {
			       	b[ctrb++]=make_tuple(start,end,end-start+1);
			       	startold=start;
			       	endold=end;
			       }                 	
			}
			b[ctrb++]=temp;


		}
		else
		{
			for(int i=0;i<n;i++)
			{
				if(i==0||i==n-1)
				{
					if(i==0&&a[0]==1&&a[1]==1)
						start=0;
					if(i==n-1&&a[n-2]==1&&a[n-1]==1)
						end=n-1;

				}
				else{

			           if (a[i-1]==0&&a[i]==1&&a[i+1]==1)
			            start=i;
			           if(a[i-1]==1&&a[i]==1&&a[i+1]==0)
			             end=i;
			        }
			           if(end>start&&start!=startold&&end!=endold&&start!=-2&&end!=-2)
			             {
			       	       b[ctrb++]=make_tuple(start,end,end-start+1);
			       	       startold=start;
			       	       endold=end;
			              } 
			                       	
			}

		}
		int indxmax1=-1;
		for(int i=0;i<ctrb;i++)
		{

			if(max1<get<2>(b[i]))
				{max1=get<2>(b[i]);
					indxmax1=i;
				}
			

		}
		for(int i=0;i<ctrb;i++)
		{
			if(max2<get<2>(b[i])&&get<2>(b[i])<=max1&&i!=indxmax1)
			{
				max2=get<2>(b[i]);
			}
		}

		int index;
		for(int i=0;i<q;i++)
		{
			if(c[i]=='!')
				{
					if(marker==0)
					{
						marker=n-1;
					}
					else marker--;
				}
			else if(c[i]=='?')
			{
				index=bsrch(marker,b,ctrb,n);
				if(index==-1)
					cout<<max(1,min(k,max1))<<endl;
				else{
					if(get<1>(b[index])<=n-1&&get<0>(b[index])<get<1>(b[index]))
					{
						if(get<2>(b[index])!=max1)
						{
							cout<<max(1,min(k,max1))<<endl;
						}
						else if(get<2>(b[index])==max1)
						{
							cout<<max(1,min(k,maxi(max2,get<1>(b[index]) -marker,marker-get<0>(b[index])+1)))<<endl;
						}
					}
					else if(get<1>(b[index])>=0&&get<1>(b[index])<get<0>(b[index]))
					{

						if(get<2>(b[index])!=max1)
						{
							cout<<max(1,min(k,max1))<<endl;
						}
						else if(get<2>(b[index])==max1)
						{
							if(marker>=get<0>(b[index])&&marker<=n-1)
							cout<<max(1,min(k,maxi(max2,get<1>(b[index])+n-marker,marker-get<0>(b[index])+1)))<<endl;
						   else if(marker>=0&&marker<=get<1>(b[index]))
						   {
						   	cout<<max(1,min(k,maxi(max2,get<1>(b[index])-marker,get<2>(b[index])-(get<1>(b[index])-marker))))<<endl;
						   }
						}
					}
				    }

			}
		}

	}  
}