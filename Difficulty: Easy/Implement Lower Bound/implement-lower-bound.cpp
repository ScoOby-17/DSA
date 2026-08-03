class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int s=0,e=arr.size()-1;
        int ans=arr.size();
        while(s<=e){
            int m=s+(e-s) /2;
            if(arr[m] >= target){
                ans=m;
                e=m-1;
            }else{
                s=m+1;
            }
        }
        return ans;
    }
};
