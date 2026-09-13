class Solution {
public:
    string addStrings(string num1, string num2) {
        string n1 = num1.length() >= num2.length() ? num1 : num2;
        string n2 = num1.length() >= num2.length() ? num2 : num1;

        string ans = "";
        int i = n1.length()-1;
        int j = n2.length()-1;
        bool isGT10 = false;
       
        while(i>=0){
            int sum = (n1[i]-'0');
            if(j >=0 ) sum += (n2[j]-'0');
            i-- , j--;
            if(isGT10) sum++;

            int lastVal = sum%10;
            ans.push_back(lastVal + '0');
            
            isGT10 = (sum > 9);
        }

        if(isGT10) ans.push_back('1');
        reverse(ans.begin(),ans.end());

        return ans;
    }
};