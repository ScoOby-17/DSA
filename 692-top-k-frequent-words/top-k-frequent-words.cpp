class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int>mp;

        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }

        struct Cmp{
            bool operator()(const pair<string,int>& a , const pair<string,int>& b) const {
                if(a.second != b.second) return a.second < b.second; //map heap on bases of frequency
                return a.first > b.first;
            }
        };
        priority_queue<pair<string,int> , vector<pair<string,int>> , Cmp> q(mp.begin(),mp.end());

        vector<string>ans;
        for(int i=0;i<k;i++){
            ans.push_back(q.top().first);
            q.pop();
        }

        return ans;
    }
};