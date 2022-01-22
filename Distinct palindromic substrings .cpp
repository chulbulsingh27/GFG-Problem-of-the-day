Given a string str of lowercase ASCII characters, Count the number of distinct continuous palindromic sub-strings which are present in the string str.

Example 1:

Input:
str = "abaaa"
Output:
5
Explanation : These are included in answer:
"a","aa","aaa","aba","b"
Example 2:

Input
str = "geek"
Output: 
4
Explanation : Below are 4 palindrome sub-strings
"e","ee","g","k"
  
  // code
  
  class Solution{
  public:
    unordered_map<string, bool> m;
    void help(string &s, int i, int j){
        string x;
        if(i==j){
            x += "_";
            x += s[i];
            i--; j++;
            m[x] = true;
        }
        while(i>=0 && j<s.size() && s[i]==s[j]){
            x+=s[i];
            m[x] = true;
            i--; j++;
        }
    }
    int palindromeSubStrs(string s) {
        m.clear();
        for(int i=0; i<s.size(); i++){
            help(s, i, i);
            help(s, i, i+1);
        }
        int a = m.size();
        return a;
    }
};
