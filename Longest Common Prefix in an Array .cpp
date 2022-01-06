Given a array of N strings, find the longest common prefix among all strings present in the array.


Example 1:

Input:
N = 4
arr[] = {geeksforgeeks, geeks, geek,
         geezer}
Output: gee
Explanation: "gee" is the longest common
prefix in all the given strings.
Example 2:

Input: 
N = 2
arr[] = {hello, world}
Output: -1
Explanation: There's no common prefix
in the given strings.
  
  // code
  
  class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        /*if(N==0) return "-1";
        else if(N==1) return arr[0];
        else{
            sort(arr,arr+N);
            int n = arr[0].size();
            string res;
            for(int i=0;i<n;i++){
                if(arr[0][i] == arr[N-1][i]) res += arr[0][i];
                else break;
            }
            if(res != "") return res;;
            return "-1";
            }*/
            sort(arr,arr+N);
            string res;
            int i=0,j=0;
            while(i<arr[0].size() && j<arr[N-1].size()){
                if(arr[0][i] == arr[N-1][i]){
                    res += arr[0][i];
                    i++;
                    j++;
                }
                else break;
            }
            if(res =="") return "-1";
            return res;
        // your code here
    }
  };
