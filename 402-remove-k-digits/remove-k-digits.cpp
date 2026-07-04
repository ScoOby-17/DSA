class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;
        int n = num.length();

        for(int i=0;i<n;i++){
            while(!s.empty() && s.top()-'0' > num[i]-'0' && k>0){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(k>0){
            s.pop();
            k--;
        }

        if(s.empty()) return "0";

        string val="";
        while(!s.empty()){
            val.push_back(s.top());
            s.pop();
        }

        reverse(val.begin(),val.end());

        int start=0;
        while(start < val.size()-1 && val[start] == '0'){
            start++;
        }

        val= val.substr(start);
        return val;
    }
};