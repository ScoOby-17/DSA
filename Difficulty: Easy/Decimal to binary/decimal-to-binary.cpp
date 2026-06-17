class Solution {
  public:
    string decToBinary(int n) {
        // code here
        string s="";
        while(n){
            s.push_back(n%2 + '0');
            n/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};