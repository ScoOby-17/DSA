class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd=1;
        int even=2;
        int nextOdd = 3;
        int nextEven = 4;
        for(int i=1;i<n;i++){
            odd += nextOdd;
            even += nextEven;
            nextOdd += 2;
            nextEven += 2;
        }

        int ans = __gcd(odd , even); //inbuild fn in cpp
        return ans;
    }
};