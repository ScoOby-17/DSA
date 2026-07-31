class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        int n = word.size();
        int count = 0;
        if(n < 9) return n;

        //maping each char frequency
        for(int i=0;i<n;i++){
            mp[word[i]]++;
        }

        //sort on basis or frequency
        vector<pair<char,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end() , [](auto& a , auto& b){
            if(a.second == b.second) return a.first < b.first;  //same freq → char order
            return a.second > b.second;                         //freq descending
        });

        int charMaped = 0;
        int tap = 1;
        
        for(int i=0;i<v.size();i++){
            pair<char,int>p = v[i];
            count += p.second * tap;
            charMaped++;
            if(charMaped % 8 == 0  && charMaped > 0) tap++;
        }

        return count;
    }
};