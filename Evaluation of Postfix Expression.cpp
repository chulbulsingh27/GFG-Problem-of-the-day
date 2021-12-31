Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. 
Operators will only include the basic arithmetic operators like *, /, + and -.

 

Example 1:

Input: S = "231*+9-"
Output: -4
Explanation:
After solving the given expression, 
we have -4 as result.
Example 2:

Input: S = "123+*8-"
Output: -3
Explanation:
After solving the given postfix 
expression, we have -3 as result.
  
  // code
  
  class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        int n = s.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])) st.push(s[i]-'0');
            else{
                int res2 = st.top();
                st.pop();
                int res1 = st.top();
                st.pop();
                switch(s[i]){
                    case '+':
                    st.push(res1+res2);
                    break;
                    case '-':
                    st.push(res1-res2);
                    break;
                    case '*':
                    st.push(res1*res2);
                    break;
                    case '/':
                    st.push(res1/res2);
                    break;
                }
            }
        }
        return st.top();
    }
};
