class Solution {
public:
    vector<int>nseFn(vector<int>&arr){
        int n = arr.size();
        vector<int>ans(n,n);
        stack<int>s;

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>= arr[i]){
                s.pop();
            }

            if(!s.empty()){
                ans[i] = s.top();
            }

            s.push(i);
        }

        return ans;
    }

    vector<int>pseFn(vector<int>&arr){
        int n = arr.size();
        vector<int>ans(n,-1);
        stack<int>s;

        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>= arr[i]){
                s.pop();
            }

            if(!s.empty()){
                ans[i] = s.top();
            }

            s.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int>pse = pseFn(heights);
        vector<int>nse = nseFn(heights);

        int ans = 0;

        for(int i=0;i<heights.size();i++){
            int width = nse[i]-pse[i]-1;
            int area = heights[i] * width;
            ans = max(area , ans);
        }

        return ans;
    }

    
};