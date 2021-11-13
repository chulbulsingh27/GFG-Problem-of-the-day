Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

Example 1:

Input:
{([])}
Output: 
true
Explanation: 
{ ( [ ] ) }. Same colored brackets can form 
balaced pairs, with 0 number of 
unbalanced bracket.
 
  //code
  class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispair(char open,char close){
        if(open == '(' && close == ')') return true;
        else if(open == '{' && close == '}') return true;
        else if(open == '[' && close == ']') return true;
        else return false;
    }
    bool ispar(string s)
    {
        stack<char> st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(st.empty() ||  !ispair(st.top(), s[i])) return false;
                else st.pop();
            }
        }
        if(st.empty()) return true;
        else return false;
        // Your code here
    }

};
