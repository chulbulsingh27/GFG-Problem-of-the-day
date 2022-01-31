/*Given a binary tree and a node, print all cousins of given node in order of their appearance. Note that siblings should not be printed.

Example 1:

Input : 
             1
           /   \
          2     3
        /   \  /  \
       4    5  6   7

Given node : 5
Output : 6 7
Explanation :
Nodes 6 and 7 are on the same level 
as 5 and have different parents.*/
  
  // code
  
  class Solution
{
    public:
    vector<int> printCousins(Node* root, Node* node_to_find)
    {
        queue<Node*> q;
        q.push(root);
        bool check = true;
        while(!q.empty()&& check){
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* temp = q.front();
                q.pop();
                if(temp->left == node_to_find || temp->right == node_to_find) check = false;
                else{
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
            }
        }
        vector<int> res;
        if(q.empty()) return {-1};
        else{
            while(!q.empty()){
                res.push_back(q.front()->data);
                q.pop();
            }
            
        }
        return res;
        
        //code here
    }
    
};
