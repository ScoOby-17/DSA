class Solution {
public:
    int maxProduct(int n) {
        string val = to_string(n);
        sort(val.begin(),val.end());
        int ans = INT_MIN;
        int size = val.length();
        ans = (val[size-1]-'0') * (val[size-2]-'0');
        return ans;
    }
};