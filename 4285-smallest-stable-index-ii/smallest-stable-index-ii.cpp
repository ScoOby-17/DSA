class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>suffixMin(n);
        int maxVal = INT_MIN;

        suffixMin[n-1] = nums[n-1];

        //add value in suiffix array
        for(int i=n-2;i>=0;i--){
            suffixMin[i] = min(nums[i],suffixMin[i+1]);
        }

        for(int i=0;i<n;i++){
            maxVal = max(maxVal , nums[i]);
            int minVal = suffixMin[i];
            int diff = maxVal-minVal;
            if(diff <= k) return i;
        }

        return -1;
    }
};