class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n ==0 ) return 0;
        string str = to_string(n);
        string newStr = "";
        int sum = 0;
        for(int i=0;i<str.length();i++){
            if(str[i] != '0'){
                newStr.push_back(str[i]);
                sum += str[i] - '0';
            }
        }

        long long ans = stoll(newStr) * sum;
        return ans;
    }
};