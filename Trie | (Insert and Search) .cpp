Trie is an efficient information retrieval data structure. Use this data structure to store Strings and search strings. Your task is to use TRIE data structure and search the given string A. If found print 1 else 0.

Example 1:

Input:
N = 8
key[] = {the,a,there,answer,any,by,
         bye,their}
search = the
Output: 1
Explanation: the is present in the given
string "the a there answer any by bye
their"
 
 // code
 void insert(struct TrieNode *root, string key)
{
    for(auto it : key){
        if(root->children[it-'a'] == NULL) root->children[it-'a'] = new TrieNode();
        root=root->children[it-'a'];
    }
    root->isLeaf = true;
    // code here
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    for(auto it : key){
        if(root->children[it-'a'] == NULL) return false;
        root=root->children[it-'a'];
    }
    return root->isLeaf;
    // code here
}
