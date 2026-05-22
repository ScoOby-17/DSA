class Solution {
public:
    int reachNumber(int target) {
        int move = 0;
        int sum=0;
        target = abs(target);
        while(1){
            move++;
            sum+=move;
            if(sum>=target && (sum-target)%2 == 0){
                return move;
            }
        }
        return move;
    }
};