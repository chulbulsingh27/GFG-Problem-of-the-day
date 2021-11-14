Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Example 1:

Input:
S = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.
//code
int countRev (string s)
{
    int n = s.size();
    if(n & 1 == 1) return -1;
    int op = 0 , cl = 0, res = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '{') op++;
        else cl++;
        if(op < cl) {
            res += cl-op;
            swap(cl,op);
        }
    }
    res += abs(op-cl)/2;
    return res;
    // your code here
}
