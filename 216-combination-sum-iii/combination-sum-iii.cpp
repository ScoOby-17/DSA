class Solution {
public: 
    void genValidCombinations(int k , int n , vector<vector<int>>& ans , vector<int>& combinations , vector<int>& arr , int idx){
        if(n == 0 && combinations.size() == k){
            ans.push_back(combinations);
            return;
        }
        if(combinations.size() == k || idx == arr.size() || n < 0) return;
        
        //include case
        combinations.push_back(arr[idx]);
        genValidCombinations(k , n-arr[idx] , ans , combinations , arr , idx+1);
        //exclude case
        combinations.pop_back(); //backtrack
        genValidCombinations(k , n , ans , combinations , arr , idx+1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>combinations;
        vector<int>arr = {1,2,3,4,5,6,7,8,9};
        genValidCombinations(k , n , ans , combinations , arr , 0);
        return ans;
    }
};