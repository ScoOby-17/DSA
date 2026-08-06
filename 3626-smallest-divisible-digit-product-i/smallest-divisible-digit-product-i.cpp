class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int c = n;
            int product = 1;
            while(c){
                int last = c%10;
                c /= 10;
                product *= last;
            }
            if(product%t == 0) return n;
            n++;
        }
        return -1; //never reach here
    }
};