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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>critIdx;
        ListNode* prev = head;
        head = head->next;
        int idx = 1;

        while(head->next){ // conditon of possible critical point
            bool isMaxima = head->val > prev->val && head->val > head->next->val;
            bool isMinima = head->val < prev->val && head->val < head->next->val;
            if(isMaxima || isMinima){
                critIdx.push_back(idx);
                // cout<< idx << " ";
            }
            idx++;
            prev = head;  head = head->next;
        }

        if(critIdx.empty()) return {-1,-1};
        // Note: critIdx array is always sorted
        int n = critIdx.size();
        if(n==1) return {-1,-1};
        int minDist = critIdx[n-1]-critIdx[0];
        int maxDist = critIdx[n-1]-critIdx[0];

        for(int i=1;i<n;i++){
            minDist = min(minDist , critIdx[i]-critIdx[i-1]);
        }

        return {minDist , maxDist};
    }
};