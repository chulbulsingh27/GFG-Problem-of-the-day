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
