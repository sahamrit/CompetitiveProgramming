#include<iostream>
#include <math.h>

 using namespace std;
int myPow(int x, int p) {
  if (p == 0) return 1;
  if (p == 1) return x;
  return x * myPow(x, p-1);
}
 int nosize(int m)
 {int i;
     for( i=0;m!=0;i++)
        m=m/10;
     return i;
 }
 int karatsuba(int x,int y,int m,int n )
 {
     if(m<3||n<3)return x*y;
     int a,b,c,d,p,q,r;
   if(m<=n)
   {
    a=x/myPow(10,m/2);

     b=x%myPow(10,m/2);

     c=y/myPow(10,m/2);

       d=y%myPow(10,m/2);

     p=  karatsuba(a,c,nosize(a),nosize(c));

      q= karatsuba(b,d,nosize(b),nosize(d));

       r=karatsuba(a+b,c+d,nosize(a+b),nosize(c+d));

   return myPow(10,2*(m/2))*p+q+myPow(10,m/2)*(r-p-q);
   }
    else
    {a=x/myPow(10,n/2);

     b=x%myPow(10,n/2);

     c=y/myPow(10,n/2);
       d=y%myPow(10,n/2);
     p=  karatsuba(a,c,nosize(a),nosize(c));

      q= karatsuba(b,d,nosize(b),nosize(d));

       r=karatsuba(a+b,c+d,nosize(a+b),nosize(c+d));

    return myPow(10,2*(n/2))*p+q+myPow(10,n/2)*(r-p-q);//important 2*(n/2)!=n
    }

 }
 int multiply(int x,int y)
 {return karatsuba( x,y,nosize(x),nosize(y));

 }
int main()
{
   cout<< endl<<multiply(349654,1331)<<endl;

}
