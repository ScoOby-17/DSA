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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        vector<int>nums;
        ListNode* tmp = head;
        while(tmp!=NULL){
            nums.push_back(tmp->val);
            tmp = tmp->next;
        }
        tmp = head;

        int i=0;
        int n=nums.size();
        int j=1;
        while(j<n){
            swap(nums[i],nums[j]);
            i+=2;
            j+=2;
        }

        i=0;
        while(tmp != NULL){
            tmp->val = nums[i];
            i++;
            tmp = tmp->next;
        }

        return head;
    }
};