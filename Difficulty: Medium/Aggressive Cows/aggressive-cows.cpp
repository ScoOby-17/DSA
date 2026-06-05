class Solution {
  public:
    bool isPlace(vector<int> &stalls, int k, int dist){
        int last=stalls[0];
        int cows=1;
        
        for(int i=0;i<stalls.size();i++){
            if(stalls[i]-last >= dist){
                cows++;
                last = stalls[i];
            }
        }
        if(cows>=k) return 1;
        return 0;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int s=1;
        int n=stalls.size();
        int e=stalls[n-1]-stalls[0];
        int ans=1;
        while(s<=e){
            int m=s+(e-s)/2;
            bool isPlaceAtDistanceM = isPlace(stalls,k,m);
            if(isPlaceAtDistanceM){
                s=m+1;
                ans=m;
            }else{
                e=m-1;
            }
        }
        return ans;
    }
};