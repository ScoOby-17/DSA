class Solution {
public:
    void generateAll(int &n ,int s ,int e ,string &str ,vector<string> &ans){
        //base case
        if(str.length() == 2*n){
            ans.push_back(str);
            return;
        }
        //add "("
        if(s<n){
            str.push_back('(');
            generateAll(n, s+1, e, str, ans);
            str.pop_back(); //backtrack
        }
        if(e<s){
            str.push_back(')');
            generateAll(n, s, e+1, str, ans);
            str.pop_back(); //backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str="";
        generateAll(n,0,0,str,ans);
        return ans;
    }
};