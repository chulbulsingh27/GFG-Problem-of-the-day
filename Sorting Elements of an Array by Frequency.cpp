Given an array of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first. If frequencies of two elements are same, then smaller number comes first.

Example 1:

Input:
N = 5
A[] = {5,5,4,6,4}
Output: 4 4 5 5 6
Explanation: The highest frequency here is
2. Both 5 and 4 have that frequency. Now
since the frequencies are same then 
smallerelement comes first. So 4 4 comes 
firstthen comes 5 5. Finally comes 6.
The output is 4 4 5 5 6.
  
 // code
  
  class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    static bool comp(pair<int,int> a,pair<int,int> b){
        if(a.first != b.first) return a.first > b.first;
        if(a.first == b.first) return a.second < b.second;
        return false;
    }
    vector<int> sortByFreq(int arr[],int n)
    {
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;
        vector<pair<int,int>> vec;
        for(auto it : mp) vec.push_back({it.second,it.first});
        sort(vec.begin(),vec.end(),comp);
        vector<int> res;
        for(auto it1 : vec){
            while(it1.first){
                res.push_back(it1.second);
                it1.first--;
            }
        }
        return res;
        //Your code here
    }
};
