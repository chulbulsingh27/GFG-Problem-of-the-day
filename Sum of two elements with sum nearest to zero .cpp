Given an array of n integers

Example 1:

Input:
N = 3
arr[] = {-8 -66 -60}
Output: -68
Explanation: Sum of two elements closest to 
zero is -68 using numbers -60 and -8.
â€‹Example 2:

Input: 
N = 6
arr[] = {-21 -67 -37 -18 4 -65}
Output: -14
Explanation: Sum of two elements closest to
zero is -14 using numbers -18 and 4.

Your Task:
You don't need to read input or print anything. You just need to complete the function closestToZero() which takes an array arr[] and its size n as inputs and returns the maximum sum closest to zero that can be formed by summing any two elements in the array.

// code
 
  class Solution
{
    public:
    int closestToZero(int arr[], int n)
    {
        sort(arr,arr+n);
        int i=0,j=n-1;
        int minsum = arr[i] + arr[j];
        while(i < j){
            int sum = arr[i] + arr[j];
            if(sum ==0) return 0;
            else if(sum > 0){
                if(abs(sum) < abs(minsum)) minsum = sum;
                else if(abs(sum) == abs(minsum)) minsum = max(sum,minsum);
                j--;
            }
            else{
                if(abs(sum) < abs(minsum)) minsum = sum;
                else if(abs(sum) == abs(minsum)) minsum = max(sum,minsum);
                i++;
            }
        }
        return minsum;
    }
};

  
