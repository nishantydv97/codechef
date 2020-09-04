/*


Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?



*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL)
            return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }
        if(fast==NULL)
            return head->next;
        ListNode* temp;
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
        
        
    }
};
