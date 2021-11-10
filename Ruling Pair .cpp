Geek Land has a population of N people and each person's ability to rule the town is measured by a numeric value arr[i]. The two people that can together rule Geek Land must be compatible with each other i.e., the sum of digits of their ability arr[i] must be equal. Their combined ability should be maximum amongst all the possible pairs of people. Find the combined ability of the Ruling Pair.

Example 1:

Input:
N = 5
arr[] = {55, 23, 32, 46, 88}
Output:
101
Explanation:
All possible pairs that are 
compatible with each other are- (23, 32) 
with digit sum 5 and (55, 46) with digit 
sum 10. Out of these the maximum combined 
ability pair is (55, 46) i.e. 55 + 46 = 101
  
  
  //code
  
  class Solution{
    
    public:
    int digitsum(int n){
        int sum =0;
        while(n){
            sum += n%10;
            n/=10;
        }
        return sum;
    }
    int RulingPair(vector<int> arr, int n) 
    {
        unordered_map<int,int> mp;
        int ans = -1;
        for(int i=0;i<n;i++){
            int dsum = digitsum(arr[i]);
            if(mp.find(dsum) ==mp.end()){
                mp[dsum] = arr[i];
                continue;
            }
            //int tans = mp[dsum] + arr[i];
            ans = max(ans,mp[dsum] + arr[i]);
            mp[dsum] = max(mp[dsum],arr[i]);
        }
        return ans;
    	// Your code goes here
    }   
};
