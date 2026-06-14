class Solution {
public:
    bool checkGoodInteger(int n) {
        long long digitSum=0;
        long long squareSum=0;
        while(n){
            int last = n%10;
            n=n/10;
            digitSum+=last;
            squareSum+=last*last;
        }

        int diff = squareSum - digitSum;
        if(diff >= 50) return 1;
        return 0;
    }
};