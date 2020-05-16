/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *secondhead=head->next,*oddhead=head,*evenhead=head->next;
        while(oddhead->next && evenhead && evenhead->next)
        {
            oddhead->next = evenhead->next;
            oddhead = oddhead->next;
            evenhead->next = oddhead->next;
            evenhead = evenhead->next;
        }
        
        oddhead->next=secondhead;
                
        return head;
    }
};
