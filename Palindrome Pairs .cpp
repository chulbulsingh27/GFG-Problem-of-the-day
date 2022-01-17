Given an array of strings arr[] of size N, find if there exists 2 strings arr[i] and arr[j] such that arr[i]+arr[j] is a palindrome 
i.e the concatenation of string arr[i] and arr[j] results into a palindrome.


Example 1:

Input:
N = 6
arr[] = {"geekf", "geeks", "or","keeg", "abc", 
          "bc"}
Output: 1 
Explanation: There is a pair "geekf"
and "keeg".
Example 2:

Input:
N = 5
arr[] = {"abc", "xyxcba", "geekst", "or", "bc"}
Output: 1
Explanation: There is a pair "abc"
and "xyxcba".
  
  // code
  
  class Solution{   
  public:
    // Function to check if a palindrome pair exists
    bool palin(string s){
        string res = s;
        reverse(res.begin(),res.end());
        if(s == res) return true;
        return false;
    }
    bool palindromepair(int n, string arr[]) {
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            auto s = arr[i];
            reverse(s.begin(),s.end());
            mp.insert({s,i});
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<arr[i].size();j++){
                string s1 = arr[i].substr(0,j);
                string s2 = arr[i].substr(j);
                if(mp.count(s1) && palin(s2) && mp[s1] != i) return true;
                if(mp.count(s2) && palin(s1) && mp[s2] != i) return true;
            }
        }
        return false;
    }

};
