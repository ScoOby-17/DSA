class Solution {
public:
    void solve(string& s , int index ,vector<string>& path , vector<vector<string>>&ans){
        if(index == s.length()) { ans.push_back(path); return; }
        
        for(int i=index;i<s.length();i++){
            bool isPalindrome = CheckPalindrome(s , index , i);
            if(isPalindrome){          //startIDx   //length
                path.push_back(s.substr(index , i - index + 1));
                solve(s , i+1 , path , ans);
                path.pop_back();
            }
        }
    }

    bool CheckPalindrome(string& str , int s , int e){
        while(s<e){
            if(str[s] == str[e]) s++ ,e--;
            else return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<string>path;
        vector<vector<string>>ans;
        solve(s , 0 , path , ans);
        return ans;
    }
};