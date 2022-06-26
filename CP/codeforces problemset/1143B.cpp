#include<bits/stdc++.h>
using namespace std;
int tonumber(string s)
{	
	int res=0;
	for(int i=0;i<s.size();i++)
	{
		res=res*10+s[i]-'0';
	}
	return res;
}
long long int product_(int n)
{
	long long product=1;
	while(n!=0)
	{
		product=product*(n%10);
		n/=10;
	}
	return product;
} 
int main()
{
	int n;
	cin>>n;
	string s=to_string(n),b;
	long long result=INT_MIN,product,no;
	if(s.size()==1){
		cout<<n<<endl;
		return 0;
	}
	result=product_(n);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')continue;
		b=s;
		b[i]=(b[i]-'1')+'0';
		for(int j=i+1;j<b.size();j++)
			b[j]='9';
		no=tonumber(b);
		product=product_(no);
		if(result<product)
			result=product;
	}
	cout<<result<<endl;
}