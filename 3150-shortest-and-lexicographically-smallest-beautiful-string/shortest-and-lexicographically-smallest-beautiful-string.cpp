class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int ones = 0;
        int n=s.length();
        int l=0;

        for(int r=0;r<n;r++){
            if(s[r]=='1'){
                ones++;
            }

            while(ones == k && l<=r){
                int size = r-l+1;
                string candidate = s.substr(l,size);
                if(ans.length()>size || ans.empty() || 
                        (size == ans.length() && candidate < ans)){
                    ans = candidate;
                }
                if(s[l]=='1') ones--;
                l++;
            }
        }

        return ans;
    }
};