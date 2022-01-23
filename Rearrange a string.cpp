/*Given a string containing uppercase alphabets and integer digits (from 0 to 9), the task is to print the alphabets in the lexicographical order followed by the sum of digits.

Example 1:

Input: S = "AC2BEW3"
Output: "ABCEW5"
Explanation: 2 + 3 = 5 and we print all
alphabets in the lexicographical order. 
Example 2:

Input: S = "ACCBA10D2EW30"
Output: "AABCCDEW6"
Explanation: 0+1+2+3 = 6 and we print all
alphabets in the lexicographical order. */

// code

class Solution
{
  public:
    string arrangeString(string str)
    {
        int n = str.size();
        sort(str.begin(),str.end());
        int sum = 0;
        string res;
        for(int i=0;i<n;i++){
            if(str[i]-'0' >= 0 && str[i]-'0' <= 9) sum += str[i]-'0';
            else res += str[i];
        }
        if(sum) res += to_string(sum);
        return res;
        
    }
};
