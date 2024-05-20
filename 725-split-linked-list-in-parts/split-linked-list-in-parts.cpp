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
private:
    void reverse(ListNode *&head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nextn;

        while(curr) {
            nextn = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextn;
        }

        head = prev;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode *> res;
        ListNode *ptr = head;
        int n = 0;

        while(ptr) {
            n += 1;
            ptr = ptr->next;
        }

        ptr = head;
        if(k >= n) {
            while(ptr) {
                res.push_back(new ListNode(ptr->val));
                ptr = ptr->next;
            }
            // Fill remaining slots with NULL
            res.resize(k, NULL);
        }
        else {
            int groupsize = n / k;
            int remainder = n % k;

            for(int i = 0; i < k; ++i) {
                ListNode *hnew = ptr;
                int group_count = groupsize + (i < remainder ? 1 : 0);
                for(int j = 1; j < group_count && ptr; ++j) {
                    ptr = ptr->next;
                }
                if(ptr) {
                    ListNode *next_ptr = ptr->next;
                    ptr->next = NULL;
                    ptr = next_ptr;
                }
                res.push_back(hnew);
            }
        }

        return res;
    }
};