Given an array arr[ ] of positive integers, the task is to find the maximum XOR value of the elements from all the possible subsets.

Example 1:

Input: N = 3, arr[] = {2, 4, 5}
Output: 7
Explanation: Subset {2, 5} has maximum xor
Example 2:

Input: N = 1, arr[] = {1}
Output: 1
Explanation: Subset {1} has maximum xor
  
  //code
  
  class Solution{
	public:
	int maxXor(int arr[], int n)
	{
	    int maxEle = INT_MIN;
        for(int i = 0; i < n; ++i)  maxEle = max(maxEle, arr[i]);
        int MSB = 0;
        for(int i = 31; i >= 0; --i)
        if((1 << i) & maxEle) {
            MSB = i; 
            break;
        }
        int index = 0;
        for(int i = MSB; i >= 0; --i) {
            int maxIndex = index, maxElement = INT_MIN;
            for(int j = index; j < n; ++j)
            if(arr[j] & (1 << i) && arr[j] > maxElement)
            maxIndex = j, maxElement = arr[j];
            if(maxElement == INT_MIN) continue; // if there's no maxElement, there's no use going ahead.
            swap(arr[index], arr[maxIndex]); // since we don't want to affect the number in 'index' position
            maxIndex = index; // since now the position of maxElement is changed to 'index' in arr[]
            for(int j = 0; j < n; ++j){
                if(j != maxIndex && arr[j] & (1 << i))
                arr[j] ^= arr[maxIndex];
            }
            ++index;
        }
        int res = 0;
        for(int i = 0; i < n; ++i) res ^= arr[i];
  
  // This is where we individualize the subsets, as we can have subsets of 1 element each.
  // And XOR of such subsets is the element itself, and so, the max element out of all those
  // elements will be the max XOR value iff XOR of some other subset is greater, thereby, the following line of code:        
        return max(res, maxEle);
    }
};
