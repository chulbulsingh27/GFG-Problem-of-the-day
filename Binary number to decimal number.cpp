Given a Binary Number B, find its decimal equivalent.
Example 1:

Input: B = 10001000
Output: 136
Example 2:

Input: B = 101100
Output: 44
  
  // code 
  
  class Solution
{
	public:
		int binary_to_decimal(string str)
		{
		    int res  =0;
		    //return stoi(str,0,2);
		    int n = str.size();
		    for(int i=0;i<n;i++){
		        res += pow(2,(n-i-1)) * (str[i]-'0');
		    }
		    return res;
		}
};
