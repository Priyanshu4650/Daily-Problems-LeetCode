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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) {
            return head;
        }
        
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        
        // Check if there are at least k nodes left in the linked list
        int count = 0;
        curr = head;
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }
        
        // If there are at least k nodes, then proceed with the reversal
        if (count == k) {
            curr = head;
            for (int i = 0; i < k; i++) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            // Recursively reverse the next part of the list and connect it
            head->next = reverseKGroup(curr, k);
            return prev;
        } else {
            // If there are fewer than k nodes left, return the head as is
            return head;
        }
    }
};
