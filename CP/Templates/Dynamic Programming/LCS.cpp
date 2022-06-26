#include <bits/stdc++.h>
using namespace std;

string lcs(string X, string Y, int m, int n) { 
   int L[m+1][n+1]; 
   for (int i=0; i<=m; i++) { 
     for (int j=0; j<=n; j++) { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
       else if (X[i-1] == Y[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 
   //Size of LCS = L[m][n]

   int index = L[m][n]; 
   string lcs(index, 'a');
   int i = m, j = n; 
   while (i > 0 && j > 0) { 
      if (X[i-1] == Y[j-1]) { 
          lcs[index-1] = X[i-1]; 
          i--; j--; index--;  
      } 
  
      else if (L[i-1][j] > L[i][j-1]) 
         i--; 
      else
         j--; 
   } 

   return lcs;
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << lcs("abaab", "baabb", 5, 5);

    return 0;
}