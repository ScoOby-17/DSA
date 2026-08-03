class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        int s=0,e=n-1;
        int ans=-1;
        
        while(s<=e){
            int m=s+(e-s)/2;
            if(arr[m]>=x){
                ans=m;
                e=m-1;
            }else{
                s=m+1;
            }
        }
        return ans;
    }
};