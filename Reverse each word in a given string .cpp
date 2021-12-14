Given a String. Reverse each word in it where the words are separated by dots.

Example 1:

Input:
S = "i.like.this.program.very.much"
Output: i.ekil.siht.margorp.yrev.hcum
Explanation: The words "i", "like",
"this", "program", "very", "much"
are all reversed.
â€‹Example 2:

Input: 
S = "pqr.mno"
Output: rqp.onm
Explanation: Both "pqr" and "mno" are
reversed.

  //code
  
  class Solution
{
  public:
    string reverseWords (string s)
    {
        int n = s.size(), i = 0;
        stack<char> st;
        string str;
        while(i<n){
            if(s[i] == '.'){
                while(!st.empty()){
                    str+=st.top();
                    st.pop();
                }
                str += '.';
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){
            str += st.top();
            st.pop();
        }
        return str;
    }
};
