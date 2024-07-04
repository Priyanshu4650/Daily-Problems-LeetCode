class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if (!head) return nullptr;

        ListNode* curr = head->next; // start from the first node after the initial zero
        ListNode* prev = head;
        int tempSum = 0;

        while (curr) {
            if (curr->val == 0) {
                prev->val = tempSum;
                tempSum = 0;
                prev->next = curr->next;
                prev = prev->next;
            } else {
                tempSum += curr->val;
            }
            curr = curr->next;
        }

        return head;
    }
};