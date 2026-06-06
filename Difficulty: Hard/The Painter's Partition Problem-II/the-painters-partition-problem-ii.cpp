class Solution {
  public:
    bool  checkPaint(vector<int>& arr, int k ,int paintCapacity){
        int painted=0;
        int painterNeed=1;
        for(int i=0;i<arr.size();i++){
            if(painted+arr[i] <= paintCapacity){
                painted+=arr[i];
            }else{
                painterNeed++;
                painted=arr[i];
            }
        }
        if(painterNeed<=k) return 1;
        return 0;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int s=0;
        int e=0;
        for(int i=0;i<arr.size();i++){
            s=max(arr[i],s);
            e+=arr[i];
        }
        
        int ans=0;
        
        while(s<=e){
            int m=s+(e-s)/2;
            bool canPaint = checkPaint(arr,k,m);
            if(canPaint){
                ans=m;
                e=m-1;
            }else{
                s=m+1;
            }
        }
        
        return ans;
    }
};