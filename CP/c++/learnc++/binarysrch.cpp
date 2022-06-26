#include<iostream>
using namespace std;

int binary(int A[],int beg,int last,int no)
{
    int mid;
    while (beg<=last){
        mid=(beg+last)/2;
        if (A[mid]==no)
           return mid;
        else if(A[mid]<no)
           beg=mid+1;
        else if(A[mid]>no)
           last=mid-1;

    }
    return -1;

}
int main()
{
    int A[10];
    for(int i=0;i<10;i++)
        cin >>A[i];
    cout<<binary(A,0,9,5);
}
