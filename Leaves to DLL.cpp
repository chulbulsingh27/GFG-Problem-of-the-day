Given a Binary Tree of size N, extract all its leaf nodes to form a Doubly Link List starting from the left most leaf. Modify the original tree to make the DLL
thus removing the leaf nodes from the tree. Consider the left and right pointers of the tree to be the previous and next pointer of the DLL respectively.
Example 1:
Input :
        1
      /   \
     2     3
    / \   / \
   4   5 6   7    

Output: 
Modified Tree :
        1
      /   \
     2     3

Doubly Link List :
4 <-> 5 <-> 6 <-> 7

Explanation:
The leaf nodes are modified to form the DLL 
in-place. Thus their links are removed from 
the tree.
  // code
  
  Node* fnc(Node *root ,Node *&ans,Node* &curr)
{   
    if(root==NULL)return NULL;
    //leaf node
    if(root->left==NULL && root->right==NULL)
    {
        if(ans==NULL) //first time leaf node
        {
            ans = new Node(root->data);
            curr = ans;
        }
        else
        {
            curr->right = new Node(root->data);
            curr->right->left=curr;
            curr = curr->right;
        }
        return NULL;
    }
    root->left =  fnc(root->left,ans,curr);
    root->right =  fnc(root->right,ans,curr);
    
}
Node * convertToDLL(Node *root){
    Node* ans = NULL;
    Node* curr = NULL;
    fnc(root,ans,curr);
    return ans;
    
    // add code here.
}
