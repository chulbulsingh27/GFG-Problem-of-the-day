Given a Directed Graph. Count the total number of ways or paths that exist between two vertices in the directed graph. These paths doesn’t contain any cycle.
Note: Graph doesn't contain multiple edges, self loop and cycles and the two vertices( source and destination) are denoted in the example.


Example 1:

Input:
0 -> 1
|   /  \
4<---2--3   
 

Output: 4
Explanation: 
There are 4 paths from 0 to 4.
0 -> 4
0 -> 1 -> 4
0 -> 2 -> 4
0 -> 1 -> 3 -> 2 -> 4
  
  
  // code
  
  class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        if(source == destination) return 1;
        int count = 0;
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(auto it : adj[temp]){
                if(it == destination) count++;
                else q.push(it);
            }
        }
        return count;
        
    }
};

  
  
