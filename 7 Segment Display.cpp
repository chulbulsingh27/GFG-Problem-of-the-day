Using seven segment display, you can write down any digit from 0 to 9 using at most seven segments. Given a positive number N and then a string S representing a number of N digits. You have to rearrange the segments in this N digit number to get the smallest possible N digit number. This number can have leading zeros. You can not waste any segment or add any segment from your own. You have to use all of the segments of the given N digits.

Note: You can refer this diagram for more details



Example 1:

Input:
N = 6
S = "234567"
Output:
000011
Explanation:
234567 has a total of 28 segments and
we can rearrange them to form 000011
which has 28 segments too. 000011 is the
smallest possible number which can be
formed on rearrangement.
  // code
  class Solution {
  public:
    string sevenSegments(string S, int N) {
        S = S.substr(0, N);
        int seg[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 5};
        int cnt = 0;
        for(auto i:S){
            cnt += seg[i-'0'];
        }
        string x = "" ;
        for(int i = N-1; i>=0;i--){
            for(int j=0; j<10; j++){
               if(cnt-seg[j]>=2*i && cnt-seg[j]<=7*i){
                   x += (j+'0');
                   cnt -= seg[j];
                   break;
               }
            }
        }
        return x;
    }
};
