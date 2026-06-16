class Solution {
public:
    string processStr(string s) {
        string str = "";
        for(int i=0;i<s.length();i++){
            if(s[i] != '*' && s[i] != '#' && s[i] != '%'){
                str.push_back(s[i]);
            }else if(s[i] == '*'){
                if(str.length() > 0) str.pop_back();
            }else if(s[i] == '#'){
                str += str;
            }else if(s[i] == '%'){
                reverse(str.begin(),str.end());
            }
        }

        return str;
    }
};