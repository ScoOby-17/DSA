class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> ans(row, vector<int>(col, 0));

        if(k==0)return grid;

        for(int l=0;l<k;l++){
            
            for(int i=0;i<row;i++){
                for(int j=0;j<col-1;j++){
                    ans[i][j+1] = grid[i][j];
                }
                if(i < row-1){
                    ans[i+1][0] = grid[i][col-1];
                }
            }

            ans[0][0] = grid[row-1][col-1];
            grid = ans;
        }

        return ans;
    }
};