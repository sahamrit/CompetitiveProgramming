#include<bits/stdc++.h>
#include <boost/math/special_functions/binomial.hpp>
using namespace std;
int  n,t,r;
#define M 1000000007
//https://math.stackexchange.com/questions/964149/calculating-a-b-mod-p
long long  power(long long x, long long y, long long p) 
{ 
    __int128_t res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return (long long)(res%p); 
} 
//from geeksforgeeks https://www.geeksforgeeks.org/space-and-time-efficient-binomial-coefficient/
__int128_t  binomialCoeff(int n,int k) 
{ 
    __int128_t res = 1; 
  
    // Since C(n, k) = C(n, n-k) 
    if ( k > n - k ) 
        k = n - k; 
  
    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1] 
    for (int i = 0; i < k; ++i) 
    { 
        res=((res%M)*((n-i)%M))%M;
        res=((res%M)*(power(i+1,M-2,M)%M))%M;
    } 
    res=res%M;
    return res; 
}


int main()
{
     

     cin>>t;
     for(int i=0;i<t;i++)
     {
     cin>>n>>r;
     __int128_t  sum=0;
     for(long long  k=1;k<=min(n-r+1,r);k++)
     {
          sum=(sum%M+((binomialCoeff(r-1,k-1)%M)*(binomialCoeff(n-r+1,k)%M)*(power(2,k,M)%M))%M)%M;

     }
     cout<<(long long)sum<<endl;
     


     }


}