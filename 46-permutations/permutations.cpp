class Solution {
public:
    void genPermutations(vector<int>& nums , vector<int>& arr , vector<bool>mp , vector<vector<int>>&ans){
        if(arr.size() == nums.size()){
            ans.push_back(arr);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(mp[i] == false){
                arr.push_back(nums[i]);
                mp[i]=true;
                genPermutations(nums , arr , mp , ans);
                arr.pop_back();
                mp[i]=false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>arr;
        int n=nums.size();
        vector<bool>mp(n,false);
        vector<vector<int>>ans;
        genPermutations(nums , arr , mp , ans);

        return ans;
    }
};