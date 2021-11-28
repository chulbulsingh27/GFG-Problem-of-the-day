Given a sorted linked list of distinct nodes (no two nodes have the same data) and an integer X. Count distinct triplets in the list that sum up to given integer X.

Example 1:

Input: LinkedList: 1->2->4->5->6->8->9, X = 17
Output: 2
Explanation: Distinct triplets are (2, 6, 9) 
and (4, 5, 8) which have sum equal to X i.e 17.

Example 2:

Input: LinkedList: 1->2->4->5->6->8->9, X = 15
Output: 5
Explanation: (1, 5, 9), (1, 6, 8), (2, 4, 9), 
(2, 5, 8), (4, 5, 6) are the distinct triplets

//code

int countTriplets(struct Node* head, int x) 
{
    vector<int> vec;
    int n =0;
    Node* temp = head;
    while(temp != NULL){
        vec.push_back(temp->data);
        n++;
        temp =temp->next;
    }
    int count = 0;
    for(int i = 0;i<n-1;i++){
        int low = i+1;
        int high = n-1;
        while(low < high){
            int sum = vec[low] + vec[i] + vec[high];
            if(sum == x){
                count++;
                low++;
                high--;
            }
            else if(sum < x) low++;
            else high--;
        }
    }
    return count;
} 
