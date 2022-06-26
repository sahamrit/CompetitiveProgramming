#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int main()
{
	int n;cin>>n;
	vector<string> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	int mini=a[0].size();
	for(int i=0;i<n;i++)mini=min(mini,(int)a[i].size());
	vector<char> res;	
	for(int j=0;j<mini;j++){
		bool check=true;
		for(int i=1;i<n;i++){
			if(a[i][j]!=a[0][j]){check=false;break;}
		}
		if(!check)break;
		res.push_back(a[0][j]);
	}
	for(int i=0;i<res.size();i++)
		cout<<res[i];	
}
vector<char> lps(vector<string>&a){
	int n=a.size();
	int mini=a[0].size();
	for(int i=0;i<n;i++)mini=min(mini,(int)a[i].size());
	vector<char> res;	
	for(int j=0;j<mini;j++){
		bool check=true;
		for(int i=1;i<n;i++){
			if(a[i][j]!=a[0][j]){check=false;break;}
		}
		if(!check)break;
		res.push_back(a[0][j]);
	}
	return res;
}