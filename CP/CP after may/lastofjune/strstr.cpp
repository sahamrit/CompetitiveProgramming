void computelps(vector<int>lps,int m,string pat){
	int i=0,j=0;
	while(i<m){
		if(pat[i]==pat[j]){
			lps[i++]=++j;
		}
		else{
			while(j && pat[i]!=pat[j]){
				j=pat[j-1];
			}
			if(pat[i]==pat[j]){
				lps[i++]=++j;
			}
			else{
				lps[i++]=0;
			}
		}
	}
}
int Solution::strstr(string txt,string pat){
	int n=txt.size(),m=pat.size();
	vector<int>lps(m);
	if(m==0 || n==0)return -1;
	computelps(lps,m,pat);
	int i=0,j=0;
	while(i<n){
		if(txt[i]==pat[j]){
			i++;j++;
		}
		else{
			while(j && pat[i]!=pat[j]){
				j=lps[j-1];
			}
			if(pat[i]==pat[j]){
				i++;j++;
			}
		}
		if(j==m){
			return i-m;
		}
	}

}