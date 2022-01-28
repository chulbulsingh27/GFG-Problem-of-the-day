Given 2 integers n and r. You task is to calculate nCr%1000003.
 

Example 1:

Input: n = 5, r = 2
Output: 10
Explanation: 5C2 = 5! / (2! * 3!) = 10
Example 2:

Input: n = 3, r = 2
Output: 3
Explanation: 3C2 = 3! / (2! * 1!) = 3
  
  // code
  
  #define vc vector
//#define int int40_t


static constexpr int kMod = 1000003;
static int maxFact;
static long long fact[kMod+1];
class Solution {
public:

long long power(long long x, int p) {
    if (p == 0) {
        return 1;
    }
    if (p == 1) {
        return x;
    }
    
    auto t = power(x, p >> 1);
    auto res = t*t % kMod;
    if ((p&1) != 0) {
        res = res*x % kMod;
    }
    return res;
}

inline long long mod_inverse(long long x) {
    // Euler formula:
    //  a^(-1) = x^(phi(m)-1)
    //    m = prime -> phi(m) = m-1
    //  a^(-1) = x^(m-2)
    return power(x, kMod-2);
}
long long f(int n) {
    if (n <= maxFact) {
        return fact[n];
    }
    for (int i = maxFact+1; i <= n; i++) {
        fact[i] = fact[i-1]*i % kMod;
    }
    maxFact = n;
    return fact[n];
}

int rCnModP(int n, int r) {
    if (r > n) {
        return 0;
    }
    if (r == 0 || r == n) {
        return 1;
    }
    
    auto f_n = f(n);
    auto f_r = f(r);
    auto f_nr = f(n-r);
    long long t = f_n * (mod_inverse(f_r)*mod_inverse(f_nr) % kMod);
    return (int) (t % kMod);
}

int rCnModPrimeLucas(long long n, long long r) {
    if (r == 0) {
        return 1;
    }
    int ni = (int) (n % kMod);
    int ri = (int) (r % kMod);
    long long t = (long long) rCnModPrimeLucas(n/kMod, r/kMod) * rCnModP(ni, ri) % kMod;
    return (int) t;
}

int findByCrt(int rem) {
    int min_x = 0;
    while (true) {
        if (min_x % kMod == rem) {
            return min_x;
        }
        min_x++;
    }
}
int nCr(long long n, long long r) {
    memset(fact, 0, sizeof fact);
    fact[0] = fact[1] = 1;
    maxFact = 1;
    int rem = rCnModPrimeLucas(n, r);
    return findByCrt(rem);
}
};
