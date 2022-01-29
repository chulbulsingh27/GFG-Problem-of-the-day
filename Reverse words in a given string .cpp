Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:

Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i

// code

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    {
        /*string res;
        string currword;
        vector<string> words;
        for(int i=0;i<S.size();i++){
            if(S[i] == '.'){
                words.push_back(currword);
                currword = "";
            }
            else currword += S[i];
        }
        words.push_back(currword);
        for(int i = words.size()-1;i>=0;i--){
            res+=words[i];
            if(i != 0) res+='.';
        }
        return res;*/
        // code here
        /*string res;
        int r;
        int n = S.size();
        for(int i=n-1;i>=0;i--){
            if(S[i]=='.'){
                r = n-i;
                n = i-1;
                res+=(S.substr(i+1,r));
                res+=(".");
            }
        }
        res.append(S.substr(0,n+1));
        return res;*/
        string res;
        int r;
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            if(s[i]=='.'){
                r = n-i;
                n=i-1;
                res+=(s.substr(i+1,r));
                res+='.';
            }
        }
        res+=s.substr(0,n+1);
        return res;
    } 
};
