#include <iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int N=10;

//[l,r]closed 
int partition2(int *a, int l, int r,int medofmed ) {
  int i,j,k;
  for( i=l;i<r+1;i++)
    if(a[i]==medofmed)break;
  swap(a[l],a[i]);
  i=l;j=i+1;k=r;
  while(j<=k)
  {
    if(a[i]==a[j])j++;
    else if(a[i]>a[j]){
      swap(a[i],a[j]);
      i++;
      j++;
    }
    else{
      swap(a[j],a[k]);
      k--;
    } 
  }
return i;
}
int findMedian(int arr[], int n)
{
    int *temp=new int[n];
    for(int i=0;i<n;i++)temp[i]=arr[i];
    sort(temp, temp+n);
  int ans=temp[n/2];
  free(temp);
    return ans;
}


int dselect(int *a, int s, int n) {

    if(n<=1)return a[0];
 int i;
 int  *median=new int [(int)ceil(n/5)];
        for (i=0; i<n/5; i++)
            median[i] = findMedian(a+i*5, 5);
        if (i*5 < n)         {
            median[i] = findMedian(a+i*5, n%5);
            i++;
        }

        int medofmed = dselect(median, i/2, i);


  int m = partition2(a, 0, n-1,medofmed);
 free(median);
 
if(s==m+1)return a[m];
else if(s<m+1)
  return dselect(a, s, m );
else if(s>m+1)
    return dselect(a+m+1,s-(m+1) ,n-(m+1) );
}

int main() {
  int n;

  int a[N];
  for (int  i = 0; i <N; ++i) {
    cin >> a[i];
  }
  cout<<"enter ith smallest";
  cin>>n;
 cout<<dselect(a, n, N);

}
