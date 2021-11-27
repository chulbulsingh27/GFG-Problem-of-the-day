Given N activities with their start and finish day given in array start[ ] and end[ ]. 
Select the maximum number of activities that can be performed by a single person,
assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day.


Example 1:

Input:
N = 2
start[] = {2, 1}
end[] = {2, 2}
Output: 
1
Explanation:
A person can perform only one of the
given activities.
  
  Example 2:

Input:
N = 4
start[] = {1, 3, 2, 5}
end[] = {2, 4, 3, 6}
Output: 
3
Explanation:
A person can perform activities 1, 2
and 4.
  
  // code
 static bool comp(const pair<int,int> &a, const pair<int,int> &b){
        return (a.second < b.second);
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>> vec; 
        for(int i = 0; i < n; ++i) vec.push_back({start[i], end[i]});  
        sort(vec.begin(), vec.end(), comp); 
        int count = 1; 
        int time_end = vec[0].second;
        for(int i = 1; i < vec.size() ; ++i) {
            if(vec[i].first > time_end) {
                count++; 
                time_end = vec[i].second;  
            }
        }
        return count; 
    }
