class Solution {
public:
    void totalCount(vector<int>& arr , int idx , int& target , int sum , int &count){
        if(arr.size() == idx && target == sum){
            count++;
            return;
        }else if(arr.size() == idx) return;

        // plus case
        totalCount(arr , idx+1 , target , sum + arr[idx] , count);
        // minus case
        totalCount(arr , idx+1 , target , sum - arr[idx] , count);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        totalCount(nums , 0 , target , 0 , count);
        return count;
    }
};