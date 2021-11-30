Given a BST (Binary Search Tree), find the shortest range [x, y], such that, at least one node of every level of the BST lies in the range.
If there are multiple ranges with the same gap (i.e. (y-x)) return the range with the smallest x.

Example 1:

Input:
              8
          /   \
         3     10
       /  \      \
      2    6      14
          / \     /
         4   7   12
                /  \
               11   13
Output: 6 11
Explanation: Level order traversal of the tree 
is [8], [3, 10], [2, 6, 14], [4, 7, 12], [11, 13]. 
The shortest range which satisfies the above 
mentioned condition is [6, 11]. 
//code
  
  
 class Solution{
    public:
    const int maxi = 1e9;
    struct str{
        int value, index, listNum;
    };
    struct comp {
        bool operator()(str& lhs, str& rhs) {
            return lhs.value > rhs.value;
        }
    };
    pair<int, int> findShortestRange(vector<vector<int>>& vec) {
        int maxValue = 0, n = vec.size();
        pair<int, int> res = {0,maxi};
        priority_queue<str, vector<str>, comp> pq;
        for (int i = 0; i < n; ++i) {
            pq.push({vec[i][0],0,i});
            maxValue = max(maxValue,vec[i][0]);
        }
        while(true) {
            str curr = pq.top();
            pq.pop();
            int minValue = curr.value, index = curr.index, listNum = curr.listNum;
            int diff = maxValue - minValue;
            if (diff < res.second - res.first) res = { minValue,maxValue };
            if (index == vec[listNum].size() - 1) break;
            pq.push({ vec[listNum][index + 1], index + 1, listNum });
            maxValue = max(maxValue, vec[listNum][index + 1]);
        }
       return res;
    }
    pair<int, int> shortestRange(Node *root) {
        vector<vector<int>> vec;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> nums;
            while (size--) {
                Node* temp = q.front();
                q.pop();
                nums.push_back(temp->data);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            vec.push_back(nums);
        }
        return findShortestRange(vec);
    }
};
