class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int sum = nums[0];
        int i=1;
        while(i<n){
            if(nums[i-1] == nums[i]-1){
                sum += nums[i];
                i++;
                continue;
            }
            break;
        }

        unordered_map<int , bool>mp;
        i=0;
        while(i<n){
            mp[nums[i]] = true;
            i++;
        }

        while(mp[sum] == true){
            if(mp[sum]){
                sum++;
            }
        }

        return sum;
    }
};