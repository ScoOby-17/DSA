class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength=0;
        int l=0,r=0;
        int n=s.length();
        unordered_map<char,int>mp;
        while(r < n){
            int length = r-l+1;
            if(!mp.count(s[r]) || l>mp[s[r]] ){
                maxLength = max(maxLength,length);
                mp[s[r]]=r;
            }else{
                l=mp[s[r]]+1;
                mp[s[r]]=r;
            }
            r++;
        }
        return maxLength;
    }
};