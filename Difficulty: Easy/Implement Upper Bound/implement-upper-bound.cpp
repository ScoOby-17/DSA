class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int ans=n;
        int s = 0,e= n-1;
        while(s<=e){
            int m = s+(e-s)/2;
            if(arr[m] > target){
                ans=m;
                e=m-1;
            }else{
                s=m+1;
            }
        }
        return ans;
    }
};
