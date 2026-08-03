class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        int s=0,e=n-1;
        int ans=-1;
        
        while(s<=e){
            int m=s+(e-s)/2;
            if(arr[m]<=x){
                ans=m;
                s=m+1;
            }else{
                e=m-1;
            }
        }
        return ans;
    }
};
