class Solution {
public:
    void solve(vector<vector<char>>&arr , string& word , int idx , bool& ans , vector<vector<bool>>& isGet , int &row , int& col , int i , int j){
        if(ans || idx == word.length()){ ans = true ; return ;}

        //up
        if(j-1 > -1 && arr[i][j-1] == word[idx] && isGet[i][j-1] == false){
            isGet[i][j-1] = true;
            solve(arr , word , idx+1 , ans , isGet , row , col , i , j-1);
            isGet[i][j-1] = false;
        }
        //down
        if(j+1 < col && arr[i][j+1]==word[idx] && isGet[i][j+1] == false){
            isGet[i][j+1]=true;
            solve(arr , word , idx+1 , ans , isGet , row , col , i , j+1);
            isGet[i][j+1]=false;
        }
        //left
        if(i-1 > -1 && arr[i-1][j]==word[idx] && isGet[i-1][j] == false){
            isGet[i-1][j]=true;
            solve(arr , word , idx+1 , ans , isGet , row , col , i-1 , j);
            isGet[i-1][j]=false;
        }
        //right
        if(i+1 < row && arr[i+1][j]==word[idx] && isGet[i+1][j] == false){
            isGet[i+1][j]=true;
            solve(arr , word , idx+1 , ans , isGet , row , col , i+1 , j);
            isGet[i+1][j]=false;
        }

    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>>isGet(row , vector<bool>(col , false));
        bool ans = false;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0]){
                    isGet[i][j]=true;
                    solve(board , word , 1 , ans , isGet , row , col , i , j);
                    isGet[i][j]= false;
                }
                if(ans) break;
            }
            if(ans) break;
        }

        return ans;
    }
};