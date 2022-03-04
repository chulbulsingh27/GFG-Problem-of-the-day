Given a binary matrix of dimensions M * N. One can perform the given operation in the matrix.
If the value of matrix[i][j] is 0, then traverse in the same direction and check the next value.
If the value of matrix[i][j] is 1, then update matrix[i][j] to 0 and change the current direction from up, right, down, or left to the directions 
right, down, left, and up respectively.
Initially you start from cell(0, 0), moving in right direction.

The task is to find the first cell of the matrix  which leads to outside the matrix from the traversal of the given matrix from the cell (0, 0) by performing the operations.

Example 1:

Input:
matrix[][] = {{0,1},
              {1,0}}

Output: (1,1)

// code
class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        pair<int,int> vec;
        int n = matrix.size();
        int m = matrix[0].size();
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        int pos = 1;
        int i=0,j=0;
        while(i >=0 && i<n  && j>=0 && j<m){
            vec = {i,j};
            if(matrix[i][j] == 1){
                matrix[i][j] = 0;
                pos = (pos+1)%4;
            }
            i += dx[pos];
            j+= dy[pos];
        }
        return vec;
        //code here
    }

};
