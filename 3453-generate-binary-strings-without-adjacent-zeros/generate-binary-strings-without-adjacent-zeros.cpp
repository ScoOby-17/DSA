class Solution {
public:
    void generateBinaryStr(int &n , string &str , vector<string> &ans){
        if(str.length() == n){
            ans.push_back(str);
            return;
        }
        //add 1 always
        str.push_back('1');
        generateBinaryStr(n,str,ans);
        str.pop_back();

        //add 0 id contition true
        if(str.empty() || str.back() == '1'){
            str.push_back('0');
            generateBinaryStr(n,str,ans);
            str.pop_back();
        }
    }

    vector<string> validStrings(int n) {
        vector<string>ans;
        string str="";
        generateBinaryStr(n,str,ans);
        return ans;
    }
};