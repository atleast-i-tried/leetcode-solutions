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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        if(!list1 && !list2) return NULL;

        ListNode* dummy = new ListNode(-1) ;
        ListNode* copy = dummy;
        ListNode* t1 = list1;
        ListNode* t2 = list2;

        while(t1 && t2) {
            if(t1->val <= t2->val) {
                dummy->next = t1;
                dummy = dummy->next;
                t1 = t1->next;
            } else {
                dummy->next = t2;
                dummy = dummy->next;
                t2 = t2->next;
            }
        }

        if(t1) {
            dummy->next = t1;
        }
        if(t2) {
            dummy->next = t2;
        }
        return copy->next;
    }
}; 