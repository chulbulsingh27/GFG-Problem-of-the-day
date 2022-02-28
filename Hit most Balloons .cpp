You are given an infinite two-dimensional grid. There are N balloons placed at certain coordinates of the grid. You have an arrow with yourself, 
which you will be using to shoot the balloons. You can select any point on the grid as your starting point and any point on the grid as the target point.
When you fire the arrow, all ballons lying on the shortest path between the starting point and target point will be burst.
Given the coordinates of the N ballons in an array arr, your task is to find out the maximum number of balloons that you can fire in one arrow shot.

Example 1:

Input:
N = 3
arr[] = {{1, 2}, {2, 3}, {3, 4}}
Output:
3
Explanation:
If you position yourself at point (1,2)
and fire the arrow aiming at the point (3,4).
Then all the balloons will burst.
  
  // code
  
  class Solution {
  public:
    int mostBalloons(int n, pair<int, int> arr[]) {
        int maxi, res  = 0, k;
        double slope = 0;
        for(int i = 0;i < n; i++){
            unordered_map<double,int> mp;
            k = 0;
            maxi = 0;
            for(int j=0;j<n;j++){
                if(arr[i] == arr[j]){
                    k++;
                    continue;
                }
                else if(arr[i].first-arr[j].first == 0) slope = INT_MAX*1e4;
                else{
                    slope=((double)(arr[i].second-arr[j].second))/((double)(arr[i].first-arr[j].first));
                }
                mp[slope]++;
                maxi = max(maxi,mp[slope]);
            }
            res = max(res,maxi+k);
        }
        return res;
    }
};
