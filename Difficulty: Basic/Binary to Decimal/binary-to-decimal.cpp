class Solution {
  public:
    int binaryToDecimal(string& b) {
        // code here
        long long pow2 = 1;
        int ans=0;
        for(int i=b.length()-1;i>=0;i--){
            if(b[i] == '1')ans+=pow2;
            pow2 *= 2;
        }
        return ans;
    }
};