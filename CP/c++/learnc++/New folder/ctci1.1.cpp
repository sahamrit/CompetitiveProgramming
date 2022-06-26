#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{string str;
unordered_set <char> st;
cin>>str;
for(int i=0;i<str.length();i++)
{
    st.insert(str[i]);
}


if(st.size()==str.size())
  cout<<"is unique";
else
  cout<<"not unique";


}
