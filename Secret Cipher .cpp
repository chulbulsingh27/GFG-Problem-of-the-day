Geek wants to send an encrypted message in the form of string S to his friend Keeg along with instructions on how to decipher the message. To decipher the message, his friend needs to iterate over the message string from left to right, if he finds a '*', he must remove it and add all the letters read so far to the string. He must keep on doing this till he gets rid of all the '*'.
Can you help Geek encrypt his message string S? 

Note: If the string can be encrypted in multiple ways, find the smallest encrypted string. 

Example 1:

Input: S = "ababcababcd"
Output: ab*c*d
Explanation: We can encrypt the string 
in following way : "ababcababcd" -> 
"ababc*d" -> "ab*c*d"
Example 2:

Input: S = "zzzzzzz"
Output: z*z*z
Explanation: The string can be encrypted 
in 2 ways: "z*z*z" and "z**zzz". Out of 
the two "z*z*z" is smaller in length.
  
  //code
  
  class Solution{
    public:
    string compress(string s)
    {
        int n =s.size();
        vector<int> vec(n);
        for(int i=1;i<n;i++){
            int j = vec[i-1];
            while(j >0 && s[i] != s[j]) j=vec[j-1];
            if(s[i] == s[j]) j++;
            vec[i] = j;
        }
        string res;
        for(int i=n-1;i>=0;i--){
            if(i%2){
                if(vec[i] >= (i+1)/2 && (i+1)%(2*(i+1-vec[i])) == 0){
                    res.push_back('*');
                    i/=2;
                    i++;
                }
                else res.push_back(s[i]);
            }
            else res.push_back(s[i]);
        }
        reverse(res.begin(),res.end());
        return res;
        // Your code goes here
    }
};
