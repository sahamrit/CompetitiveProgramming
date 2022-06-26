#include<bits/stdc++.h>
#define p (int)(1e9+7)
using namespace std;
long long ncr[1001][1001];
void preprocess_binomial()
{
	for(int j=0;j<=1000;j++)ncr[0][j]=0;
    for(int j=0;j<=1000;j++)
    {
    	for(int i=1;i<=1000;i++)
    	{
    		if(j==0||j==i)ncr[i][j]=1;
    		else if(i<j)ncr[i][j]=0;
    		else {
    			ncr[i][j]=(ncr[i-1][j]%p+ncr[i-1][j-1]%p)%p;
    		}
    	}
    }

}
int main()
{
	preprocess_binomial();
	cout<<ncr[20][3];
}