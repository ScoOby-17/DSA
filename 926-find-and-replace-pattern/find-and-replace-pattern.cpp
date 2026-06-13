class Solution {
public:
    string patternEncoded(string s){
        string str="";
        unordered_map<char,int>mp;
        int counter=0;

        for(int i=0;i<s.length();i++){
            if(!mp.count(s[i])){
                mp[s[i]] = counter;
                counter++;
            }
            str += to_string(mp[s[i]]) + ",";
        }

        return str;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        string encodedPattern = patternEncoded(pattern);

        for(int i=0;i<words.size();i++){
            string encodedWord = patternEncoded(words[i]);
            if(encodedWord == encodedPattern) ans.push_back(words[i]);
        }

        return ans;
    }
};