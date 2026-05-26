class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int nG = g.size();
        int nS = s.size();
        int childrenPointer = 0;
        int cookiePointer = 0;
        int count = 0;

        while(childrenPointer < nG && cookiePointer < nS){
            if(g[childrenPointer] <= s[cookiePointer]){
                cookiePointer++;
                childrenPointer++;
                count++;
            }else{
                cookiePointer++;
            }
        }

        return count;
    }
};