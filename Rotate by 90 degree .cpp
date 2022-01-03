Given a square matrix[][] of size N x N. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space.

Example 1:

Input:
N = 3
matrix[][] = [[1 2 3],
              [4 5 6],
              [7 8 9]]
Output:
3 6 9 
2 5 8 
1 4 7

// code

void transpose(vector<vector<int>> & mat){
    int n = mat.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
}
void rotate(vector<vector<int> >& matrix)
{
    int n = matrix.size();
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
    transpose(matrix);
    // Your code goes here
}
