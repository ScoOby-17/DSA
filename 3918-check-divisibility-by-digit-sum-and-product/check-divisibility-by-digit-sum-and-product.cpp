class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int pro = 1;
        int copyN = n;
        
        while(copyN){
            int last = copyN % 10;
            sum += last;
            pro *= last;
            copyN /= 10;
        }

        return n % (sum+pro) == 0;
    }
};