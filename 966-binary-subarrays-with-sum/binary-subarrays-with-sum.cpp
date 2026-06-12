class Solution {
public:
    int subArraySmallOrEqualsGoal(vector<int>& nums, int goal){
        if(goal < 0) return 0; //Edge Case

        int count=0;
        int n=nums.size();
        int l=0,r=0;
        int sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum -= nums[l];
                l++;
            }
            int subArraysSmallThenSum = r-l+1;
            count += subArraysSmallThenSum;
            r++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int subArraySumLessOrEqualToGoal = subArraySmallOrEqualsGoal(nums,goal);
        int subArraySumLessOrEqualToGoalMinus1 = subArraySmallOrEqualsGoal(nums,goal-1);
        int count = subArraySumLessOrEqualToGoal - subArraySumLessOrEqualToGoalMinus1;
        return count;
    }
};