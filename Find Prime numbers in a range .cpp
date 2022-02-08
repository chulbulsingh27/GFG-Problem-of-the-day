Given two integers M and N, generate all primes between M and N.

Example 1:

Input:
M=1,N=10
Output:
2 3 5 7
Explanation:
The prime numbers between 1 and 10
are 2,3,5 and 7.
Example 2:

Input:
M=2, N=5
Output:
2,3,5
Explanation:
The prime numbers between 2 and 5 are 
2,3 and 5.



// code

class Solution {
  public:
  bool isprime(int n){
      if(n<2) return false;
      for(int i=2;i<=sqrt(n);i++){
          if(n%i == 0) return false;
      }
      return true;
  }
    vector<int> primeRange(int M, int N) {
        vector<int> vec;
        for(int i=M;i<=N;i++){
            if(isprime(i)) vec.push_back(i);
        }
        return vec;
        // code here
    }
};
