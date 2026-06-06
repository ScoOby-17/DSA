class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int first=intervals[0][0];
        int second=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            vector<int>row = intervals[i];
            if(second>=row[0]){
                second = max(second, row[1]);
            }else{
                vector<int>ansRow = {first,second};
                ans.push_back(ansRow);
                first = row[0];
                second = row[1];
            }
        }
        ans.push_back({first,second});
        return ans;
    }
};