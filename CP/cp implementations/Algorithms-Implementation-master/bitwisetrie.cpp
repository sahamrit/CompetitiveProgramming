// code for problem 
// http://codeforces.com/contest/271/problem/D
//http://codeforces.com/problemset/problem/282/E

#include <bits/stdc++.h>

using namespace std;

#define ll long long 

struct trie
{
	trie *child[2];

	trie()
	{
		for(int i=0;i<2;++i)
			child[i] = NULL;
	}
};

int n, k;
string s, good;

void insert(trie *root, int i)
{
	for(; i<n;++i)
	{
		int pos = s[i] - '0';
		if(root->child[pos] == NULL)
			root->child[pos] = new trie;
		root = root->child[pos];
	}
}
void merge(trie *mergeto,trie *mergefrom)
{

	if(mergefrom->child[0]==NULL && mergefrom->child[1]==NULL)
		return;

	if(mergefrom->child[0]!=NULL)
		{
			if(mergeto->child[0]==NULL)
			{
				mergeto->child[0]=mergefrom->child[0];
			}
			else
				merge(mergeto->child[0],mergefrom->child[0]);
		}

	if(mergefrom->child[1]!=NULL)
		{
			if(mergeto->child[1]==NULL)
			{
				mergeto->child[1]=mergefrom->child[1];
			}
			else
				merge(mergeto->child[1],mergefrom->child[1]);
		}			
	
}
void display(struct trie* root, char str[], int level) 
{ 
 
    if (root->child[0]==NULL&&root->child[1]==NULL)  
    { 
        str[level] = '\0'; 
        cout << str << endl; 
    } 
  
    int i; 
    for (i = 0; i < 2; i++)  
    { 

        if (root->child[i])  
        { 
            str[level] = i + '0'; 
            display(root->child[i], str, level + 1); 
        } 
    } 
}
int main()
{
	int no;
	//cin>>no;
	n = 21;
	s=bitset<21>(2).to_string();
	cout<<s<<endl;
	trie *t = new trie;
	insert(t,0);

	s=bitset<21>(1).to_string();
	cout<<s<<endl;
	trie *t1 = new trie;
	insert(t1,0);

	s=bitset<21>(111111).to_string();
	cout<<s<<endl;
	trie *t2 = new trie;
	insert(t2,0);

	s=bitset<21>(1111).to_string();
	cout<<s<<endl;
	trie *t3 = new trie;
	insert(t3,0);			

	merge(t,t1);
	merge(t,t2);
	merge(t,t3);		
	char str[20];
	display(t,str,0);


	return 0;
}
