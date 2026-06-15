class Solution {
public:
    int allPossibleSubArraysCountLessThan_k_elements(vector<int>& nums, int k){
        int count = 0;
        int n=nums.size();
        int l=0,r=0;
        unordered_map<int,int>mp;
        while(r<n){
            mp[nums[r]]++;
            
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }

            count += r-l+1;
            r++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = allPossibleSubArraysCountLessThan_k_elements(nums , k) - allPossibleSubArraysCountLessThan_k_elements(nums , k-1);
        return ans;
    }
};