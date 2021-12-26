Given a matrix mat of size R*C with 0 and 1’s, find the largest rectangle of all 1’s in the matrix. 
The rectangle can be formed by swapping any pair of columns of given matrix.

Example 1:

Input: 
R = 3, C = 5
mat[][] = {{0, 1, 0, 1, 0},
           {0, 1, 0, 1, 1},
           {1, 1, 0, 1, 0}};
Output: 6
Explanation: The largest rectangle's area
is 6. The rectangle can be formed by
swapping column  2 with 3. The matrix
after swapping will be
     0 0 1 1 0
     0 0 1 1 1
     1 0 1 1 0
Example 2:

Input:
R = 4, C = 5
mat[][] = {{0, 1, 0, 1, 0},
           {0, 1, 1, 1, 1},
           {1, 1, 1, 0, 1},
           {1, 1, 1, 1, 1}};
Output: 9
  
  
  // code
  
class Solution{
public:	
	// Returns area of the largest rectangle of 1's
	int maxArea(vector<bool> mat[], int r, int c) {
	    vector<vector<int>> vec(r,vector<int> (c));
	    for(int i=0;i<c;i++) vec[0][i] = mat[0][i];//first row as it is
	    for(int i=1;i<r;i++){
	        for(int j=0;j<c;j++){
	            if(mat[i][j] == 1) vec[i][j] = 1+vec[i-1][j];
	            else vec[i][j] = mat[i][j];
	        }
	    }
	    //sort the vec row wise
	    for(int i=0;i<r;i++) sort(vec[i].begin(),vec[i].end(),greater<int> ());
	    // finding the largest area
	    int res = 0;
	    for(int i=0;i<r;i++){
	        for(int j =0;j<c;j++){
	            res = max(res,(j+1)*vec[i][j]);
	        }
	    }
	    return res;
	    
	}

};
