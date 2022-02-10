Given a positive number k, we need to find a minimum value of positive integer n, such that XOR of n and n+1 is equal to k. If no such n exist then print -1.

Example 1:

Input: k = 3
Output: 1
Explaination: 1 xor 2 = 3.

Example 2:

Input: k = 6
Output: -1
Explaination: There is no such n, so that, 
n xor n+1 = k.
  
  // code 
  
  class Solution{
public:
    int xorCal(int k){
        if(k == 1) return 2;
        /*for(int i=1;i<k;i++){
            if((i^(i+1)) == k) return i;
        }*/
        if((k&(k+1)) == 0) return k/2;
        return -1;
        // code here
    }
};
