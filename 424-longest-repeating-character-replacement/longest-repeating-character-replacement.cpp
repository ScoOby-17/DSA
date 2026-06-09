class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0;
        int n=s.length();
        int maxFreq=0;
        int maxLength=0;
        unordered_map<char,int>mp;

        while(r<n){

            mp[s[r]]++;
            maxFreq = max(maxFreq , mp[s[r]]);
            int length = r-l+1;
            int replacmentNeedd = length-maxFreq;

            if(replacmentNeedd<=k){

                maxLength=max(length,maxLength);

            }else{
                while(replacmentNeedd>k){
                    mp[s[l]]--;
                    l++;
                    maxFreq=0;

                    for(auto it : mp){
                        maxFreq = max(maxFreq,it.second);
                    }

                    length = r-l+1;
                    replacmentNeedd = length-maxFreq;
                }
            }
            r++;
        }

        return maxLength;
    }
};