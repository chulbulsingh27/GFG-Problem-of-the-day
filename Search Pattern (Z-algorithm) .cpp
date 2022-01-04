Given two strings, one is a text string and other is a pattern string. The task is to print the indexes of all the occurences of pattern string in the text string. For printing, Starting Index of a string should be taken as 1.

Example 1:

Input:
S = "batmanandrobinarebat", pat = "bat"
Output: 1 18
Explanation: The string "bat" occurs twice
in S, one starts are index 1 and the other
at index 18. 
â€‹Example 2:

Input: 
S = "abesdu", pat = "edu"
Output: -1
Explanation: There's not substring "edu"
present in S.



// code

class Solution
{
    public:
        // Fills Z array for given string str[] 
    void getZarr(string str, int Z[]) 
    { 
        int n = str.length(); 
        int L, R, k; 
      
        // [L,R] make a window which matches with prefix of s 
        L = R = 0; 
        for (int i = 1; i < n; ++i) 
        { 
            // if i>R nothing matches so we will calculate. 
            // Z[i] using naive way. 
            if (i > R) 
            { 
                L = R = i; 
      
                // R-L = 0 in starting, so it will start 
                // checking from 0'th index. For example, 
                // for "ababab" and i = 1, the value of R 
                // remains 0 and Z[i] becomes 0. For string 
                // "aaaaaa" and i = 1, Z[i] and R become 5 
                while (R<n && str[R-L] == str[R]) 
                    R++; 
                Z[i] = R-L; 
                R--; 
            } 
            else
            { 
                // k = i-L so k corresponds to number which 
                // matches in [L,R] interval. 
                k = i-L; 
      
                // if Z[k] is less than remaining interval 
                // then Z[i] will be equal to Z[k]. 
                // For example, str = "ababab", i = 3, R = 5 
                // and L = 2 
                if (Z[k] < R-i+1) 
                    Z[i] = Z[k]; 
      
                // For example str = "aaaaaa" and i = 2, R is 5, 
                // L is 0 
                else
                { 
                    // else start from R and check manually 
                    L = i; 
                    while (R<n && str[R-L] == str[R]) 
                        R++; 
                    Z[i] = R-L; 
                    R--; 
                } 
            } 
        } 
    } 
        vector <int> search(string pat, string txt)
        {
            vector <int> res;
            string concat = pat + "$" + txt; 
            int l = concat.length(); 
  
            // Construct Z array 
            int Z[l] = {0}; 
            getZarr(concat, Z); 
  
            // now looping through Z array for matching condition 
                for (int i = 0; i < l; ++i) 
                    { 
                        // if Z[i] (matched region) is equal to pattern 
                        // length we got the pattern 
                        if (Z[i] == pat.length()) 
                         res.push_back(i - pat.length() ); 
                    } 
            return res;
        }


};
