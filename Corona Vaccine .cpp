Geek has developed an effective vaccine for Corona virus and he wants each of the N houses in Geek Land to have access to it. 
Given a binary tree where each node represents a house in Geek Land, find the minimum number of houses that should be supplied with the vaccine kit if
one vaccine kit is sufficient for that house, 
its parent house and it's immediate child nodes.  
Example 1:

Input:
    1
   / \
  2   3 
        \
         4
          \
           5
            \
             6

Output:
2
Explanation:
The vaccine kits should be 
supplied to house numbers 1 and 5. 
  
  
  // code
  
class Solution{
public:
    int help(Node* root, int &vaccine){
        if(root == NULL) return 1;
        int lc = help(root->left,vaccine);
        int rc = help(root->right,vaccine);
        if(lc == -1 || rc == -1){
            vaccine++;
            return 0;
        }
        if(lc == 0 || rc == 0) return 1;
        return -1;
    }
    int supplyVaccine(Node* root){
        int vaccine = 0;
        if(help(root,vaccine) == -1) vaccine++;
        return vaccine;
    }
};
