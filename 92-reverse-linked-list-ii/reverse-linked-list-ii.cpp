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
    ListNode* reverse(ListNode* temp1) {
        if(temp1==NULL || temp1->next==NULL) return temp1;
        ListNode* temp = temp1->next;
        temp1->next=NULL;
        ListNode* ans = reverse(temp);
        temp->next = temp1;
        return ans  ;
    }   
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* temp1=head;
        ListNode* prev = NULL;
        ListNode* temp2 = head;
        ListNode* after = NULL;
        for(int i=1;i<left;i++)
        {
            if(temp1!=NULL){
                prev=temp1;
                temp1=temp1->next;
            }
        }
        for(int i=1;i<right;i++)
        {
            if(temp2!=NULL)
            {
                temp2=temp2->next;
                after = temp2->next;
            }
        }
        if(prev!=NULL) prev->next=NULL;
        temp2->next=NULL;
        ListNode* ans = reverse(temp1);
        if(prev!=NULL) prev->next=ans;
        ListNode* tempo = ans;
        while(tempo->next!=NULL) tempo=tempo->next;
        tempo->next=after;
        if(prev==NULL) return ans; // THIS REFERS THAT THE REVERSE LIST INCLUDES HEAD POINTER. THEREFORE WE NEED TO RETURN 
        return head; 
    }
};