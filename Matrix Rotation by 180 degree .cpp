Given a square matrix of size N X N, turn it by 180 degrees in anticlockwise direction without using extra memory.
 

Example 1:

Input: N = 4, 
matrix = {{1, 2, 3, 4}, 
          {5, 6, 7 ,8}, 
          {9, 10, 11, 12},
          {13, 14, 15, 16}}
Output: {{16, 15, 14, 13}, 
         {12, 11, 10, 9}, 
         {8, 7, 6, 5}, 
         {4, 3, 2, 1}}

// code

class Solution {
public:
    void reverse1(vector<vector<int> >& matrix){
        int n = matrix.size();
        for(int i=0;i<n;i++){
            int l = 0; int h = n-1;
            while(l < h){
                swap(matrix[l][i],matrix[h][i]);
                l++;
                h--;
            }
        }
    }
    void transpose(vector<vector<int> >& matrix){
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j = i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        transpose(matrix);
        reverse1(matrix);
        transpose(matrix);
        reverse1(matrix);
        // Code here
    }
};
