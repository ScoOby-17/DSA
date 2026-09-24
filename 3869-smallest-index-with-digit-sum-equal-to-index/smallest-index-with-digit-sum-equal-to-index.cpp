class Solution {
public:
    int digitSum(int val){
        int sum=0;
        while(val){
            int last = val%10;
            sum+=last;
            val/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int sum = digitSum(nums[i]);
            if(sum == i) return i;
        }
        return -1;
    }
};