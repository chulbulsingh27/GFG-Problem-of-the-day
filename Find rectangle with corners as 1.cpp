Given a NxM binary matrix consisting of 0s and 1s. Find if there exists a rectangle/ square within the matrix whose all four corners are 1. 

Example 1:

Input:
N = 4, M = 5
matrix[][] = 
{
{1 0 0 1 0},
{0 0 1 0 1},
{0 0 0 1 0}, 
{1 0 1 0 1}
} 

Output: Yes
Explanation:
Valid corners are at index (1,2), (1,4), (3,2), (3,4) 
  
  // code
  
  class Solution{
    public:
    bool ValidCorner(const vector<vector<int> >& matrix)
    {
        // brute force
        /*int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 1){
                    for(int i2=i+1;i2<m;i2++){
                        for(int j2=j+1;j2<n;j2++){
                            if(matrix[i][j2] == 1 && matrix[i2][j] && matrix[i2][j2] == 1){
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;*/
        unordered_map<int,unordered_set<int>> mp;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int j2 = j+1;j2<n;j2++){
                    if(matrix[i][j] == 1 && matrix[i][j2]==1){
                        if(mp.find(j) != mp.end() && mp[j].find(j2) != mp[j].end()){
                            return true;
                        }
                        /*if (mp.find(j2) != mp.end() && mp[j2].find(j) != mp[j2].end()){
                           return true;
                        }*/
                        mp[j].insert(j2);
                        //mp[j2].insert(j);
                    }
                }
            }
        }
        return false;
        
    }
};
