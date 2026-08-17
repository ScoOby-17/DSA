class Solution {
public:
    string solve(string& s , int& i){
        string res = "";

        while(i<s.length() && s[i]!=']'){
            if(isdigit(s[i])){
                string number="";
                while(i<s.length() && s[i]!='['){
                    number.push_back(s[i]);
                    i++;
                }
                int num = stoi(number);
                i++; //skip [
                string decode = solve(s,i);
                i++; //skip ]

                for(int j=0;j<num;j++){
                    res += decode;
                }
            }else{
                res.push_back(s[i]);
                i++;
            }
        }

        return res;
    }
    string decodeString(string s) {
        int i=0;
        string ans = solve(s,i);
        return ans;
    }
};