#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip>
#include<vector>
using namespace std;

void greedy(long double **EF,int **PP,int n)
{
	int i=0,j=0;
	long double score=1,horscore,tempscore,tempmax;
	int idx;
	while((i!=n-1)||(j!=n-1))
	{
		if(i==n-1)
		{
			while(j!=n-1)
			{
			cout<<"at "<<"("<<i<<";"<<j<<") score:"<<setprecision(9)<<score<<endl;			
				if(PP[i][j])
				{
					score=score*1.25;
				}
				j++;
			}
		}
		else if(j==n-1)
		{
			while(i!=n-1)
			{
			cout<<"at "<<"("<<i<<";"<<j<<") score:"<<setprecision(9)<<score<<endl;			
				score=score*EF[i][j];
				i++;				
			}
		}
		else
		{	
			cout<<"at "<<"("<<i<<";"<<j<<") score:"<<setprecision(9)<<score<<endl;			
			tempscore=score*EF[i][j];
			tempmax=tempscore;
			idx=j;
			horscore=score;
			for(int k=j+1;k<n;k++)
			{
				if(PP[i][k-1])
					horscore=horscore*1.25;
				tempscore=horscore*EF[i][k];
				if(tempmax<tempscore)
				{
					tempmax=tempscore;
					idx=k;
				}

			}

			j=idx;
			score=tempmax;
			i++;
		}


	}
	cout<<"at "<<"("<<n-1<<";"<<n-1<<") score:"<<setprecision(9)<<score<<endl;	
	cout<<"exit score"<<setprecision(9)<<score<<endl;
}
void DP(long double**EF,int **PP,int n )
{
	long double **T,horscore,verscore;
	T=new long double*[n];
	for(int i=0;i<n;i++)
		T[i]=new long double[n];

	long double	score=1;
	T[0][0]=1;
	for(int j=1;j<n;j++)
	{
		if(PP[0][j-1])score=score*1.25;
		T[0][j]=score;
	}
	score=1;

	for(int i=1;i<n;i++)
	{
		score=score*EF[i-1][0];
		T[i][0]=score;
	}


	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(PP[i][j-1])
				horscore=T[i][j-1]*1.25;
			else
				horscore=T[i][j-1];
			verscore=T[i-1][j]*EF[i-1][j];
			T[i][j]=max(horscore,verscore);
		}
	}
	cout<<"exit score"<<setprecision(9)<<T[n-1][n-1]<<endl;


}
void DPsol(long double **EF,int **PP,int n)
{
	long double **T,horscore,verscore;
	char **sol;
	T=new long double*[n];
	sol=new char*[n];
	for(int i=0;i<n;i++)
		{	T[i]=new long double[n];
			sol[i]=new char[n];
		}	

	long double	score=1;
	T[0][0]=1;
	sol[0][0]='s';//s=stop;
	for(int j=1;j<n;j++)
	{
		if(PP[0][j-1])score=score*1.25;
		T[0][j]=score;
		sol[0][j]='l';//left
	}
	score=1;

	for(int i=1;i<n;i++)
	{
		score=score*EF[i-1][0];
		T[i][0]=score;
		sol[i][0]='u';//up;
	}


	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(PP[i][j-1])
				horscore=T[i][j-1]*1.25;
			else
				horscore=T[i][j-1];
			verscore=T[i-1][j]*EF[i-1][j];
			T[i][j]=max(horscore,verscore);
			sol[i][j]=horscore>verscore?'l':'u';
		}
	}
	int i=n-1,j=n-1;
	vector<pair<int,int>> recon;
	while((i!=0)||(j!=0))
	{
		recon.push_back(make_pair(i,j));
		if(sol[i][j]=='l')j--;
		else i--;

	}	
	cout<<"at "<<"("<<0<<";"<<0<<") score:"<<setprecision(9)<<1<<endl;
	for(int i=recon.size()-1;i>=0;i--)
	{
	cout<<"at "<<"("<<recon[i].first<<";"<<recon[i].second<<") score:"<<setprecision(9)<<T[recon[i].first][recon[i].second]<<endl;		
	}		


}
int main()
{
	int n;
	cin>>n;
	int **PP;
	long double energy=1,**EF;
	EF=new long double*[n-1];
	for(int i=0;i<n-1;i++)
		EF[i]=new long double[n];
	PP=new int*[n];
	for(int i=0;i<n;i++)
		PP[i]=new int[n-1];
	cout<<"Echaustion factors"<<endl;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>EF[i][j];
			cout<<EF[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"magic powers"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			cin>>PP[i][j];
			cout<<PP[i][j]<<" ";
		}
		cout<<endl;
	}	
	cout<<"GREEDY SOLN"<<endl;
	greedy(EF,PP,n);
	cout<<"DP SOLN"<<endl;
	DP(EF,PP,n);
	cout<<"DP soln retrace"<<endl;
	DPsol(EF,PP,n);

}