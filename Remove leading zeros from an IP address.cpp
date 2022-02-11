Given an IP address, remove leading zeros from the IP address. Note that our IP address here can be a little different. 
It can have numbers greater than 255. Also, it does not necessarily have 4 numbers. The count can be lesser/more.

Example 1:

Input:
S = "100.020.003.400"
Output: 100.20.3.400
Explanation: The leading zeros are removed
from 20 and 3.
Example 2:

Input: 
S = "100.000.010.0999"
Output: 100.0.10.999
Explanation: The leading zeros are removed
from 0, 10 and 999.
  
  // code
  
  class Solution
{
  public:
    string newIPAdd (string s)
    {
        string res;
        int n = s.size();
        int i=0,j=0;
        while(i<n)
        {
            // if current character is dot include it in res
            if(s[i] == '.'){
                res += s[i];
                i++;
            }
            else{
                j = i;
                while(j<n && s[j] == '0') j++;// ignore leading zero
                if(j == n || s[j]=='.') res += '0';
                else{//include current number in res
                    while(j<n && s[j] != '.'){
                        res += s[j++];
                    }
                    
                }
                i=j;
            }
        }
        return res;
    }
};
