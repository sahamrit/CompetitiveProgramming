#include<iostream>
#include<string.h>
using namespace std;
int  solution_comp(char *solution)
{
        int j=0,i=0,ctr=0;
    while(j<strlen(solution))
    {
        ctr=0;
        if(solution[j]!=solution[j+1])
        {
            solution[i++]=solution[j++];
            continue;
        }
        while(solution[j]==solution[j+1])
        {
            ctr++;j++;
        }
        solution[i++]=solution[j];
        if(ctr<10)
        {solution[i++]=(char)(ctr+49);}
        else{ctr++;
            i--;
                int temp,ctr1=0;
             temp=ctr;
            while(temp!=0)
            {ctr1++;
              temp=temp/10;
            }
            i=i+ctr1;
            while(ctr!=0)
            {
                solution[i]=(char)(ctr%10+48);
                ctr=ctr/10;
                i--;

            }
            i=i+ctr1+1;
        }
        j++;

    }
    solution[i]='\0';

    return (i);
}
int main()
{
    char solution[100];
    cin>>solution;
   cout<< solution_comp(solution)<<endl;
    cout<<solution;
}
