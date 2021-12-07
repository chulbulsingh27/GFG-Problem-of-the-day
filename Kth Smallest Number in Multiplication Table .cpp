Given three integers M, N and K. Consider a grid of M * N, where mat[i][j] = i * j (1 based index). The task is to return the Kth smallest element in the M * N multiplication table.
 

Example 1:

Input:
M = 3, N = 3
K = 5
Output: 3
Explanation: 

The 5th smallest element is 6. 


Example 2:

Input:
M = 2, N = 3
K = 6
Output: 6 
  // code
  
  class Solution {
public:
    int KthSmallest(int m, int n, int k) {
       int l =0,r=m*n,ans;
       while(l<=r){
           int mid = l+(r-l)/2;
           int count =0;
           for(int i=1;i<=m;i++) count += min(mid/i,n);
           if(count >= k){
               ans = mid;
               r = mid-1;
           }
           else  l = mid+1;
       }
       return ans;
    }
};
