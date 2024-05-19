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
    // Function to return gcd of a and b
    int gcd(int a, int b) {
        // Find Minimum of a and b
        int result = min(a, b);
        while (result > 0) {
            if (a % result == 0 && b % result == 0) {
                break;
            }
            result--;
        }
    
        // Return gcd of a and b
        return result;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;

        ListNode *curr = head;
        ListNode *nextNode = head->next;

        while(nextNode) {
            int t = gcd(curr->val, nextNode->val);

            ListNode *temp = new ListNode(t);
            curr->next = temp;
            temp->next = nextNode;

            curr = nextNode;
            nextNode = nextNode->next;
        }

        return head;
    }
};