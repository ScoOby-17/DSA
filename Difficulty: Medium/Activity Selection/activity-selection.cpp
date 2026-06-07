class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<vector<int>>arr;
        int maxActivity=1;
        for(int i=0;i<start.size();i++){
            arr.push_back({start[i],finish[i]});
        }
        sort(arr.begin(),arr.end(), [](vector<int>&a , vector<int>&b){
            return a[1]<b[1];
        });
        
        int prevEnd = arr[0][1];
        for(int i=1;i<arr.size();i++){
            if(prevEnd<arr[i][0]){
                maxActivity++;
                prevEnd = arr[i][1];
            }
        }
        return maxActivity;
    }
};