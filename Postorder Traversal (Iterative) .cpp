Given a binary tree. Find the postorder traversal of the tree without using recursion.

Example 1

Input:
           1
         /   \
        2     3
      /  \
     4    5

Output: 4 5 2 3 1
Explanation:
Postorder traversal (Left->Right->Root) of 
the tree is 4 5 2 3 1.
  
  // code
  
  class Solution{
    public:
    vector<int> postOrder(Node* root) {
        vector<int> vec;
        if(root == NULL) return vec;
        stack<Node*> st1,st2;
        st1.push(root);
        while(!st1.empty()){
            Node* temp = st1.top();
            st2.push(temp);
            st1.pop();
            if(temp->left) st1.push(temp->left);
            if(temp->right) st1.push(temp->right);
        }
        while(!st2.empty()){
            vec.push_back(st2.top()->data);
            st2.pop();
        }
        return vec;
    }
};
