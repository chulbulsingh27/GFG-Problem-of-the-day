The first line of input contains an integer T denoting the number of test cases. The first line of each test case consists of an integer N. The second line consists of N spaced integers.The last line consists of an integer k.

Output:
Print the data value of (N/k)th node in the Linked List.

User Task:
The task is to complete the function fractional_node() which should find the n/kth node in the linked list and return its data value.

Constraints: 
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
6
1 2 3 4 5 6
2
5
2 7 9 3 5
3

Output:
3
7

Explanation:
Testcase 1: 6/2th element is the 3rd(1-based indexing) element which is 3.
  
  // code
  
  int fractional_node(struct Node *head, int k)
{
    int count = 0, dis;
    Node* ptr1 = head;
    while(ptr1 != NULL)
    {
        count++;
        ptr1=ptr1->next;
    }
    if(count%k==0) dis=count/k;
    else dis=(count/k)+1;
    int count1=1;
    ptr1=head;
    while(count1<=count)
    {
        if(count1==dis) return ptr1->data;
        count1++;
        ptr1=ptr1->next;
    }
}
