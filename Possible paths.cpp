Given a directed graph and two vertices ‘u’ and ‘v’ in it. Find the number of possible walks from ‘u’ to ‘v’ with exactly k edges on the walk modulo 109+7.
 

Example 1:

Input 1: graph = {{0,1,1,1},{0,0,0,1}, 
{0,0,0,1}, {0,0,0,0}}, u = 0, v = 3, k = 2
Output: 2
Explanation: Let source ‘u’ be vertex 0, 
destination ‘v’ be 3 and k be 2. The output 
should be 2 as there are two walk from 0 to 
3 with exactly 2 edges. The walks are {0, 2, 3}
and {0, 1, 3}.

  //code
  class Solution {
  public:
    long long res =0, mod = 1e9+7;
    int dp[51][51];
    int help(vector<vector<int>>&graph, int u, int &v, int k){
        if(k<0) return 0;
        if(k == 0 && u == v) return 1;
        if(dp[u][k] != -1) return dp[u][k];
        int res =0;
        for(int i=0;i<graph[u].size();i++){
            if(graph[u][i] == 0) continue;
            res = (res+ help(graph,i,v,k-1))%mod;
        }
        return dp[u][k] = res;
    }
	int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k){
	    memset(dp,-1,sizeof(dp));
	    return help(graph,u,v,k);
	}
};
