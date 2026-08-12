class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int l=0;
        int ans = 0;

        for(int r=0;r<nums.size();r++){
            int freq = ++mp[nums[r]];

            while(freq > k){
                mp[nums[l]]--;
                l++;
                freq = mp[nums[r]];
            }

            ans = max(ans , r-l+1);
        }

        return ans;
    }
};