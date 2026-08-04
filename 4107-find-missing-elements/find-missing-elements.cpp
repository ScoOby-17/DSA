class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<bool>v(101,false);
        int minV = INT_MAX;
        int maxV = INT_MIN;
        int n = nums.size();
        vector<int>ans;

        for(int i=0;i<n;i++){
            minV = min(minV , nums[i]);
            maxV = max(maxV , nums[i]);
            v[nums[i]] = true;
        }

        for(int i=minV;i<maxV;i++){
            if(v[i] == false) ans.push_back(i);
        }

        return ans;
    }
};