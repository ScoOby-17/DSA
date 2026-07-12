class Solution {
public:
    void solve(vector<int>& nums , int n , map<int,int> &mp , vector<int>&combination , vector<vector<int>>&ans){
        if(combination.size() == n){
            ans.push_back(combination);
            return;
        }

        for(auto&[num,freq] : mp){
            if(freq == 0) continue;

            combination.push_back(num);
            mp[num]--;
            solve(nums, n, mp, combination, ans);
            combination.pop_back();
            mp[num]++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size()    ;
        map<int,int>mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        vector<int>combination;
        vector<vector<int>>ans;
        solve(nums , n , mp , combination , ans);

        return ans;
    }
};