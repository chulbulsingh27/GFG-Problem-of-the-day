Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
  
  // code
  Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* next;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        Node* slow = head;
        Node* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;
        while(slow != NULL){
            if(head->data != slow->data) return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};
