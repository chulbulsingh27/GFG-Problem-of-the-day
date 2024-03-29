Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array.
Find these two numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.
Example 2:

Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and 
smallest positive missing number is 2.
  
  
  // code
  
  vector<int> findTwoElement(int *arr, int n) {
        vector<int> vec(n+1,0);
        vector<int> res;
        for(int i=0;i<n;i++) vec[arr[i]]++;
        for(int i=n;i>=0;i--) {
            if(vec[i] == 2) res.push_back(i);
        }
        for(int i=n;i>=0;i--){
            if(vec[i] == 0) res.push_back(i);
        }
        return res;
    }
