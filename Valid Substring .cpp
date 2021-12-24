Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid(well-formed) parentheses substring.
NOTE: Length of the smallest valid substring ( ) is 2.

Example 1:

Input: S = "(()("
Output: 2
Explanation: The longest valid 
substring is "()". Length = 2.
Example 2:

Input: S = "()(())("
Output: 6
Explanation: The longest valid 
substring is "()(())". Length = 6.
  
  //
  
  class Solution {
  public:
    int findMaxLen(string str) {
        int res = 0;
        int open = 0;
        int close = 0;
        for(int i=0;i<str.size();i++){
            if(str[i] == '(') open++;
            else close++;
            if(open == close) res = max(res,2*open);
            else if(open < close){
                open = close = 0;
            }
        }
        open = 0;
        close = 0;
        for(int i=str.size()-1;i>=0;i--){
            if(str[i] == '(') open++;
            else close++;
            if(open == close) res = max(res,2*open);
            else if(close < open) open = close = 0;
        }
        return res;
    }
};
