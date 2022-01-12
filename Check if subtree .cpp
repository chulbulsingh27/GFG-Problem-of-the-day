Given two binary trees with head reference as T and S having at most N nodes. The task is to check if S is present as subtree in T.
A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.

Example 1:

Input:
T:      1          S:   3
      /   \            /
     2     3          4
   /  \    /
  N    N  4
Output: 1 
Explanation: S is present in T

// code

class Solution
{
    public:
    bool issame(Node* t, Node* s){
        if(t == NULL && s== NULL) return true;
        if(t == NULL || s == NULL) return false;
        if(t->data != s->data) return false;
        return issame(t->left,s->left) && issame(t->right,s->right);
    }
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* t, Node* s) 
    {
        if(t==NULL && s==NULL)  return true;    
        if(t!=NULL){
            if(issame(t,s)|| isSubTree(t->left,s) || isSubTree(t->right,s)) return true;
        }
        return false;
    }
};
