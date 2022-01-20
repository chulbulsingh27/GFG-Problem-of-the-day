/*
Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

                                               

Example 1:

Input:
     11
    /  \
   1    2
Output: 11
Explanation: The maximum sum is sum of
node 11.
Example 2:

Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.
*/

// code 


class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    unordered_map<Node*,int> mp;
    int getMaxSum(Node *root) 
    {
        if(root == NULL) return 0;
        if(mp[root]) return mp[root];
        int inc = root->data;
        if(root->left){
            inc += getMaxSum(root->left->left);
            inc += getMaxSum(root->left->right);
        }
        if(root->right){
            inc += getMaxSum(root->right->left);
            inc += getMaxSum(root->right->right);
        }
        int exc = getMaxSum(root->left) + getMaxSum(root->right);
        mp[root] = max(inc,exc);
        return mp[root];
        // Add your code here
    }
};
