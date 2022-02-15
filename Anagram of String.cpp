Given two strings S1 and S2 in lowercase, the task is to make them anagram. The only allowed operation is to remove a character from any string.
Find the minimum number of characters to be deleted to make both the strings anagram. Two strings are called anagram of each other if one of them can be converted into another by rearranging its letters.

Example 1:

Input:
S1 = bcadeh
S2 = hea
Output: 3
Explanation: We need to remove b, c
and d from S1.
  
  // code
  
  int remAnagram(string str1, string str2)
{
    /*int ans = 0;
    unordered_map<char,int>mp;
    for(auto it : str1) mp[it]++;
    for(auto it1: str2) mp[it1]--;
    for(auto it : mp)  ans += abs(it.second);
    return ans;*/
    int n1 = str1.size();
    int n2 = str2.size();
    int arr1[1001] = {0}, arr2[1001] = {0};
    for(int i=0;i<n1;i++) arr1[str1[i]-'a']++;
    for (int i=0;i<n2;i++) arr2[str2[i]-'a']++;
    int result = 0;
    for (int i=0; i<26; i++) result += abs(arr1[i] - arr2[i]);
    return result;
}
