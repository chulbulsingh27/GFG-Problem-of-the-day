Professor X wants his students to help each other in the chemistry lab. He suggests that every student should help out a classmate who scored less marks than him in chemistry and whose roll number appears after him. But the students are lazy and they don't want to search too far. They each pick the first roll number after them that fits the criteria. Find the marks of the classmate that each student picks.
Note: one student may be selected by multiple classmates.

Example 1:

Input: N = 5, arr[] = {3, 8, 5, 2, 25}
Output: 2 5 2 -1 -1
Explanation: 
1. Roll number 1 has 3 marks. The first person 
who has less marks than him is roll number 4, 
who has 2 marks.
2. Roll number 2 has 8 marks, he helps student 
with 5 marks.
3. Roll number 3 has 5 marks, he helps student 
with 2 marks.
4. Roll number 4 and 5 can not pick anyone as 
no student with higher roll number has lesser 
marks than them. This is denoted by -1.
Output shows the marks of the weaker student that 
each roll number helps in order. ie- 2,5,2,-1,-1
//code
  
  class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    {
        stack<int> st;
        vector<int> vec;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i] <= st.top()) st.pop();
            if(st.empty()) vec.push_back(-1);
            else vec.push_back(st.top());
            st.push(arr[i]);
        }
        reverse(vec.begin(),vec.end());
        return vec;
    } 
};
