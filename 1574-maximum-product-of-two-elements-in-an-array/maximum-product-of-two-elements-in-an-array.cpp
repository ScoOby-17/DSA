class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int fst = INT_MIN;
        int sec = INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int curr = nums[i];
            if(curr > fst){
                sec = fst;
                fst = curr;
            }else if(curr <= fst && curr > sec){
                sec = curr;
            }
        }

        return (fst-1) * (sec-1);
    }
};