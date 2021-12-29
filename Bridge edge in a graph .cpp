Given a Graph of V vertices and E edges and another edge(c - d), the task is to find if the given edge is a Bridge. i.e., removing the edge disconnects the graph.

Example 1:

Input:

c = 1, d = 2
Output:
1
Explanation:
From the graph, we can clearly see that
blocking the edge 1-2 will result in 
disconnection of the graph. So, it is 
a Bridge and thus the Output 1.
  
  // code
  
  class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(int src,vector<bool> &vis,vector<int> adj[],int c, int d){
        vis[src] = true;
        for(auto i: adj[src]){
            if((src == c && i==d) ||(src == d && i == c)) continue;
            if(!vis[i]) dfs(i,vis,adj,c,d);
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<bool> vis(V,0);
        dfs(c,vis,adj,c,d);
        if(!vis[d]) return 1;
        return 0;
        // Code here
    }
};
