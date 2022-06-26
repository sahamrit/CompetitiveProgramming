#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string& pat, vector < int > &lps) { 
    int i = 1, len = 0, M = pat.size(); 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else 
            if (len != 0)
                len = lps[len - 1]; 
            else{ 
                lps[i] = 0; 
                i++; 
            } 
    } 
} 

int KMPSearch(string& pat, string& txt) { 
    int N = txt.size();
    int M = pat.size();  
  
    vector < int > lps(M); 
    computeLPSArray(pat, lps); 

    int cnt = 0;
  
    int i = 0;
    int j = 0; 
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        }
        else
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i++;
        if (j == M) { 
            cnt++;
            j = lps[j - 1]; 
        } 
    } 

    return cnt;
} 

int main()
{
	ios_base::sync_with_stdio(false);
 	cin.tie(NULL);
	
	string pat, txt;
    cin >> txt >> pat;
    cout << KMPSearch(txt, pat) << endl;	
	
	return 0;
}