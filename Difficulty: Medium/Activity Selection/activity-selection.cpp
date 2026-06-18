class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<vector<int>>jobs;
        for(int i=0;i<start.size();i++){
            jobs.push_back({start[i],finish[i]});
        }
        
        sort(jobs.begin(),jobs.end(),[](auto &a, auto &b){
            return a[1]<b[1];
        });
        
        int Activity = 1;
        int prevEnd = jobs[0][1];
        for(int i=1;i<jobs.size();i++){
            if(prevEnd < jobs[i][0]){
                Activity++;
                prevEnd = jobs[i][1];
            }
        }
        return Activity;
    }
};