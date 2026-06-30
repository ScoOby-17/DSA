class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int n = s.length();
        int l=0 , r=0;
        int a=0,b=0,c=0;
        
        while(r<n){
            if(s[r]=='a')a++;
            if(s[r]=='b')b++;
            if(s[r]=='c')c++;

            while(a && b && c){
                count += n-r;
                if(s[l]=='a')a--;
                if(s[l]=='b')b--;
                if(s[l]=='c')c--;

                l++;
            }
            r++;
        }

        return count;
    }
};