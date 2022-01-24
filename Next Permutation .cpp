/*Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers. 
If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order. You are given an list of numbers arr[ ] of size N.

Example 1:

Input: N = 6
arr = {1, 2, 3, 6, 5, 4}
Output: {1, 2, 4, 3, 5, 6}
Explaination: The next permutation of the 
given array is {1, 2, 4, 3, 5, 6}.*/
  
  //  code
class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        /*
        Traverse from end of list and find a point where the numbers start to decrease.
        That's the first point. 
        Now form end to that point find a number that is greater than
        the first point so as to find next greater permutation and not a smaller number.
        Finally swap the numbers and sort the remaining list after the first point.
        */
        //if(next_permutation(arr.begin(),arr.end())) return arr;
        //sort(arr.begin(),arr.end());
        //return arr;
        int k,l;
        for(k = n-2;k>=0;k--){
            if(arr[k] < arr[k+1]) break;
        }
        if(k<0) reverse(arr.begin(),arr.end());
        else{
            for(l = n-1;l>=0;l--){
                if(arr[l] > arr[k]) break;
            }
            swap(arr[k],arr[l]);
            reverse(arr.begin()+k+1,arr.end());
        }
        return arr;
    }
};
