Given an array A[] of N integers and a range(L, R). The task is to find the number of subarrays having sum in the range L to R (inclusive).

Example 1:

Input:
N = 3, L = 3, R = 8
A[] = {1, 4, 6}
Output: 
3
Explanation: 
The subarrays are [1,4], [4] and [6]
Example 2:

Input:
N = 4, L = 4, R = 13
A[] = {2, 3, 5, 8}
Output: 
6
Explanation: 
The subarrays are [2,3], [2,3,5], 
[3,5],[5], [5,8] and [8]


//code

class Solution {
  public:
    long long help(vector<int> A, int N, long res){
        long long  left  = 0, right = 0,sum = 0, ans = 0;
        while(right < N){
            sum += A[right];
            while(left <= right && sum > res){
                sum -= A[left];
                left++;
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
    long long countSubarray(int N,vector<int> A,long long L,long long R) {
        long long rightcount = help(A, N,R);
        long long leftcount = help(A, N,L-1);
        return rightcount - leftcount;
    }
};
