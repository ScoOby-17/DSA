class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxOne=0;
        int zeros=0;
        int l=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]==0){
                zeros++;
            }
            if(zeros<=k){
                int ones=r-l+1;
                maxOne = max(ones,maxOne);
            }else{
                while(zeros>k){
                    if(nums[l]==0) zeros--;
                    l++;
                }
            }
        }
        return maxOne;
    }
};