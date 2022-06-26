//worst case O(sqrt(n))when a prime factor is large
void divide(int x,int u){
	for(int i=2;i*i<=x;i++)
		if(x%i==0){
			p[u].push_back(i);
			dp[u].push_back(1);		
			while(x%i==0)x/=i; 
		}
	if(x>1){
		p[u].push_back(x);
		dp[u].push_back(1);
	}
}