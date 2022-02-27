There are two kinds of bots A and B in a 1-D array. A bot can only move left while B can only move right. There are also empty spaces in between represented by #.
But its also given that the bots cannot cross over each other.

Given the initial state and final state, we should tell if the transformation is possible.

NOTE: There can be many bots of the same type in a particular array. 


Example 1:

Input:
s1 = #B#A#
s2 = ##BA#
Output: Yes
Explanation: Because we can reach the 
final state by moving 'B' to the 
right one step.
  
  // code
  
  class Solution{   
public:
    string moveRobots(string s1, string s2){
        int n = s1.size();
        int i = 0, j = 0;
        while(i<n && j< n){
            while(s1[i] == '#') i++;
            while(s2[j] == '#') j++;
            if(i<n && j< n){
                if((s1[i]!=s2[j]) || (s1[i]=='A'&&i<j) || (s1[i]=='B'&&i>j)) return "No";
            }
            i++;
            j++;
        }
        while(i<n){
            if(s1[i++] != '#') return "No";
        }
        while(j<n){
            if(s2[j++] != '#') return "No";
        }
        return "Yes";
        // code here 
    }
};
