class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int i=0;
        int j=col-1;
        while(i<row && j>=0){
            int val = matrix[i][j];
            if(val<target){
                i++;
            }else if(val>target){
                j--;
            }else{
                return true;
            }
        }
        return false;
    }
};