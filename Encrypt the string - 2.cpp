You are given a string S. Every sub-string of identical letters is replaced by a single instance of that letter followed by the hexadecimal representation of the
number of occurrences of that letter. Then, the string thus obtained is further encrypted by reversing it [ See the sample for more clarity ]. 
 Print the Encrypted String.

Note: All Hexadecimal letters should be converted to Lowercase letters.
Example 1:

Input:
S = "aaaaaaaaaaa"
Output:
ba 
Explanation: 
aaaaaaaaaaa
Step1: a11 (a occurs 11 times)
Step2: a11 is ab [since 11 is b in
hexadecimal]
Step3: ba [After reversing]
Example 2:

Input:
S = "abc"
Output:
1c1b1a
Explanation: 
abc
Step1: a1b1c1
Step2: 1c1b1a [After reversing]

//code

class Solution {
  public:
    string encryptString(string S) {
        int i,j=0;
        vector<pair<char,int>> p; 
        p.push_back({S[0],1});
        for(i=1;i<S.size();i++)
        {
            if(S[i]==p[j].first) p[j].second += 1;
            else
            {
                p.push_back({S[i],1});
                j++;
            }
        }
        for(auto it=p.rbegin();it!=p.rend();it++){
            printf("%x%c",(*it).second,(*it).first);
        }
     }
};
