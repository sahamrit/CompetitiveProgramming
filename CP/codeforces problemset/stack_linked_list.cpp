#include<bits/stdc++.h>
using namespace std;
struct node{
	int ele;
	node *next;
};
node *init()
{
	node *top;
	top=NULL;
	return top;
}

bool isempty(node *top)
{
	if(top==NULL)return true;
	return false;
}

int top(node *top)
{
	if(isempty(top)){
		cout<<"Empty Stack"<<endl;
		return INT_MIN;
	}
	return top->ele;
}

node *push(node *top,int val)
{
	node *s=new  node;
	s->ele=val;
	s->next=top;
	top=s;
	return top;
}

node *pop(node *top)
{
	if(isempty(top)){
		cout<<"Stack empty"<<endl;
		return top;
	}
	node *temp=top;
	top=top->next;
	free(temp);
	return top;
}

void print(node *top)
{
	node *temp=top;
	while(temp!=NULL)
	{
		cout<<temp->ele<<" ";
		temp=temp->next;
	}
}
int main()
{
	node *top;
	top=init();
	top=pop(top);	
	cout<<"1st print"<<endl;
	print(top);
	top=push(top,5);
	top=push(top,5);
	top=push(top,5);
	top=push(top,5);
	cout<<"2nd print"<<endl;
	print(top);
	top=pop(top);
	top=pop(top);
	cout<<"3rd print"<<endl;
	print(top);	
	top=push(top,1);
	cout<<"4th print"<<endl;
	print(top);		


				
}