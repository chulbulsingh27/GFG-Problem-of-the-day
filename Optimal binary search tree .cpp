Given a sorted array keys[0.. n-1] of search keys and an array freq[0.. n-1] of frequency counts, where freq[i] is the number of searches to keys[i].
Construct a binary search tree of all keys such that the total cost of all the searches is as small as possible.
Let us first define the cost of a BST. The cost of a BST node is level of that node multiplied by its frequency. Level of root is 1.


Example 1:

Input:
n = 2
keys = {10, 12}
freq = {34, 50}
Output: 118
Explaination:
There can be following two possible BSTs 
        10                       12
          \                     / 
           12                 10
                              
The cost of tree I is 34*1 + 50*2 = 134
The cost of tree II is 50*1 + 34*2 = 118 
  
  // code
  
  class Solution{
    public:
    int dp[101][101][101];
    int help(int keys[], int freq[],int left, int right, int height){
        if(left > right) return 0;
        if(dp[left][right][height] != -1) return dp[left][right][height];
        int res = INT_MAX;
        for(int i = left ; i<= right;i++){
            res = min(res,height*freq[i]+help(keys,freq,left,i-1,height+1)+help(keys,freq,i+1,right,height+1));
        }
        return dp[left][right][height] = res;
    }
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        memset(dp,-1,sizeof(dp));
        return help(keys,freq,0,n-1,1);
    }
};
