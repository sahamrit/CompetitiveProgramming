#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

const int N=10;

int partition2(int *a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

int randomizedselect(int *a, int s, int n) {
    srand(time(0));
    if(n<=1)return a[0];

  int k = 0 + rand() % (n);
  swap(a[0], a[k]);
  int m = partition2(a, 0, n-1);
if(s-1==m)return a[m];
else if(s-1<m)
  randomizedselect(a, s, m );
else if(s-1>m)  randomizedselect(a+m+1,s-(m+1) ,n-(m+1) );
}

int main() {
  int n,ctr=0;

  int a[N];
  for (int  i = 0; i <N; ++i) {
    cin >> a[i];
  }
  cout<<"enter ith smallest";
  cin>>n;
 cout<<randomizedselect(a, n, N);

}
