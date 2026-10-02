class Solution {
public:
    int minSetSize(vector<int>& arr) {

        unordered_map<int , int>mp;
        int n = arr.size();
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }

        struct Cmp{
            bool operator()(const pair<int,int>& a , const pair<int,int>& b) const {
                return a.second < b.second; // max heap on bases of frequency
            }
        };
        priority_queue<pair<int,int> , vector<pair<int,int>> , Cmp> q(mp.begin(),mp.end());

        int count = 0, removed = 0;
        
        while(!q.empty()){
            auto [e , f] = q.top();
            q.pop(); count++;
            removed += f;
            if(n - removed <= n/2) return count;
        }

        return count;
    }
};