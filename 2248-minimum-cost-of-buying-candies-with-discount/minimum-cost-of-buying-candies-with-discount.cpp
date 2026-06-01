class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int totalCost = 0;
        int buy = 0;
        for(int i = cost.size()-1;i>=0;i--){
            if(buy == 2){
                buy=0;
                continue;
            }
            totalCost+=cost[i];
            buy++;
        }
        return totalCost;
    }
};