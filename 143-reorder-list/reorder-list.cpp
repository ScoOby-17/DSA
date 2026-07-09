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
    void reorderList(ListNode* head) {
        vector<int>arr;
        ListNode* tmp = head;
        while(tmp!=NULL){
            arr.push_back(tmp->val);
            tmp = tmp->next;
        }

        int i=0,j=arr.size()-1;
        tmp=head;
        int count = 0;
        while(i<=j){
            if(count%2==0){
                tmp->val = arr[i];
                i++;
            }else{
                tmp->val = arr[j];
                j--;
            }
            count++;
            tmp=tmp->next;
        }
    }
};