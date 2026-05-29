class Solution {
public:
    int minElement(vector<int>& nums) {
        int minVal = INT_MAX;
        for(int i=0;i<nums.size();i++){
            string s = to_string(nums[i]);
            int sum=0;
            for(int j=0;j<s.length();j++){
                sum += s[j]-'0';
            }
            minVal = min(minVal,sum);
        }
        return minVal;
    }
};