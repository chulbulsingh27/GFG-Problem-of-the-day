Given a Binary Tree, you need to find the maximum value which you can get by subtracting the value of node B from the value of node A, 
where A and B are two nodes of the binary tree and A is an ancestor of B. 

Example 1:

Input:
    5
 /    \
2      1
Output: 4
Explanation:The maximum difference we can
get is 4, which is bewteen 5 and 1.
  
  // code
  
  int help(Node* root,int &mx){
    if(root == NULL) return INT_MAX;
    if(root->left == NULL && root->right == NULL) return root->data;
    int l = help(root->left , mx);
    int r = help(root->right , mx);
    int mn = min(l,r);
    mx = max(mx,root->data-mn);
    return min(mn,root->data);//for a-b to be max , b should be min
}
int maxDiff(Node* root)
{
    int mx = INT_MIN;
    help(root,mx);
    return mx;
}
