#include<bits/stdc++.h>
using namespace std;
int countones( long long int n)
{ int ctr=0;
    while(n)
    {ctr+=(n&1);
    n>>=1;

    }
    return ctr;
}
  long long int power (long long int n)
{  long long int temp=2;
    if(n==0)
        return 1;
    for(int i=0;i<n-1;i++)
    {
        temp*=2;
    }
    return temp;
}
int main()
{
    vector<long long int> v;
    int n;
    cin>>n;
    bool check=true;

    int ctr1=0,ctr2=0;
     long long int no,temp1,temp3,temp2,temp4;

    for( int i=0;i<n;i++)
    {
        cin>>no;
        v.push_back(no);
    }
    for( int i=0;i<n;i++)
    {ctr1=0,ctr2=0;check=true;
    temp3=0,temp4=0;

        ctr1=countones(v[i]);

        ctr2=ctr1;
        temp1=v[i];
        temp2=v[i];
        int j=0,k=0;
        if(ctr1!=1&&ctr1!=2&&v[i]!=1)
        {


           while(temp1)
        {
            if(temp1&(1<<j))
            {
                temp3+=power(j);
                temp1+=power(j);
                ctr1=countones(temp1);


                if(ctr1==1)
                   {
                       temp3++;
                    break;}

            }

            if(ctr1==2)
             break;
             j++;


        }


        while(1)
        {
            if(temp2<1)
            {
                check=false;
                break;
            }
            if(temp2&(1<<k))
            {
                temp4+=power(k);
                temp2^=(1<<k);
                ctr2=countones(temp2);

            }


            if(ctr2==2)
             break;
             k++;


        }
           if(check)
             cout<<min(temp3,temp4)<<endl;
           else
            cout<<temp3<<endl;
       }else if(v[i]==1)
       {
           cout<<2<<endl;
       }
       else if(ctr1==1)
       {

                cout<<1<<endl;

       }else if(ctr1==2)
       {
           cout<<0<<endl;
       }

    }


}
