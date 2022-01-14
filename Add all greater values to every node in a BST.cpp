Given a BST, modify it so that all greater values in the given BST are added to every node.

Example 1:

Input:
           50
         /    \
        30    70
      /   \   / \  
     20   40 60  80
Output: 350 330 300 260 210 150 80
Explanation:The tree should be modified to
following:
             260
          /       \
        330      150
       /   \   /     \
    350   300 210    80
               
               
               
 // code
               
               
 void help(Node* root,int &sum){
    if(root == NULL) return;
    help(root->right,sum);
    root->data += sum;
    sum = root->data;
    help(root->left,sum);
}
Node* modify(Node *root)
{
    int sum =0;
    help(root,sum);
    return root;
    // Your code here
}
