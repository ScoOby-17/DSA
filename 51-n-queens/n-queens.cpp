class Solution {
public:
    bool isSafe(vector<string>&chess , int i , int j){
        int row = chess.size(); int col = chess[0].size();
        int n = chess.size();

        //check in col 
        for(int k=0;k<n;k++){
            if(chess[k][j]=='Q') return false;
        }

        //check in right to left daignol
        int r=i-1,c=j-1;
        while(r>=0 && c>=0){
            if(chess[r][c]=='Q') return false;
            r--,c--;
        }
        
        //check in left to right daignol
        r=i-1,c=j+1;
        while(r>=0 && c<n){
            if(chess[r][c]=='Q') return false;
            r--,c++;
        }

        return true;
    }

    void nQueen(vector<string>&chess , int& n , int row , vector<vector<string>>& ans){
        if(row == n){ ans.push_back(chess); return; }

        for(int j=0;j<n;j++){ // j is column
            bool isSafeLoaction = isSafe(chess , row , j);
            if(isSafeLoaction){
                chess[row][j]='Q';
                nQueen(chess , n , row+1 , ans);
                chess[row][j]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> chess(n, string(n, '.'));
        vector<vector<string>>ans;
        nQueen(chess , n , 0 , ans);
        return ans;
    }
};