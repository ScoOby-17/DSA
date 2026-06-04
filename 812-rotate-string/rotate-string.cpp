class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        s = s+s;
        int n = goal.length();
        for(int i=0;i<n;i++){
            string str = s.substr(i,n);
            if(str == goal) return true;
        }
        return false;
    }
};