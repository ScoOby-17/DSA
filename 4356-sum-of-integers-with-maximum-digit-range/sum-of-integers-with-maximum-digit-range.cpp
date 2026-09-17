class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxRange = INT_MIN;
        for(int i=0;i<nums.size();i++){
            string s = to_string(nums[i]);
            int maxV = INT_MIN; int minV = INT_MAX;
            for(int j=0;j<s.length();j++){
                int val = s[j]-'0';
                maxV = max(maxV , val);
                minV = min(minV , val);
            }
            int diff = maxV-minV;
            maxRange = max(maxRange , diff);
        }

        int ans = 0;
        for(int i=0;i<nums.size();i++){
            string s = to_string(nums[i]);
            int maxV = INT_MIN; int minV = INT_MAX;
            for(int j=0;j<s.length();j++){
                int val = s[j]-'0';
                maxV = max(maxV , val);
                minV = min(minV , val);
            }
            int diff = maxV-minV;
            if(diff == maxRange) ans += nums[i];
        }

        return ans;
    }
};