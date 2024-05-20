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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        ListNode *first = head;
        ListNode *second = head;

        while(first) {
            while(second) {
                if(first->val > second->val) {
                    swap(first->val, second->val);
                }
                second = second->next;
            }
            first = first->next;
            second = first;
        }
        return head;
    }
};