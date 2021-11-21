Given two strings str1 and str2 of the same length. Find the longest prefix of str1 which is common in str2.


Example 1:

Input: 
str1 = "geeks"
str2 = "dgeek"
Output: 0 3
Explanation: 
Longest prefix from str1
present in str2 is "geek" 
starting at index 0 in str1
and ending at index 3.
Example 2:

Input:
str1 = "practicegeeks"
str2 = "coderpractice"
Output: 0 7
Explanation: 
Longest prefix from str1
present in str2 is "practice"
starting at index 0 and ending 
at index 7 in str1.
  
  //code
class Solution{
public:
    vector<int> longestCommonPrefix(string str1, string str2){
        string str;
        int i = 0;
        while(i<str1.size()){
            str.push_back(str1[i]);
            if(str2.find(str) != string::npos) i++;
            else break;
        }
        if(i == 0) return{-1,-1};
        else return {0,i-1};
    }
};
