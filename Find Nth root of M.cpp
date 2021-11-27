You are given 2 numbers (n , m); the task is to find n√m (nth root of m).
 

Example 1:

Input: n = 2, m = 9
Output: 3
Explanation: 32 = 9
Example 2:

Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not
integer.
  
  //code
  
  class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    long long int low = 1, high = m, mid;
		long long int ans = -1;
		while(low <= high){
			mid = (low + high)/2;
			long long int x = mid;
			for(int i = 1; i < n; i++){
				x *= mid;
				if(x > m )break;
			}
			if(x == m){
				ans = mid;
				break;
			}
			else if(x > m)high = mid - 1;
			else low = mid + 1;
		}
		return int(ans);
	    //int res = round(pow(m,1.0/n));
	    //if(pow(res,n) == m) return res;
	    //return -1;
	}  
};
