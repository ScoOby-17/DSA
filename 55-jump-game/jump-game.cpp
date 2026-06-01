class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx = 0;
        for(int i=0;i<nums.size();i++){
            if(i>maxIdx) return false;
            int idxReach =nums[i] + i;
            if(idxReach > maxIdx) maxIdx = idxReach;
        }
        return true;
    }
};