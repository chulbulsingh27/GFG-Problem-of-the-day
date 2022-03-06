For a given 2D Matrix before, the corresponding cell (x, y) of the after matrix is calculated as follows: 

res = 0;
for(i = 0; i <= x; i++){
    for( j = 0; j <= y; j++){              
        res += before(i,j);
    }
}
after(x,y) = res;
Given an N*M 2D-Matrix after, your task is to find the corresponding before matrix for the given matrix.

 

Example 1:

Input:
N = 2, M = 3
after[][] = {{1, 3, 6},
            {3, 7, 11}}
Output:
1 2 3
2 2 1
Explanation:
The before matrix for the given after matrix
matrix is {{1, 2, 3}, {2, 2, 1}}.
  
  // code
  
  class Solution{
    public:
    vector<vector<int>> computeBeforeMatrix(int N, int M, vector<vector<int>> after){
        for(int i=N-1;i>=0;i--){
            for(int j=M-1;j>=0;j--){
                if(i) after[i][j]=after[i][j]-after[i-1][j];
                if(j) after[i][j]=after[i][j]-after[i][j-1];
                if(i && j) after[i][j]=after[i][j]+after[i-1][j-1];
            }
        }
        return after;
    }
};
