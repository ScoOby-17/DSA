class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>leftHighest(n);
        vector<int>rightHighest(n);

        int highest = height[0];
        for(int i=0;i<n;i++){
            highest = max(height[i] , highest);
            leftHighest[i] = highest;
        }

        highest = height[n-1];
        for(int i=n-1;i>=0;i--){
            highest = max(height[i] , highest);
            rightHighest[i] = highest;
        }

        int totalUnits=0;
        for(int i=0;i<n;i++){
            int curr = height[i];
            if(curr < rightHighest[i] && curr < leftHighest[i]){
                int high = min(leftHighest[i] , rightHighest[i]);
                int unit = high - curr;
                totalUnits += unit;
            }
        }

        return totalUnits;
    }
};