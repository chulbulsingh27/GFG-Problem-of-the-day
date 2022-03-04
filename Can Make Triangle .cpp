Given an array A[] of N elements, You'd like to know how many triangles can be formed with side lengths equal to adjacent elements from A[].

Construct an array of integers of length N - 2 where ith element is equal to 1 if it is possible to form a triangle with side lengths A[i], A[i+1], and A[i+2].
otherwise 0.

Note: A triangle can be formed with side lengths a, b and c if a+b>c and a+c>b and b+c>a.

Example 1:

Input:
N = 4
A[] = {1, 2, 2, 4}
Output:
1 0
Explanation:
output[0] = 1 because we can form a 
triangle with side lengths 1,2 and 2.
output[1] = 0 because 2+2<4 so, we cannot 
form a triangle with side lengths 2,2 and 4.
  
  // code 
  
  class Solution{
    public:
    vector<int> canMakeTriangle(vector<int> A, int n){
        // code here
        vector<int> vec;
        for(int i=0;i<n-2;i++){
            if(A[i]+A[i+1]>A[i+2]&&A[i]+A[i+2]>A[i+1]&&A[i+1]+A[i+2]>A[i]) vec.push_back(1);
            else vec.push_back(0);
        }
        return vec;
    }
}; 
