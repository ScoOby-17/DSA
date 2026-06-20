
class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // code here
        int n = arr.size();
        vector<int>ngeCount(n,0);
        for(int i=0;i<n;i++){
            int curr = arr[i];
            for(int j=i+1;j<n;j++){
                if(arr[j] > curr){
                    ngeCount[i]++;
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<indices.size();i++){
            int idx = indices[i];
            ans.push_back(ngeCount[idx]);
        }
        return ans;
    }
};