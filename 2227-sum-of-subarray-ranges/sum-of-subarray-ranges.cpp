class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int>nse(n),pse(n),nge(n),pge(n); //in these we store indexs
        stack<int>s;

        //next smallest element
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()] >= nums[i]){
                s.pop();
            }

            nse[i] = s.empty() ? n : s.top();
            s.push(i);
        }
         
        //prev smallest element
        while(!s.empty()) s.pop();
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()] > nums[i]){
                s.pop();
            }

            pse[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        //next greatest element
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()] <= nums[i]){
                s.pop();
            }

            nge[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        //prev greatest element
        while(!s.empty()) s.pop();
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()] < nums[i]){
                s.pop();
            }

            pge[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }


        long long sumOfRange = 0;
        for(int i=0;i<n;i++){
            long long leftSmall = i-pse[i];
            long long rightSmall = nse[i]-i;
            long long leftHigh = i-pge[i];
            long long rightHigh = nge[i]-i;

            sumOfRange += leftHigh * rightHigh * nums[i];
            sumOfRange -= leftSmall * rightSmall * nums[i];
        }

        return sumOfRange;
    }
};