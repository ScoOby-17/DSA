class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int totalIntervals =intervals.size();
        //sort on bases on end of interval [i][1]  
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];  
        });

        int nonOverlappingCount = 1;
        int lastSelectedEnd = intervals[0][1];

        for(int i=1;i<totalIntervals;i++){

            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];

            if(currentStart >= lastSelectedEnd){
                nonOverlappingCount++;
                lastSelectedEnd = currentEnd;
            }

        }
        int intervalsToRemove = totalIntervals - nonOverlappingCount;
        return intervalsToRemove ;
    }
};