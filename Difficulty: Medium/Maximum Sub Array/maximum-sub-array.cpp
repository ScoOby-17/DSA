class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        // code here
        vector<int>ans;
        int sum=0;
        int maxSum = 0;
        vector<int>subArr;
        
        bool isAllNeg = true;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i] < 0){
                sum = 0;
                subArr.clear();
                continue;
            }
            
            isAllNeg = false;
            
            sum += arr[i];
            subArr.push_back(arr[i]);
            
            if(sum > maxSum ||  (sum == maxSum && subArr.size() > ans.size())){
                ans = subArr;
                maxSum = sum;
            }
        }
        
        if(isAllNeg) return {-1};
        
        return ans;
    }
};