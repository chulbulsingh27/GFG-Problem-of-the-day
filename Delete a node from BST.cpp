Given a Binary Search Tree and a node value X. Delete the node with the given value X from the BST. If no node with value x exists, then do not make any change. 

Example 1:

Input:
      2
    /   \
   1     3
X = 12
Output: 1 2 3
Explanation: In the given input there
is no node with value 12 , so the tree
will remain same.
Example 2:

Input:
            1
             \
              2
                \
                 8 
               /    \
              5      11
            /  \    /  \
           4    7  9   12
X = 9
Output: 1 2 4 5 7 8 11 12
Explanation: In the given input tree after
deleting 9 will be
             1
              \
               2
                 \
                  8
                 /   \
                5     11
               /  \     \
              4    7     12
// code
Node* help(Node* root){
    Node* temp = root;
    while(temp != NULL && temp->left != NULL) root = root->left;
    return temp;
}
Node *deleteNode(Node *root, int x) {
    if(root == NULL) return NULL;
    if(x > root->data) deleteNode(root->right, x);
    else if(x < root->data) deleteNode(root->left, x);
    else{
        if(root->left == NULL && root->right == NULL) return NULL;
        if(root->left == NULL){
            Node*temp = root->right;
            delete temp;
            return root;
        }
        if(root->right == NULL){
            Node*temp = root->left;
            delete temp;
            return root;
        }
        // deleting root if both left and right exists.
        Node* temp = help(root->right);//move left to right 
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);
    }
    return root;
    // your code goes here
}
