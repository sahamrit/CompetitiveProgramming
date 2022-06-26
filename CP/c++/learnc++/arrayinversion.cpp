#include<iostream>
#include<time.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
const int N=6;
int  mergingandsplitcount(int A[],int B[],int C[],int m,int n)
{    int ctr=0;
    int i=0,j=0,k=0;
    while(i<m&&j<n)
    {
        if(A[i]<B[j])
            C[k++]=A[i++];
        else if(A[i]>B[j])
        {C[k++]=B[j++];
        ctr+=m -i;}
        else {C[k++]=A[i++];
              C[k++]=B[j++];
        }

    }
    while(i<m)
        C[k++]=A[i++];
    while(j<n)
         C[k++]=B[j++];
         return ctr;

}

int  mergesortandnonsplit(int A[],int n)
{
    if(n<=1)return 0;
    int i=n/2;
    int *B=new int [n];
   int x= mergesortandnonsplit(A,i) ;
   int y= mergesortandnonsplit(A+i,n-i);
    int z=mergingandsplitcount(A,A+i,B,i,n-i);
    for(i=0;i<n;i++)
        A[i]=B[i];
    delete [] B;
    return x+y+z;
}

int main()
{int A[100];
int inversions=0;
cout<<"enter N elements of array \n";

for(int i=0;i<N;i++)
    cin>>A[i];

cout<<"inputed array is :\n";
for(int i=0;i<N;i++)
    cout<<A[i]<<" ";
inversions=mergesortandnonsplit(A,N);
cout<<"no of inversions are:"<<inversions<<endl;

cout<<"sorted array is""\n";
for(int i=0;i<N;i++)
    cout<<A[i]<<" ";

}
