class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>prefixMax(n);
        vector<int>suffixMax(n);
        int pMax=0,sMax=0;
        int unitCount = 0;

        //prefix max
        for(int i=0;i<n;i++){
            pMax = max(pMax , height[i]);
            prefixMax[i] = pMax;
        }
        //suffix max
        for(int i=n-1;i>=0;i--){
            sMax = max(sMax,height[i]);
            suffixMax[i] = sMax;
        }

        for(int i=1;i<n-1;i++){
            if(height[i] < prefixMax[i-1] && height[i] < suffixMax[i+1]){
                int units = min(prefixMax[i-1] , suffixMax[i+1]) - height[i];
                unitCount += units;
            }
        }

        return unitCount;
    }
};