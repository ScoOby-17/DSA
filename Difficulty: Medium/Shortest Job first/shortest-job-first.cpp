class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        int currWaitingTime = 0;
        int totalWaitingTime = 0;
        int n=bt.size();
        
        for(int i=0;i<n;i++){
            totalWaitingTime += currWaitingTime;
            currWaitingTime += bt[i];
        }
        
        return totalWaitingTime/n;
    }
};