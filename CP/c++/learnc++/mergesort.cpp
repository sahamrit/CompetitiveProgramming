#include<iostream>
#include<time.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

void merging(int A[],int B[],int C[],int m,int n)
{
    int i=0,j=0,k=0;
    while(i<m&&j<n)
    {
        if(A[i]<B[j])
            C[k++]=A[i++];
        else if(A[i]>B[j])
        C[k++]=B[j++];
        else {C[k++]=A[i++];
              C[k++]=B[j++];
        }

    }
    while(i<m)
        C[k++]=A[i++];
    while(j<n)
         C[k++]=B[j++];

}

void mergesort(int A[],int n)
{
    if(n==1)return;
    int i=n/2;
    int *B=new int [n];
    mergesort(A,i) ;
    mergesort(A+i,n-i);
    merging(A,A+i,B,i,n-i);
    for(i=0;i<n;i++)
        A[i]=B[i];
    delete [] B;
}

int main()
{int A[(int)pow(10,3)];
srand(time(0));
for(int i=0;i<pow(10,3);i++)
    A[i]=rand()%10000000+1;
cout<<"unsorted array is:\n";

 mergesort(A,pow(10,3));
 cout<<"new array is\n";
 for(int i=0;i<pow(10,3);i++)
 cout<<A[i]<<" ";



}
