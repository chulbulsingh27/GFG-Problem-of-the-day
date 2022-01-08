Given an integer N, print all the N digit numbers in increasing order, such that their digits are in strictly increasing order(from left to right).

Example 1:

Input:
N = 1
Output:
0 1 2 3 4 5 6 7 8 9
Explanation:
Single digit numbers are considered to be 
strictly increasing order.
Example 2:

Input:
N = 2
Output:
12 13 14 15 16 17 18 19 23....79 89
Explanation:
For N = 2, the correct sequence is
12 13 14 15 16 17 18 19 23 and so on 
up to 89.
  
  // code
  
  class Solution
{
public:
    void fun(int n, vector<int> &vec, int num){
        if(n == 1){
            vec.push_back(num);
            return;
        }
        for(int i=(num%10)+1;i<10;i++){
            fun(n-1,vec,num*10 + i);
        }
    }
    vector<int> increasingNumbers(int n)
    {
        if(n==1) return {0,1,2,3,4,5,6,7,8,9};
        vector<int> vec;
        for(int i =1;i<=10-n;i++) fun(n,vec,i);
        return vec;
        
    }
};
