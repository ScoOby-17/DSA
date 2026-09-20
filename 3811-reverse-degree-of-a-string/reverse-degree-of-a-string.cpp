class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char,int>m;
        char c = 'z';
        for(int i=1;i<27;i++){
            m[c] = i;
            // cout<<c<<endl;
            c--;
        }

        int ans = 0;
        for(int i=0;i<s.length();i++){
            ans += m[s[i]] * (i+1);
        }

        return ans;
    }
};