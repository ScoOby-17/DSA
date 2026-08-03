class Solution {
  public:
    int countFreq(vector<int>& arr, int x) {
        // code here
        vector<int>ans = {-1,-1};
        int n=arr.size();
        int s=0,e=n-1;
        
        //firstOccurance
        while(s<=e){
            int m=s+(e-s)/2;
            if(arr[m]==x){
                ans[0]=m;
                e=m-1;
            }else if(arr[m]>x){
                e=m-1;
            }else{
                s=m+1;
            }
        }
        
        //lastOccurance
        s=0,e=n-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(arr[m]==x){
                ans[1]=m;
                s=m+1;
            }else if(arr[m]<x){
                s=m+1;
            }else{
                e=m-1;
            }
        }
        
        if (ans[0] == -1) return 0;
             
        int noOfOccurance = ans[1]-ans[0]+1;
        
        return noOfOccurance;
    }
};
