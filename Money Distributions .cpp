Find the number of ways in which N coins can be distributed among K pupils such that each pupil receives at least one coin each. Two distributions are said to be different only if they have at least one pupil who got a different number of coins.
 

Example 1:

Input: N = 7, K = 3
Output: 15
Explanation: 
Coin distribution can be any of the following 15 ways. 
{1,1,5}, {1,5,1}, {5,1,1}, {2,1,4}, {1,2,4}, {1,4,2}
{2,4,1}, {4,1,2}, {4,2,1}, {3,1,3}, {1,3,3}, {3,3,1}
{2,2,3}, {2,3,2}, {3,2,2}

//code

class Solution{
	public:
	    const int mod = 1e9 + 7;
        int expo(int a, int b) {
        int ans = 1;
        while (b) {
            if (b & 1)(ans *= a) %= mod;
            (a *= a) %= mod;
            b >>= 1;
        }
        return ans;
    }
    int totalWays(int n, int k) {
        if (n < k)return 0;
        int ans = 1;
        for (int i = n - k + 1; i <= n - 1; i++)(ans *= i) %= mod;
        for (int i = 1; i <= k - 1; i++)(ans *= expo(i, mod - 2)) %= mod;
        return ans;
    }
};
