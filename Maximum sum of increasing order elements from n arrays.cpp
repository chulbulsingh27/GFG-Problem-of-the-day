Given n arrays of size m each. Find maximum sum obtained by selecting a number from each array such that the element
selected from the i-th array is more than the element selected from (i-1)-th array. If maximum sum cannot be obtained then return 0.

Example 1:

Input : arr[ ] = {{1,7,4,3}, {4,2,5,1}, {9,5,1,8}}
Output : 18
Explanation:
We can select 4 from the first array,
5 from second array and 9 from the third array.

Example 2:

Input : arr[ ] = {{9,8,7}, {6,5,4}, {3,2,1}} 
Output :  0
  
  // code
  
  int maximumSum( int n,int m, vector<vector<int>> &a) {
    int mn = INT_MAX;
    int sum = 0;
    for(int i=n-1;i>=0;i--){
        int mx = INT_MIN;
        for(int j=0;j<m;j++){
            if(a[i][j] > mx &&  a[i][j] < mn) mx = a[i][j];
        }
        if(mn > mx) sum += mx;
        mn = mx;
    }
    if(sum > 0) return sum;
    return 0;
    // Complete the function
}
