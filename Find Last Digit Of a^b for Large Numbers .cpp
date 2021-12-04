You are given two integer numbers, the base a and the index b. You have to find the last digit of ab.

Example 1:

Input:
a = "3", b = "10"
Output:
9
Explanation:
310 = 59049. Last digit is 9.
  // code
  
  class Solution {
  public:
    int getLastDigit(string a, string b) {
        if (b.length()<2){
            int ans = pow(a[a.length()-1]-48, b[b.length()-1]-48);
            return ans%10;
        }
        int powerCycle[4];
        powerCycle[0]=4;
        for (int i=1;i<4;i++)  powerCycle[i]=i;
        int b0 = b[b.length()-1]-48;
        int b1 = b[b.length()-2]-48;
        int power = b1*10+b0;
        int base = a[a.length()-1]-48;
        power%=4;
        int ans = pow(base, powerCycle[power]);
        return ans%10;
    }
};
