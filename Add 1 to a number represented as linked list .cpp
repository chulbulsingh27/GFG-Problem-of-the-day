A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457 
Example 2:

Input:
LinkedList: 1->2->3
Output: 124 
  // code 
  
  class Solution
{
    public:
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
    Node* addOne(Node *head) 
    {
        Node* newhead = reverse(head);
        Node* prev = NULL, *curr = newhead, *curr1 = newhead;
        int carry = 0;
        // why prev becoz after traversal curr will become NULL and if at the end carry is
        //NULL then there should some pointer whose next will point to new Node(1);
        while(curr != NULL){
            int sum = 0;
            if(prev == NULL) sum = curr->data + 1;
            else sum = curr->data + carry;
            carry = sum/10;
            curr->data = sum%10;
            prev = curr;
            curr=curr->next;
        }
        if(carry == 1) {
            Node* node = new Node(1);
            prev->next = node;
        }
        return reverse(curr1);
        
        // Your Code here
        // return head of list after adding one
    }
