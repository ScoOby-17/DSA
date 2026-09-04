class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxVal = INT_MIN;
        int minVal = INT_MAX;

        for(int i=0;i<nums.size();i++){
            maxVal = max(maxVal , nums[i]);
            minVal = INT_MAX;
            for(int j=i;j<nums.size();j++){ 
                minVal = min(minVal , nums[j]); 
            }
            // cout<<maxVal << " " << minVal << endl;
            int diff = maxVal - minVal;
            if(diff <= k) return i;
        }

        return -1;
    }
};