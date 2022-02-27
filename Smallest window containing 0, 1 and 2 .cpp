Given a string S consisting of the characters 0, 1 and 2. Your task is to find the length of the smallest substring of string S that contains all the three characters 0, 1 and 2.
If no such substring exists, then return -1.

Example 1:

Input:
S = "01212"
Output:
3
Explanation:
The substring 012 is the smallest substring
that contains the characters 0, 1 and 2.
  
  // code
  
  class Solution {
  public:
    int smallestSubstring(string s) {
        int n = s.size();
        int ans = INT_MAX;
        vector<int> vec(3,0);
        int j = 0;
        for(int i=0;i<n;i++){
            //int j = 0;
            vec[s[i]-'0']++;
            while(vec[s[j]-'0'] > 1){
                vec[s[j]-'0']--;
                j++;
            }
            if(vec[0] >= 1 && vec[1] >= 1 && vec[2] >= 1) ans = min(ans,i-j+1);
        }
        if(ans == INT_MAX) return -1;
        else return ans;
        // Code here
    }
};
