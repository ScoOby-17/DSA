class Solution {
public:
    set<vector<int>>s;
    void genCombination(vector<int>& arr , vector<int>combination , int target , int i){
        //base cases
        if(target < 0 || i == arr.size()) return;
        if(target == 0){
            s.insert(combination);
            return;
        }

        combination.push_back(arr[i]);
        genCombination(arr , combination , target-arr[i] , i+1); //include one time
        genCombination(arr , combination , target-arr[i] , i); //include many time
        combination.pop_back(); //backtrack
        genCombination(arr , combination , target , i+1); //exclude case
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>combination;
        genCombination(candidates , combination , target , 0);
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};