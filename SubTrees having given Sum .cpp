int help(Node* root, int x,int &count){
    if(root == NULL) return 0;
    int ls = help(root->left,x,count);
    int rs = help(root->right,x,count);
    int result = root->data + ls + rs;
    if(result == x) count+=1;
    return result;
}
int countSubtreesWithSumX(Node* root, int x)
{
    int count = 0;
    help(root,x,count);
    return count;
	// Code here
}



//Given a binary tree and an integer X. Your task is to complete the function countSubtreesWithSumX() that returns the count of the number of subtress having total node’s data sum equal to the value X.
//Example: For the tree given below:            

              5
            /    \
        -10     3
        /    \    /  \
      9     8  -4 7

Subtree with sum 7:
             -10
            /      \
          9        8

and one node 7.

Example 1:

Input:
       5
    /    \
  -10     3
 /   \   /  \
 9   8 -4    7
X = 7
Output: 2
Explanation: Subtrees with sum 7 are
[9, 8, -10] and [7] (refer the example
in the problem description).
