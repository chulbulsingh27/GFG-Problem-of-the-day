Given an N bit binary number, find the 1's complement of the number. The ones' complement of a binary number 
is defined as the value obtained by inverting all the bits in the binary representation of the number (swapping 0s for 1s and vice versa).
 

Example 1:

Input:
N = 3
S = 101
Output:
010
Explanation:
We get the output by converting 1's in S
to 0 and 0s to 1
Example 2:

Input:
N = 2
S = 10
Output:
01
Explanation:
We get the output by converting 1's in S
to 0 and 0s to 1
  
  // code
  
  class Solution{ 
public:
    string onesComplement(string s,int n){
        for(int i=0;i<n;i++){
            if(s[i]=='1') s[i] = '0';
            else if(s[i]=='0') s[i] = '1';
        }
        return s;
    }
};
