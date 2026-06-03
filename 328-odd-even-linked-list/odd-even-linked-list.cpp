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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;  
        ListNode* even = head;
        ListNode* odd = head->next;
        ListNode* tmpEven = head;
        ListNode* tmpOdd = head->next;
        while(tmpEven->next != NULL && tmpOdd->next != NULL){
            tmpEven->next = tmpEven->next->next;
            tmpOdd->next = tmpOdd->next->next;
            tmpEven = tmpEven->next;
            tmpOdd = tmpOdd->next;
        }
        tmpEven->next = odd;
        return even;
    }
};