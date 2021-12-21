Given 3 strings A, B and C, the task is to find the longest common sub-sequence in all three given sequences.

Example 1:

Input:
A = "geeks", B = "geeksfor", 
C = "geeksforgeeks"
Output: 5
Explanation: "geeks"is the longest common
subsequence with length 5.
â€‹Example 2:

Input: 
A = "abcd", B = "efgh", C = "ijkl"
Output: 0
Explanation: There's no common subsequence
in all the strings.
  
  // code
  
  int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    int arr[n1+1][n2+1][n3+1];
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            for(int k=0;k<=n3;k++){
                if(i==0 || j==0 || k ==0) arr[i][j][k] = 0;
                else if(A[i-1] == B[j-1]&&A[i-1] == C[k-1]) arr[i][j][k]=1+arr[i-1][j-1][k-1];
                else arr[i][j][k] = max(max(arr[i-1][j][k],arr[i][j-1][k]),arr[i][j][k-1]);
                
            }
        }
    }
    return arr[n1][n2][n3];
    // your code here
}
