class Solution {
public:
    void solve(vector<int>&arr , unordered_map<int,bool>&mp , string& s ,unordered_set<int>& uniquesVal){
        if(s.length()==3){
            int num = stoi(s);
            if(num%2==0) uniquesVal.insert(num); return;
        }

        for(int i=0;i<arr.size();i++){
            if(mp[i] == false){
                if(s.empty() && arr[i] == 0) continue; // for handel zero in start 

                s.push_back(arr[i]+'0');
                mp[i] = true;
                solve(arr , mp , s , uniquesVal);
                mp[i] = false;
                s.pop_back();
            }
        }
    }
    
    int totalNumbers(vector<int>& digits) {
        string s ="";
        unordered_set<int>uniquesVal;
        unordered_map<int,bool>mp;
        solve(digits , mp , s ,uniquesVal);
        return uniquesVal.size();
    }
};