Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency.
Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.
Note: If two elements have same frequency, then the element which occur at first will be taken on the left of Binary Tree and other one to the right.

Example 1:

S = "abcdef"
f[] = {5, 9, 12, 13, 16, 45}
Output: 
0 100 101 1100 1101 111
Explanation:
HuffmanCodes will be:
f : 0
c : 100
d : 101
a : 1100
b : 1101
e : 111
Hence printing them in the PreOrder of Binary 
Tree.
  
  //code
  
  class Solution
{
	public:
	struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val)
        {
           data = val;
           left = NULL;
           right = NULL;
        }
    };
    // To compare two points
    struct compare {
        bool operator()(Node* l, Node* r)
        {
            return (l->data > r->data);
        }
    };
    void preorder(vector<string> &res, Node *root, string s)
    {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) res.push_back(s);
        preorder(res, root->left , s + "0");
        preorder(res, root->right , s + "1");
    }
	vector<string> huffmanCodes(string S,vector<int> f,int N)
	{
	    priority_queue<Node *, vector<Node*>, compare> pq;
        for (int i = 0; i < f.size(); i++)
        {
            Node *temp = new Node(f[i]);
            pq.push(temp);
        }
        vector<string> res;
        for (int i = 1; i < N; i++)
        {
            Node *x = pq.top();
            pq.pop();
            Node *y = pq.top();
            pq.pop();
            Node *temp = new Node(x->data + y->data);
            temp->left = x;
            temp->right = y;
            pq.push(temp);
        }
        preorder(res, pq.top() , "");
        return res;
    }
};

  
