Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList.
The second part of this problem can be found here.


Example 1:

Input:
wordList = {"des","der","dfr","dgt","dfs"}
startWord = "der", targetWord= "dfs",
Output:
3
Explanation:
The length of the smallest transformation
sequence from "der" to "dfs" is 3
i,e "der" -> "dfr" -> "dfs".




//
class Solution{
    public:
      int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),targetWord)==wordList.end()) return 0;
        set<string> s;
        for(auto i:wordList) s.insert(i);
        queue<string> q;
        q.push(startWord);
        int d=0;
        while(!q.empty())
        {
            d++;
            int n=q.size();
            while(n--)
            {
                string curr=q.front();
                q.pop();
                for(int i=0;i<curr.length();i++)
                {
                    string tmp=curr;
                    for(char c='a';c<='z';c++)
                    {
                        tmp[i]=c;
                        if(tmp==curr) continue;
                        if(tmp==targetWord) return d+1;
                        if(s.find(tmp)!=s.end())
                        {
                            q.push(tmp);
                            s.erase(tmp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
int main{
  int tc;
  cin>>tc;
  while(tc--){
    int n;
    cin>>n;
    vector<string> wordList(n);
    for(int i=0;i<n;i++) cin>> wordList[i];
    string startWord,targetWord;
    cin>> startWord >> targetWord;
    Solution obj;
    int ans = obj.wordLadderLength(startWord,targetWord,wordList);
    cout<<ans<<endl;
    return 0;
  }
}
        
