Given a parent array arr[] of a binary tree of N nodes. Element at index i in the array arr[] represents the parent of ith node, i.e, arr[i] = parent(i). Find the height of this binary tree.
Note: There will be a node in the array arr[], where arr[i] = -1, which means this node is the root of binary tree.

Example 1:

Input: N = 7
arr = {-1, 0, 0, 1, 1, 3, 5}
Output: 5
Explanation: Tree formed is:
                    0
                   / \
                  1   2
                 / \
                3   4
               /
              5
             /
            6      Height of the tree= 5
                      
   // code
                      
class Solution{
public:
    int findHeight(int n, int arr[]){
        int res = 1;
        for(int i=0;i<n;i++){
            int curr = arr[i];
            int count = 1;
            while(curr >= 0){
                curr = arr[curr];
                count++;
            }
            res = max(res,count);
        }
        return res;
    }
};
