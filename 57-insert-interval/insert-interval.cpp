class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());

        //Merge Interval same
        vector<vector<int>>ans;
        int start=intervals[0][0];
        int end=intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            vector<int>row = intervals[i];
            if(end >= row[0]){
                end = max(row[1],end);
                continue;
            }else{
                ans.push_back({start,end});
                start = row[0],end=row[1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};