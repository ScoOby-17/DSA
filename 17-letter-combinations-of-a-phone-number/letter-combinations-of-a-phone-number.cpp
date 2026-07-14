class Solution {
public: 
    void solve(string& digits , string& str , int idx , vector<string>& mp , vector<string>& ans){
        if(idx == digits.size()){
            ans.push_back(str);
            return;
        }

        string chars = mp[digits[idx]-'0'];
        for(char c : chars){
            str.push_back(c);
            solve(digits , str , idx+1 , mp , ans);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string str = "";
        vector<string>ans;
        vector<string>mp = {"" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
        solve(digits , str , 0 , mp , ans);

        return ans;
    }
};