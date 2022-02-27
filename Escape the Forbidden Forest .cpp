Penelope and her classmates are lost in the Forbidden Forest and the Devil is out to get them. But Penelope has magical powers that can build bridges across the dangerous 
river and take her friends to safety. The only bridges that can withstand the Devil's wrath are the ones built between two similar trees in the forest. 
Given str1 and str2 denoting the order of trees on either side of the river, find the maximum number of bridges that Penelope can build and save everyone from the Devil. 
Note: Each tree in the forest belongs to one of the 3 categories represented by * or # or @

Example 1:

Input:
str1 = "*@#*" 
str2 = "*#"
Output:
2
Explanation:
str1 = "*@#*" and str2 = "*#" 
Two bridges can be built between the banks 
of the river in the following manner. 
* @ # *
|      |
*     #

// code

class Solution
{
    public:
    int dp[101][101];
    int lcsfun(string str1, string str2, int i, int j){
        if(i == 0 ||  j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(str1[i-1] == str2[j-1]) return dp[i][j] = 1+lcsfun(str1,str2,i-1,j-1);
        return dp[i][j] = max(lcsfun(str1,str2,i,j-1),lcsfun(str1,str2,i-1,j));
    }
    int build_bridges(string str1, string str2)
    {
        memset(dp,-1,sizeof(dp));
        return lcsfun(str1,str2,str1.size(),str2.size());
    }
};
