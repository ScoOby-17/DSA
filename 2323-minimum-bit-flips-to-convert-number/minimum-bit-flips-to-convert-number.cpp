class Solution {
public:
    int minBitFlips(int start, int goal) {
        string binaryS = bitset<32>(start).to_string();
        string binaryG = bitset<32>(goal).to_string();
        int count = 0;
        for(int i=0;i<binaryS.length();i++){
            if(binaryS[i]!=binaryG[i]) count++;
        }
        return count;
    }
};