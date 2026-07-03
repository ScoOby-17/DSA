class Solution {
public:
    vector<int>rightSmallestIdx(vector<int>& arr){
        int n = arr.size();
        vector<int>nse(n); //in this we store indexs
        stack<int>s;

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }

            nse[i] = s.empty() ? n : s.top(); //store index
            s.push(i); //insert index in stack
        }

        return nse;
    }
    
    vector<int>leftSmallestIdx(vector<int>& arr){
        int n = arr.size();
        vector<int>pse(n);//in this we store indexs
        stack<int>s;

        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()] > arr[i]){
                s.pop();
            }

            pse[i] = s.empty() ? -1 : s.top(); //store index
            s.push(i); //insert index in stack
        }

        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>pse = leftSmallestIdx(arr);
        vector<int>nse = rightSmallestIdx(arr);

        int sum=0;
        int mod = 1e9 + 7;
        for(int i=0;i<arr.size();i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            sum = (sum + (left * right % mod) * arr[i] % mod) % mod;
        }

        return sum;
    }
};