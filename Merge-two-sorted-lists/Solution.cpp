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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        
        while(l1 && l2)
        {
            if(l1->val<=l2->val)
            {
                prev->next = l1;
                prev = prev->next;
                l1 = l1->next;
            }
            else
            {
                prev->next = l2;
                prev = prev->next;
                l2 = l2->next;
            }
        }
        
        if(l1 && !l2)
        {
            prev->next = l1;
        }
        
        if(l2 && !l1)
        {
            prev->next = l2;
        }
        
        return dummy->next;
    }
};
