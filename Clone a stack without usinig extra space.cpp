Given elements of a stack, clone the stack without using extra space.


Example 1:

Input:
N = 10
st[] = {1, 1, 2, 2, 3, 4, 5, 5, 6, 7}
Output:
1 
  // code
  
  class Solution{
    public:
    void clonestack(stack<int> st, stack<int>& cloned)
    {
        //recursive approach
        /*if(st.empty()) return;
        int ele = st.top();
        st.pop();
        clonestack(st,cloned);
        cloned.push(ele);*/
        //cloned = st;
        //iterative approach
        while(!st.empty()){
            int  ele = st.top();
            int count = 0;
            st.pop();
            while(!cloned.empty()){
                st.push(cloned.top());
                cloned.pop();
                count++;
            }
            cloned.push(ele);
            while(count--){
                cloned.push(st.top());
                st.pop();
            }
        }
        
    }
};
