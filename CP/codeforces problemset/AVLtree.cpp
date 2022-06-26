#include<bits/stdc++.h>
using namespace std;
struct node{
	int key,height;
	node *L,*R;

};

node *newnode(int key)
{
	node *p=new node;
	p->key=key;
	p->R=p->L=NULL;
	p->height=1;
	return p;
}

int height(node *N)
{
	if(N==NULL)return 0;

	return N->height;
}
node *rrotate(node *y)
{
	node *x=y->L;
	node *T2=x->R;

	x->R=y;
	y->L=T2;

	x->height=max(height(x->L),height(x->R))+1;
	y->height=max(height(y->L),height(y->R))+1;	

	return x;
}

node *lrotate(node *x)
{
	node *y=x->R;
	node *T2=y->L;

	y->L=x;
	x->R=T2;


	x->height=max(height(x->L),height(x->R))+1;
	y->height=max(height(y->L),height(y->R))+1;	

	return y;

}
int getbalance(node *root)
{
	return height(root->R)-height(root->L);
}

node *insert(node *root,int key)
{	
	if(root==NULL)
		return	newnode(key);

	if(key<root->key)
		root->L=insert(root->L,key);
	else if(key>root->key)
		root->R=insert(root->R,key);
	else return root;

	int balance=getbalance(root);

	if(balance <-1 && key < root->L->key)//LL case
		return rrotate(root);
	if(balance <-1 && key>root->L->key)//LR case
	{
		root->L=lrotate(root->L);
		return rrotate(root);
	}
	if(balance >1 && key>root->R->key)//RR case
		return lrotate(root);

	if(balance >1 && key<root->R->key)//RL case
	{
		root->R=rrotate(root->R);
		return lrotate(root);
	}

	return root;

}
node *minvalnode(node *p)
{
	while(p->L!=NULL)p=p->L;
	return p;

}
node *delete_node(node *root,int key)
{
	if(root==NULL)return root;

	if(key<root->key)
		root->L=delete_node(root->L,key);
	else if(key>root->key)
		root->R=delete_node(root->R,key);
	else if(key==root->key)
	{	
		if(root->L==NULL || root->R==NULL){
			node *temp=root->L?root->L:root->R;
			if(temp==NULL)
			{
				temp=root;
				root=NULL;
			}
			else
			{
				*root=*temp;
			}
			free(temp);
		}
		else{

			node *temp=minvalnode(root->R);
			root->key=temp->key;
			root->R=delete_node(root->R,temp->key);

		}	
	}

	if(root==NULL)return root;

	int balance=getbalance(root);

	if(balance>1 && getbalance(root->R)>=0)//RR case
		return lrotate(root);
	if(balance >1 && getbalance(root->R)<0)//RL case
		{
			root->R=rrotate(root->R);
			return lrotate(root);
		}	
	if(balance <-1 && getbalance(root->L)<=0)//LL case
	 		return rrotate(root->L);		
	 if(balance<-1 &&getbalance(root->L)>0)//LR case
	 {
	 	root->L=lrotate(root->L);
	 		return rrotate(root);
	 }	
	 return root;
}
bool search(node *root,int key){
	if(root==NULL)return false;
	if(key==root->key)return true;

	if(key<root->key)return search(root->L,key);
	if(key>root->key)return search(root->R,key);

}

int main(){
	node *root;
	root=insert(root,4);
	root=insert(root,6);
	root=insert(root,4);
	root=insert(root,6);
	root=insert(root,10);
	root=insert(root,8);	
	if(search(root,8))cout<<"8 found"<<endl;
	root=delete_node(root,8);
	if(!search(root,8))cout<<"8 delete_noded"<<endl;	
	if(search(root,4))cout<<"4 found"<<endl;
	if(!search(root,1))cout<<"1 not found"<<endl;
}