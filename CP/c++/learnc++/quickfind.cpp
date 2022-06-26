#include<iostream>
#include<vector>


using namespace std;

class quickfind{

private: vector <int> v;
public: quickfind(int N)
{
    for(int i=0;i<N;i++)
        v.push_back(i);
};
bool connected(int p,int q)
 {return v[p]==v[q];}
void unionf(int p,int q)
{
    int pid=v[p];
    int qid=v[q];
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==pid) v[i]=qid;
    }
}


};
int main()
{

int n;int p,q;char choice;
cout<<"enter the no of elements\n";
cin>>n;
quickfind obj(n);
cout<<"\nconnect the elements\n";
do {
    cout<<"enter 2 elements to connect\n";
    cin>>p>>q;
    obj.unionf(p,q);
    cout<<"\ndo you want to connect more:(y/Y) to connect\n";
    cin>>choice;

    }while(choice=='y'||choice=='Y');
cout<<"\ncheck connected elements";
do{
cout<<"enter 2 elements to check\n";
    cin>>p>>q;
   if( obj.connected(p,q))
    cout<<"\nthey are connected\n";
   else cout<<"they are not connected\n";
    cout<<"do you want to check more:(y/Y) to connect\n";
    cin>>choice;

    }while(choice=='y'||choice=='Y');


}
