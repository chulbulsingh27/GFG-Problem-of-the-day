Given a boolean matrix of size RxC where each cell contains either 0 or 1, find the row numbers of row (0-based) which already exists or are repeated.

Example 1:

Input:
R = 2, C = 2
matrix[][] = {{1, 0},
              {1, 0}}
Output: 
1
Explanation:
Row 1 is duplicate of Row 0.

Example 2:

Input:
R = 4, C = 3
matrix[][] = {{ 1, 0, 0},
              { 1, 0, 0},
              { 1, 0, 0},
              { 0, 0, 0}}
Output: 
1 2 
Explanation:
Row 1 and Row 2 are duplicates of Row 0. 
  
  // code
  
  struct trie 
{
    int data;
    int we;
    trie *children[2];
};
trie *getNode(int c)
{
    trie *node=new trie;
    node->we=0;
    node->data=c;
    for(int i=0;i<2;i++)
    {
        node->children[i]=NULL;
    }
    return node;
}
int insertNode(trie *root,vector<int>&v)
{
    trie *tmp=root;
    for(int i=0;i<v.size();i++)
    {
        int index=v[i];
        if(!tmp->children[index])
        {
            tmp->children[index]=getNode(v[i]);
        }
        tmp=tmp->children[index];
    }
    tmp->we++;
    return tmp->we;
}
class Solution
{   
public:
vector<int> repeatedRows(vector<vector<int>> matrix, int M, int N) 
{
    vector<int>ans;
    trie *root=getNode('\0');
    for(int i=0;i<M;i++)
    {
        int res=insertNode(root,matrix[i]);
        if(res>1)
        {
            ans.push_back(i);
        }
    }
    return ans;
} 
};
