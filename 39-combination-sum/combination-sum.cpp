class Solution {
public:
    set<vector<int>>s;
    void genCombination(vector<int>& arr , vector<int>combination , int target , int i , vector<vector<int>> &ans){
        //base cases
        if(target < 0 || i == arr.size()) return;
        if(target == 0){
            ans.push_back(combination);
            return;
        }

        combination.push_back(arr[i]);
        // genCombination(arr , combination , target-arr[i] , i+1 , ans); //include one time
        genCombination(arr , combination , target-arr[i] , i , ans); //include many time
        combination.pop_back(); //backtrack
        genCombination(arr , combination , target , i+1 , ans); //exclude case
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>combination;
        genCombination(candidates , combination , target , 0 , ans);
        return ans;
    }
};