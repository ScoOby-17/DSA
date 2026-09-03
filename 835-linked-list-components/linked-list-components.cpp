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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int , bool>mp;
        //mapping
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = true;
        }

        ListNode* tmp = head;
        int component = 0;
        int count = 0;

        while(tmp){
            int data = tmp->val;
            if(mp[data]){
                count++;
            } else {
                if(count) component++;
                count = 0;
            }
            tmp = tmp->next;
        }

        if(count) component++; // check for last component

        return component;
    }
};