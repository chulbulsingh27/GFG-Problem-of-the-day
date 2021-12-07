Given an array Arr[] of N distinct integers and a range from L to R, the task is to count the number of triplets having a sum in the range [L, R].
Example 1:

Input:
N = 4
Arr = {8 , 3, 5, 2}
L = 7, R = 11
Output: 1
Explaination: There is only one triplet {2, 3, 5}
having sum 10 in range [7, 11].

Example 2:

Input:
N = 5
Arr = {5, 1, 4, 3, 2}
L = 2, R = 7
Output: 2
Explaination: There two triplets having 
sum in range [2, 7] are {1,4,2} and {1,3,2}.
  //code
  
  class Solution {
  public:
    int help(int arr[],int n, int res){
        sort(arr,arr+n);
        int ans =0;
        for(int i=0;i<n-2;i++){
            int l = i+1, r = n-1;
            while(l < r){
                int sum = arr[i] + arr[l] + arr[r];
                if(sum > res) r--;
                else{
                    ans += (r-l);
                    l++;
                }
            }
            
        }
        return ans;
    }
    int countTriplets(int arr[], int n, int l, int r) {
        int x = help(arr,n,r);
        int y = help(arr,n,l-1);
        return x-y;
    }
};
