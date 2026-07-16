class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int>gcdArr;
        int maxVal = nums[0];

        for(int i=0;i<nums.size();i++){
            maxVal = max(maxVal , nums[i]);
            gcdArr.push_back(__gcd(nums[i] , maxVal));
        }

        sort(gcdArr.begin(),gcdArr.end());

        int i=0,j=gcdArr.size()-1;
        long long ans = 0;

        while(i<j){
            ans += __gcd(gcdArr[i] , gcdArr[j]);
            i++,j--;
        }

        return ans;
    }
};