// merge algorithm example C++17
#include<bits/stdc++.h>
using namespace std;

int main () {
  int first[] = {5,10,15,20,25};
  int second[] = {50,40,30,20,10};
  vector<int> v;
  multiset<int>m1(first,first+5),m2(second,second+5),m3;
  sort (first,first+5);
  sort (second,second+5);
  merge (first,first+5,second,second+5,back_inserter(v));
  m3.merge(m1);
  m3.merge(m2); 

  cout << "The resulting vector contains:";
  for (vector<int>::iterator it=v.begin(); it!=v.end(); ++it)
      cout << ' ' << *it;
  cout << '\n';
  for (multiset<int>::iterator it=m3.begin(); it!=m3.end(); ++it)
      cout << ' ' << *it;
  cout << '\n';  

  return 0;
}