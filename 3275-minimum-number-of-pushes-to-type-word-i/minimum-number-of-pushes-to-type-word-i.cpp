class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        if(n<9)return n;

        int count = 0;
        vector<string>v = {"" , "" , "" , "" , "" , "" , "" , "" , "" , ""};
        //    index --->   0    1    2    3    4    5    6    7    8    9

        int idx = 2;
        for(int i=0;i<n;i++){
            v[idx].push_back(word[i]);
            count += v[idx].length();
            idx++;
            if(idx == 10) idx = 2;
        }

        return count;
    }
};