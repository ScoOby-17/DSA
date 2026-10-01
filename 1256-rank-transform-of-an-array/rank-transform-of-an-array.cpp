class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int , vector<int>>mp;
        long long prev = LLONG_MIN;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }

        int rank=1;
        vector<int>ans(arr.size(),0);
        
        for(auto& it:mp){
            for(int& val : it.second){
                ans[val] = rank;
            }
            rank++;
        }

        return ans;
    }
};