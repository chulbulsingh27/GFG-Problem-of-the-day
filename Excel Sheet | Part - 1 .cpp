/*Given a positive integer N, return its corresponding column title as it would appear in an Excel sheet.
For N =1 we have column A, for 27 we have AA and so on.

Note: The alphabets are all in uppercase.

Example 1:

Input:
N = 51
Output: AY*/

// code

class Solution{
    public:
    string ExcelColumn(int n)
    {
        string res;
        while(n-- >0){
            //res += ('A'+n%26);
            res = (char)('A'+(n%26))+res;
            n/=26;
        }
        //reverse(res.begin(),res.end());
        return res;
        // Your code goes here
    }
};
