class Solution {
  public:
    void getPowerSets(string &s , string &combination , int idx , vector<string>& ans){
        if(idx == s.length()){
            ans.push_back(combination);
            return ;
        }
        
        //include
        combination.push_back(s[idx]);
        getPowerSets(s , combination , idx+1 , ans);
        //exclude
        combination.pop_back();
        getPowerSets(s , combination , idx+1 , ans);
    }
    vector<string> powerSet(string &s) {
        // Code here
        string combination = "";
        vector<string>ans;
        getPowerSets(s , combination , 0 , ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};