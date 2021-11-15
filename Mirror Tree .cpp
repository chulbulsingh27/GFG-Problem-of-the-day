Given a Binary Tree, convert it into its mirror.
  Example 1:

Input:
      1
    /  \
   2    3
Output: 2 1 3
Explanation: The tree is
   1    (mirror)  1
 /  \    =>      /  \
3    2          2    3
The inorder of mirror is 2 1 3
  
  // code
  class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node == NULL) return;
        mirror(node->left);
        mirror(node->right);
        // swap the nodes
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};

