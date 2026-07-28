class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        map<char,int>mp;
        string ans = "";
        bool oddFreqCharOccure = false;
        char oddFreqChar;

        //build frequency map
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
 
        //build first half
        for(auto it : mp){
            char c = it.first;
            int freq = it.second;

            if(freq %2 == 1){ //odd freq char is this
                oddFreqCharOccure = true;
                oddFreqChar = c;
            }

            for(int i=0;i<freq/2;i++){
                ans.push_back(c);
            }
        }

        string tmp = ans;
        if(oddFreqCharOccure){
            ans.push_back(oddFreqChar);
        }

        reverse(tmp.begin(),tmp.end());

        ans += tmp;
        return ans;
    }
};