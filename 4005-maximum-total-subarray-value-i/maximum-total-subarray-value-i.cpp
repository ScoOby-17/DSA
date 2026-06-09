class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans=0;
        int maxV=INT_MIN;
        int minV=INT_MAX;
        for(int i=0;i<nums.size();i++){
            maxV = max(maxV , nums[i]);
            minV = min(minV , nums[i]);
        }
        ans = 1LL *(maxV-minV) * k;
        return ans;
    }
};