Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply 
of each of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then return -1.


Example 1:

Input: V = 30, M = 3, coins[] = {25, 10, 5}
Output: 2
Explanation: Use one 25 cent coin
and one 5 cent coin
Example 2:
Input: V = 11, M = 4,coins[] = {9, 6, 5, 1} 
Output: 2 
Explanation: Use one 6 cent coin
and one 5 cent coin

// code

class Solution{

	public:
	/*int  dp[101][10001];
	int help(int idx, int coins[],int M, int V){
	    if(idx == M || V < 0) return INT_MAX/2;
	    if(V == 0) return 0;
	    if(dp[idx][V] != -1) return dp[idx][V];
	    int res1 = help(idx+1,coins,M,V);
	    int res2 = INT_MAX/2;
	    if(V-coins[idx] >= 0) res2 = 1+help(idx,coins,M,V-coins[idx]);
	    return dp[M][V] = min(res1,res2);
	}*/
	int minCoins(int coins[], int M, int V) 
	{
	    //memset(dp,-1,sizeof(dp));
	    //int ans = help(0,coins,M,V);
	    //if(ans >= INT_MAX/2) return -1;
	    //return ans;
	    // Your code goes here
	    int dp[M + 1][V + 1]; 
	    for (int i = 0; i<=M; i++) dp[i][0]=0; 
	    for (int j = 0; j<=V; j++) dp[0][j] =INT_MAX - 1;
	    for (int i = 1; i<=M; i++){
	        for(int j = 1; j<=V; j++){
	            if (coins[i-1]> j) dp[i][j]=dp[i-1][j];
	            else dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);
	            
	        }
	    }
	    if (dp[M][V] == INT_MAX - 1) return -1;
	    return dp[M][V];
	    
	}
	  
};
