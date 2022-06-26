#include<bits/stdc++.h>
using namespace std;
struct node
{
   pair<unsigned int,int> point;
   vector<int >adjlist;
   int index;

};
unordered_set<unsigned int> s;
vector<node*> perm;//global
unsigned int ctr=0;//global
int power(int a,int b)
{int temp=a;
if(b==0)
    return 1;
    for(int i=0;i<b-1;i++)
    {
        temp*=a;
    }
    return temp;
}
bool isprime(unsigned int n)
{
   for(int i=2;i<=(unsigned int)sqrt(n);i++)
   {
       if(n%i==0)
        return false;
   }
   return true;
}
int ithdigit(int n,int alpha)
{ int no_digits=0;
int temp=n;
while(temp!=0)
{
    temp=temp/10;
    no_digits++;
}

    return (n/(power(10,no_digits-alpha-1)))%10;
}
void addedge(int m,int n)
{
    perm[m]->adjlist.push_back(n);
}
void permutation( unsigned int &p,queue<unsigned int> &q)
{
unsigned ctrtemp=ctr-1;

 node * temp2=new node;
for(int i=0;i<9;i++)
{temp2->point.first=0;

    if(i!=2&&i!=5&&i!=8)
    {   if(i+1<9)
        {if(isprime(ithdigit(p,i)+ithdigit(p,i+1)))
        {
            for(int k=0;k<9;k++)
            {    if((k!=i&&k!=i+1))
            {
                temp2->point.first+=(ithdigit(p,k)*(power(10,8-k)));

            }
            else
            {
             temp2->point.first+=ithdigit(p,i)*((int)power(10,8-i-1))+ithdigit(p,i+1)*((int)power(10,8-i));

              k++;


            }
            }


  if(s.find(temp2->point.first)==s.end())
                  { cout<<temp2->point.first<<endl;
                      q.push(temp2->point.first);
                      s.insert(temp2->point.first);
     temp2->point.second=0;
     temp2->index=ctr;

     perm.push_back(temp2);
       addedge(ctrtemp,ctr);
     ctr++;

                  }






        }}

        if(i+3<9)
        {if(isprime(ithdigit(p,i)+ithdigit(p,i+3)))
        {
            for(int k=0;k<9;k++)
            {    if((k!=i&&k!=i+3))
            {
                temp2->point.first+=ithdigit(p,k)*((int)power(10,8-k));
            }
            else
            {if(k==i)
             temp2->point.first+=ithdigit(p,i)*((int)power(10,8-i-3));
             if(k==i+3)
             temp2->point.first+= ithdigit(p,i+3)*((int)power(10,8-i));

            }
            }

if(s.find(temp2->point.first)==s.end())
                  {cout<<temp2->point.first<<endl;
                      q.push(temp2->point.first);
                      s.insert(temp2->point.first);
     temp2->point.second=0;
     temp2->index=ctr;

     perm.push_back(temp2);
       addedge(ctrtemp,ctr);
     ctr++;

                  }

        }}
    }
    else if(i+3<9)
    {
      if(isprime(ithdigit(p,i)+ithdigit(p,i+3)))
        {
            for(int k=0;k<9;k++)
            {    if(k!=i&&k!=i+3)
            {
                temp2->point.first+=ithdigit(p,k)*((int)power(10,8-k));
            }
            else
            {if(k==i)
             temp2->point.first+=ithdigit(p,i)*((int)power(10,8-i-3));
             if(k==i+3)
             temp2->point.first+= ithdigit(p,i+3)*((int)power(10,8-i));

            }
            }



if(s.find(temp2->point.first)==s.end())
                  {cout<<temp2->point.first<<endl;
                      q.push(temp2->point.first);
                      s.insert(temp2->point.first);
     temp2->point.second=0;
     temp2->index=ctr;

     perm.push_back(temp2);
       addedge(ctrtemp,ctr);
     ctr++;

                  }

        }
    }

}

}
void puzzle(vector<unsigned int> v,int no)
{
    queue< unsigned int >q;
   unsigned int  p,temp1;
     p=123456789;

     q.push(p);

 s.insert(p);
   node * temp=new node;
     temp->point.first=p;
     temp->point.second=0;
     temp->index=ctr;

     perm.push_back(temp);
//cout<<perm[0]->point.first;
     ctr++;

     while(!q.empty())
     {
         temp1=q.front();

         q.pop();

         permutation(temp1,q);
     }
     /*for(int i=0;i<perm.size();i++)
     {
         cout<<perm[i]->point.first<<endl;
     }*/

     /*for(int i=0;i<no;i++)
     {
         if(m.find(v[i])!=m.end())
            cout<<m[v[i]]<<endl;
         else
            cout<<-1<<endl;
     }*/
}
int main()
{vector<unsigned int> v;
    int arr[3][3];
    unsigned int temp;

    int no;
    cin>>no;
    for(int i=0;i<no;i++)
     {


        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                cin>>arr[j][k];

            }
        }
        cout<<endl;
        temp=power(10,8)*arr[0][0]+power(10,7)*arr[0][1]+power(10,6)*arr[0][2]+power(10,5)*arr[1][0]+power(10,4)*arr[1][1]+power(10,3)*arr[1][2]+power(10,2)*arr[2][0]+
        power(10,1)*arr[2][1]+arr[2][2];
        v.push_back(temp);


    }
 puzzle(v,no);

}
