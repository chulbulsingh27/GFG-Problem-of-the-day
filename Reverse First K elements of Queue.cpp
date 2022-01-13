Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Example 1:

Input:
5 3
1 2 3 4 5

Output: 
3 2 1 4 5

Explanation: 
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.
  
  // code
  
  queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> st;
    queue<int> q1;
    while(k-- > 0){
        int a = q.front();
        q.pop();
        st.push(a);
    }
    while(!st.empty()){
        int a = st.top();
        st.pop();
        q1.push(a);
    }
    while(!q.empty()){
        int a = q.front();
        q.pop();
        q1.push(a);
        
    }
    return q1;
    // add code here.
}
