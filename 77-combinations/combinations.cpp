class Solution {
public:
    vector<vector<int>>ans;
    void generateCombinations(vector<int> &combination , int curr , int n , int k){
        if(combination.size() == k){
            ans.push_back(combination);
            return;
        }else if(n < curr){ return; }

        combination.push_back(curr);
        generateCombinations(combination , curr+1 , n , k);
        combination.pop_back();
        generateCombinations(combination , curr+1 , n , k);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> combination;
        int curr = 1;
        generateCombinations(combination,curr,n,k);
        return ans;
    }
};