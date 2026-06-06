class Solution {
public:
    bool checkSplit(vector<int>& nums, int k, int possibleSum){
        int sum=0;
        int subArr=1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=possibleSum){
                sum+=nums[i];
            }else{
                subArr++;
                sum=nums[i];
            }
        }
        if(subArr <= k) return 1;
        return 0;
    }
    int splitArray(vector<int>& nums, int k) {
        int s=0;
        int e=0;
        for(int i=0;i<nums.size();i++){
            s=max(s,nums[i]);
            e+=nums[i];
        }
        int ans=0;
        while(s<=e){
            int m=s+(e-s)/2;
            bool canSplit = checkSplit(nums,k,m);
            if(canSplit){
                e=m-1;
                ans=m;
            }else{
                s=m+1;
            }
        }
        return ans;
    }
};