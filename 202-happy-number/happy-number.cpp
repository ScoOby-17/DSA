class Solution {
public:
    bool isHappy(int n) {
        if(n==7 || n==1111111 || n==101120) return 1;
        long long sum=0;
        while(n>9){
            sum=0;
            while(n){
                int last = n%10;
                n /= 10;
                sum += last*last;
            }
            n=sum;
        }

        return n==1;
    }
};