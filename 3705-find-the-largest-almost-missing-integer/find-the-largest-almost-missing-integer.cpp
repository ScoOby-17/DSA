class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int ans = -1;
        int n=nums.size();

        unordered_map<int,int>mp;

        for(int i=0;i<n-k+1;i++){
            set<int>windowSet;  //for handle duplicate

            for(int j=i;j<i+k;j++){
                windowSet.insert(nums[j]);
            }

            for(auto val : windowSet){
                mp[val]++;
            }
        }

        for(auto& it : mp){
            if(it.second == 1){
                ans = max(it.first , ans);
            }
        }

        return ans;
    }
};