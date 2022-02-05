Professor McGonagall teaches transfiguration at Hogwarts. She has given Harry the task of changing himself into a cat. She explains that the trick
is to analyze your own DNA and change it into the DNA of a cat. The transfigure spell can be used to pick any one character from the DNA string, 
remove it and insert it in the beginning. 
Help Harry calculates minimum number of times he needs to use the spell to change himself into a cat.

Example 1:

Input: 
A = "GEEKSFORGEEKS" 
B = "FORGEEKSGEEKS"
Output: 3
Explanation:The conversion can take place 
in 3 operations:
1. Pick 'R' and place it at the front, 
   A="RGEEKSFOGEEKS"
2. Pick 'O' and place it at the front, 
   A="ORGEEKSFGEEKS"
3. Pick 'F' and place it at the front, 
   A="FORGEEKSGEEKS"
Example 2:

Input: 
A = "ABC" 
B = "BCA"
Output: 2
Explanation: The conversion can take place 
in 2 operations:
1. Pick 'C' and place it at the front, 
   A = "CAB"
2. Pick 'B' and place it at the front, 
   A = "BCA"
     
     
     // code
     
     class Solution{
    
    public:
    int transfigure (string a, string b)
    {
        /*int sum = 0;
        for(int i=0;i<a.size();i++){
            sum += a[i];
            sum-=b[i];
        }
        if(sum != 0) return -1;*/
        unordered_map<char,int> mp;
        for(int i=0;i<a.size();i++) mp[a[i]]++;
        for(int i=0;i<b.size();i++) mp[b[i]]--;
        for(auto it : mp){
            if(it.second != 0) return -1;
        }
        int count = 0;
        int n1 = a.length()-1;
        int n2 = b.length()-1;
        while(n1 >= 0 && n2 >= 0){
            if(a[n1] == b[n2]){
                n1--;
                n2--;
            } 
            else {
                n1--;
                count++;
            }
        }
        return count;
    	// Your code goes here
    }
};
