#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1003;
const int M = 1003;

ll mat[N][M], aux[N][M];

void preProcess(int n, int m){
	for(int i=0; i<m; i++) 
    	aux[0][i] = mat[0][i]; 
  
   	for(int i=1; i<n; i++) 
      	for(int j=0; j<m; j++) 
         	aux[i][j] = mat[i][j] + aux[i-1][j]; 
  
   	for(int i=0; i<n; i++) 
      	for(int j=1; j<m; j++) 
         	aux[i][j] += aux[i][j-1]; 
}

// [(tli, tlj), (rbi, rbj))
ll sumQuery(int tli, int tlj, int rbi, int rbj){
	ll res = aux[--rbi][--rbj]; 

    if (tli > 0) 
       	res = res - aux[tli-1][rbj]; 

    if (tlj > 0) 
       	res = res - aux[rbi][tlj-1];

    if (tli > 0 && tlj > 0) 
       	res = res + aux[tli-1][tlj-1]; 

    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
 	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> mat[i][j];

	preProcess(n, m);
	int q;
	cin >> q;
	while(q--){
		int tli, tlj, rbi, rbj;
		cin >> tli >> tlj >> rbi >> rbj;
		cout << sumQuery(tli, tlj, rbi, rbj) << endl;
	}
	
	return 0;
}