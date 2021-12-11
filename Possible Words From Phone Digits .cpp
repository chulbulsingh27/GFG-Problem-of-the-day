Given a keypad as shown in the diagram, and an N digit number which is represented by array a[ ], the task is to list all words which are possible by pressing these numbers.


Example 1:

Input: N = 3, a[] = {2, 3, 4}
Output:
adg adh adi aeg aeh aei afg afh afi 
bdg bdh bdi beg beh bei bfg bfh bfi 
cdg cdh cdi ceg ceh cei cfg cfh cfi 
Explanation: When we press 2,3,4 then 
adg, adh, adi, ... cfi are the list of 
possible words.
Example 2:

Input: N = 3, a[] = {3, 4, 5}
Output:
dgj dgk dgl dhj dhk dhl dij dik dil 
egj egk egl ehj ehk ehl eij eik eil 
fgj fgk fgl fhj fhk fhl fij fik fil
Explanation: When we press 3,4,5 then 
dgj, dgk, dgl, ... fil are the list of 
possible words.
  
  
  // code
  
  class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void help(int a[],int curridx,int n,unordered_map<int,string> &mp, string str,vector<string> &vec){
        if(curridx == n){
            vec.push_back(str);
            return;
        }
        int digit = a[curridx];
        string currstring = mp[digit];
        for(int i=0;i<currstring.size();i++) help(a,curridx+1,n,mp,str+currstring[i],vec);
    }
    vector<string> possibleWords(int a[], int n)
    {
        vector<string> vec;
        unordered_map<int,string> mp;
        mp[2] = "abc";mp[3] = "def";mp[4] = "ghi";mp[5] = "jkl";mp[6] = "mno";mp[7] = "pqrs";
        mp[8] = "tuv";mp[9] = "wxyz";
        help(a,0,n,mp,"",vec);
        return vec;
    }
};
