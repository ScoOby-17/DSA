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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* dummy = new ListNode(-1); dummy->next = head;
        ListNode* prev=dummy , *curr=head;
        bool isDel = false;

        while(curr){
            if(curr->next && curr->next->val == curr->val){
                isDel = true;
                curr = curr->next; continue;
            }
            if(isDel){
                isDel = false;
                prev->next = curr->next;
                curr = curr->next; continue;
            }
            prev = curr;
            curr = curr->next;
        }
        head = dummy->next;
        return head;
    }
};