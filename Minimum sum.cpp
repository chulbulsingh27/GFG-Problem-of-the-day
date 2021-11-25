Given an array Arr of size N such that each element is from the range 0 to 9. Find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers.


Example 1:

Input:
N = 6
Arr[] = {6, 8, 4, 5, 2, 3}
Output: 604
Explanation: The minimum sum is formed 
by numbers 358 and 246.
  
  // code
  
  class Solution{   
  public:
    string solve(int arr[], int n) {
        sort(arr,arr+n);
        string res;
        int carry = 0;
        for(int i=n-1;i>=0;i-=2){
            int x = arr[i] + arr[i-1] + carry;
            if(x == 0) return res;
            carry = x/10;
            x = x%10;
            res = to_string(x) + res;
        }
        if(carry != 0) res = to_string(carry) + res;
        return res;
    }
};
