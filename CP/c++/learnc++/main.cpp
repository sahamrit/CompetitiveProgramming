
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
   long double sum=0;
    for(long double i=1;i<23;i++)
        sum+=(i)/(pow(2,i));
    cout<<sum;

}
