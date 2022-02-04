/*Given an array of words, find all shortest unique prefixes to represent each word in the given array. Assume that no word is prefix of another.

Example 1:

Input: 
N = 4
arr[] = {"zebra", "dog", "duck", "dove"}
Output: z dog du dov
Explanation: 
z => zebra 
dog => dog 
duck => du 
dove => dov 
Example 2:

Input: 
N = 3
arr[] =  {"geeksgeeks", "geeksquiz",
                       "geeksforgeeks"};
Output: geeksg geeksq geeksf
Explanation: 
geeksgeeks => geeksg 
geeksquiz => geeksq 
geeksforgeeks => geeksf*/


// code 

class Solution
{
    public:
    struct TrieNode
    {
        TrieNode* child[26];
        int count;
        TrieNode()
        {
            for(int i = 0; i < 26; i++) child[i] = NULL;
            count = 0;
        }
    };
    void insert(string str, TrieNode* root)
    {
        int n = str.size();
        TrieNode* curr = root;
        for(int i = 0; i < n; i++)
        {
            int idx = str[i] - 'a';
            if(curr -> child[idx] == NULL) curr -> child[idx] = new TrieNode();
            curr -> count++;
            curr = curr -> child[idx];
        }
    }
    
    string get_prefix(string str, TrieNode* root)
    {
        TrieNode* curr = root;
        int n = str.size();
        string prefix = "";
        for(int i = 0; i < n; i++)
        {
            int idx = str[i] - 'a';
            if(curr -> count == 1)  break;
            prefix += str[i];
            curr = curr -> child[idx];
        }
        return prefix;
    }
    vector<string> findPrefixes(string arr[], int n)
    {
        TrieNode* root = new TrieNode();
        for(int i = 0; i < n; i++)  insert(arr[i], root);
        vector<string> vec;
        for(int i = 0; i < n; i++)
        {
            string temp = get_prefix(arr[i], root);
            vec.push_back(temp);
        }
        return vec;
    }
    
};
