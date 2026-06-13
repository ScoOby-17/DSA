class Solution {
public:
    string encoded(string s){
        unordered_map<char,int>mp;
        string str="";
        int counter = 1;

        for(int i=0;i<s.length();i++){
            if(!mp.count(s[i])){
                mp[s[i]] = counter++;
            }
            str += to_string(mp[s[i]]) + ",";
        }

        return str;
    }
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        return encoded(s) == encoded(t);
    }
};