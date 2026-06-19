class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currHeight = 0;
        int maxHeight = 0;
        for(int i=0;i<gain.size();i++){
            maxHeight = max(maxHeight , currHeight);
            currHeight += gain[i];
        }
        maxHeight = max(currHeight , maxHeight);
        return maxHeight;
    }
};