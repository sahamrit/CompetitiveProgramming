#include<iostream>
#include<cstdio>
using namespace std;
void URLify(char str[],int truelength)
{
    int w_space=0;
    for(int i=0;i<truelength;i++)
    {
        if(str[i]==' ')
            w_space++;
    }
    int index=truelength+2*w_space;
    str[index]='\0';
    for(int i=truelength-1;i>=0;i--)
    {
        if(str[i]==' ')
        {
            str[index-1]='0';
            str[index-2]='2';
            str[index-3]='%';;
            index-=3;
        }
        else
        {
            str[index-1]=str[i];
            index--;

        }

    }
}
int main()
{
    char arr[100];
    int t_length;
    cin>>t_length;
    cin.ignore();//have to use this before either using getline or gets
   //cin.getline(arr,t_length+1);
    gets(arr);
    URLify(arr,t_length);
    cout<<arr;
}
