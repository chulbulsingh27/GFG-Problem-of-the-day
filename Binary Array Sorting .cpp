Given a binary array A[] of size N. The task is to arrange the array in increasing order.
Note: The binary array contains only 0  and 1.
 

Example 1:

Input: 
5
1 0 1 1 0

Output: 
0 0 1 1 1

Explanation: 
After arranging the elements in 
increasing order, elements will be as 
0 0 1 1 1.
Example 2:

Input:
10
1 0 1 1 1 1 1 0 0 0

Output: 
0 0 0 0 1 1 1 1 1 1

Explanation: 
After arranging the elements in 
increasing orde, elements will be 
0 0 0 0 1 1 1 1 1 1.
  
  
  // code
  
  class Solution{
  public:
    void binSort(int arr[], int n)
    {
        /*int c0 = 0;
        int c1 = 0;
        for(int i=0;i<n;i++){
            if(arr[i] == 0) c0++;
            else c1++;
        }
        for(int i=0;i<c0;i++) arr[i] = 0;
        for(int i=c0;i<c1+c0;i++) arr[i] = 1;*/
        int l=0;
        int r=n-1;
        while(l<r){
            if(arr[l] == 0) l++;
            else if(arr[r] == 1) r--;
            else{
                swap(arr[l],arr[r]);
                l++;
                r--;
            }
        }
    }
};
