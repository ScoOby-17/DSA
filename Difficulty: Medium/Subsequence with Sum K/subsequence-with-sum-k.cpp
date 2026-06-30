class Solution {
  public:
    void checkArr(vector<int>& arr, int k , int idx ,bool& isSumEqualToK){
        if(k==0){
             isSumEqualToK = 1;
             return;
        };
        if(k < 0 || arr.size() == idx) return;
        if(isSumEqualToK) return;
        
        //include case
        checkArr(arr , k-arr[idx] , idx+1 , isSumEqualToK);
        checkArr(arr , k, idx+1 , isSumEqualToK);
    }
    
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        // Code here
        bool isSumEqualToK = false;
        checkArr(arr , k , 0 ,isSumEqualToK);
        return isSumEqualToK;
    }
};