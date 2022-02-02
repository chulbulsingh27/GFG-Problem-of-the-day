Given a weighted, undirected and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
Note: The Graph doesn't contain any negative weight cycle.
  
  // code
  
  class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> vec(V,INT_MAX);
        priority_queue<pair<int,int>> pq;
        vec[S] = 0;
        pq.push({0,S});
        while(!pq.empty()){
            int dist = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            for(auto &it : adj[prev]){
                int next = it[0];
                int newdist = it[1];
                if(vec[next] > vec[prev] + newdist){
                    vec[next] = vec[prev] + newdist;
                    pq.push({vec[next],next});
                    
                }
            }
        }
        return vec;
        // Code here
    }
};
