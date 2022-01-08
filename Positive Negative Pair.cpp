Given an array of distinct integers, find all the pairs having both negative and positive values of a number in the array.


Example 1:

Input:
n = 8
arr[] = {1,3,6,-2,-1,-3,2,7}
Output: -1 1 -3 3 -2 2
Explanation: 1, 3 and 2 are present 
pairwise postive and negative. 6 and 
7 have no pair.
Example 2:

Input:
n = 3
arr[] = {3,2,1}
Output: 0
Explanation: No such pair exists so the 
output is 0.
  
  // code
  
  class Solution{
  public:
    //Function to return list containing all the pairs having both
    //negative and positive values of a number in the array.
    vector <int> findPairs(int arr[], int n) 
    {
        unordered_set<int> st;
        vector<int> vec;
        for(int i=0;i<n;i++){
            if(st.find(-1*arr[i]) != st.end()){
                vec.push_back(-1*abs(arr[i]));
                vec.push_back(abs(arr[i]));
            }
            st.insert(arr[i]);
        }
        return vec;
        // code here
    }
};
