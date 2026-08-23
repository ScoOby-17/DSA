class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int start = lower;

        for(int i=0;i<nums.size();i++){
            if(nums[i] < lower || nums[i] > upper){
                continue;
            }

            if(i > 0 && nums[i] == nums[i-1]) continue; //for handle duplicate case

            if(nums[i]!=start){
                ans.push_back({start , nums[i]-1});
            }
            start = nums[i]+1;
        }

        //inset last postion
        if(start <= upper){
            ans.push_back({start , upper});
        }

        return ans;
    }
};