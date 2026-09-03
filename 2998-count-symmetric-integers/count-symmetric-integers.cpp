class Solution {
public:
    bool firstAndSecondhalfSum(int val){
        string s = to_string(val);
        if(s.length()%2 == 1) return false;
        pair<int,int>p = {0,0};
        int i=0;
        int j = s.length()-1;

        while(i<j){
            p.first += s[i]-'0';
            p.second += s[j]-'0';
            i++ , j--;
        }

        if(p.first == p.second) return true;
        return false;
    }

    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for(int i=low;i<=high;i++){
            count += firstAndSecondhalfSum(i);
        }

        return count;
    }
};