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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        int n=0;
        ListNode* tmp=head;
        ListNode* last=NULL;
        while(tmp!=NULL){
            n++;
            last=tmp;
            tmp=tmp->next;
        }
        
        ListNode* prev=NULL;
        tmp=head;
        k=k%n;
        if(k==0) return head;

        for(int i=0;i<n-k;i++){
            prev = tmp;
            tmp = tmp->next;
        }
        
        prev->next=NULL;
        last->next=head;

        return tmp;
    }
};