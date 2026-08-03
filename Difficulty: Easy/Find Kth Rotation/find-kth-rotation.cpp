class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int s=0;
        int n=arr.size();
        int e=n-1;
        
        while(s<e){
            int m=s+(e-s)/2;
            if(arr[m]>arr[e]){
                s=m+1;
            }else{
                e=m;
            }
        }
        
        return s;
    }
};
