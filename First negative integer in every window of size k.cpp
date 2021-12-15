Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

 

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
 
Example 2:
Input : 
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 
  
  //code
  
  vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k){
                                                 
    deque<long long int> dq;
    vector<long long> ans;
    /* Process first k (or first window) elements of array */
    long long int i;
    for (i = 0; i < k; i++){
        // Add current element at the rear of dq
        // if it is a negative integer
        if (arr[i] < 0) dq.push_back(i);
    }
    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for (i=k; i < n; i++) {
        // if dq is not empty then the element at the
        // front of the queue is the first negative integer
        // of the previous window
        if (!dq.empty()) ans.push_back(arr[dq.front()]);
        // else the window does not have a
        // negative integer
        else ans.push_back(0);
        // Remove the elements which are out of this window
        while ((!dq.empty()) && dq.front() < (i - k + 1))
            dq.pop_front(); // Remove from front of queue
        // Add current element at the rear of dq
        // if it is a negative integer
        if (arr[i] < 0) dq.push_back(i);
    }
    // Print the first negative
    // integer of last window
    if (!dq.empty()) ans.push_back(arr[dq.front()]);
    else ans.push_back(0);
    return ans;
}
