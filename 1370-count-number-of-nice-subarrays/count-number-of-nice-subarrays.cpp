class Solution {
public:
    int oddSubArrays(vector<int>& nums, int k){
        if(k<0) return 0;

        int n=nums.size();
        int l=0,r=0;
        int count=0;
        int oddValCount=0;
        while(r<n){
            if(nums[r]%2 == 1) oddValCount++;

            while(oddValCount > k){
                if(nums[l]%2 == 1) oddValCount--;
                l++;
            }

            int subArrays = r-l+1;
            count += subArrays;
            r++;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int subArraySumLessOrEqualTo_K = oddSubArrays(nums,k);
        int subArraySumLessOrEqualTo_K_minusOne = oddSubArrays(nums,k-1);

        int niceSubArrays = subArraySumLessOrEqualTo_K - subArraySumLessOrEqualTo_K_minusOne;
        return niceSubArrays;
    }
};