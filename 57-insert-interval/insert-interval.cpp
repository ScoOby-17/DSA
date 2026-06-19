class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());

        int prevEnd = intervals[0][1];
        int prevStart = intervals[0][0];

        for(int i=1;i<intervals.size();i++){
            if(prevEnd < intervals[i][0]){
                ans.push_back({prevStart , prevEnd});
                prevStart = intervals[i][0];
                prevEnd = intervals[i][1];
            }
            if(prevEnd >= intervals[i][0]){
                prevEnd = max(intervals[i][1] , prevEnd);
            }
        }
        ans.push_back({prevStart , prevEnd});
        return ans;
    }
};