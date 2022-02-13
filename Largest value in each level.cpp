Given a binary tree, find the largest value in each level.

Example 1:

Input :
        1
       / \
      2   3 

Output : 1 3
Explanation : 
There are two levels in the tree :
1. {1}, max = 1
2. {2, 3}, max = 3
  
  
  //
  
  class Solution
{
    public:
    vector<int> largestValues(Node* root)
    {
        vector<int> vec;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int mx = INT_MIN;
            for(int i=0;i<n;i++){
                Node* temp = q.front();
                q.pop();
                mx = max(mx,temp->data);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            vec.push_back(mx);
        }
        return vec;
        //code here
    }
};
