class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxV = INT_MIN;
        int minV = INT_MAX;
        
        for(int i=0;i<nums.size();i++){
            maxV = max(maxV , nums[i]);
            minV = min(minV , nums[i]);
        }

        return __gcd(maxV , minV);
    }
};