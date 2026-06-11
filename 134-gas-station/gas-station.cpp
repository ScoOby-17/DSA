class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int totalGas=0;
        int totalCost=0;
        int fuelInTank=0;

        for(int i=0;i<gas.size();i++){
            totalCost+=cost[i];
            totalGas+=gas[i];
            fuelInTank+=gas[i]-cost[i];
            if(fuelInTank<0){
                start = i+1;
                fuelInTank=0;
            }
        }
        
        if(totalCost>totalGas) return -1;
        return start;
    }
};