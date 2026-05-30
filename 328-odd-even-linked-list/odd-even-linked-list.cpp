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
        vector<int> even;
        vector<int> odd;
        int count=0;
        ListNode* tmp = head;

        if(head == NULL || head->next == NULL ) return head;

        while(tmp!=NULL){
            if(count%2==0){
                even.push_back(tmp->val);
            }else{
                odd.push_back(tmp->val);
            }
            tmp=tmp->next;
            count++;
        }

        tmp=head;
        
        for(int i=0;i<even.size();i++){
            tmp->val = even[i];
            tmp=tmp->next;
        }
        for(int i=0;i<odd.size();i++){
            tmp->val = odd[i];
            tmp=tmp->next;
        }
        return head;
    }
};