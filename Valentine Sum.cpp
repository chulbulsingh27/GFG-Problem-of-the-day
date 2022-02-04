Cupid wants to strike maximum houses in Geek Land on Valentine's Day. The houses in Geek Land are arranged in the form of a binary tree. 
Cupid is standing at target node initially. 
Find the sum of all nodes within a maximum distance k from target node. The target node should be included in the sum.


Example 1:

Input:
                   1
                 /    \
                2      9
               /      /  \
              4      5     7
            /   \         /  \
           8     19     20    11
          /     /  \
         30   40   50
target = 9, K = 1
Output:
22
Explanation:
Nodes within distance 1 from 9 are 9, 5, 7, 1  

//

class Solution{

    public:
    unordered_map<Node*,Node*> mp;
    Node* parent(Node* root, int target){
        Node* t;
        if(root == NULL) return t;
        mp[root] = NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            if(temp->data == target) t = temp;
            if(temp->right) {
                mp[temp->right] = temp;
                q.push(temp->right);
            }
            if(temp->left) {
                mp[temp->left] = temp;
                q.push(temp->left);
            }
        }
        return t;
    }
    int sum_at_distK(Node* root, int target, int k)
    {
        Node* t = parent(root,target);
        if(t == NULL) return 0;
        long long int sum = 0;
        queue<Node*> q;
        set<Node*> st;
        q.push(t);
        st.insert(t);
        int level = 0;
        while(!q.empty() && level <= k){
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* temp = q.front();
                q.pop();
                sum += temp->data;
                if(temp->right && st.find(temp->right) == st.end()){
                    q.push(temp->right);
                    st.insert(temp->right);
                }
                if(temp->left && st.find(temp->left) == st.end()){
                    q.push(temp->left);
                    st.insert(temp->left);
                }
                if(mp[temp] && st.find(mp[temp]) == st.end()){
                    q.push(mp[temp]);
                    st.insert(mp[temp]);
                }
            }
            level++;
        }
        return sum;
        // Your code goes here
    }


};
