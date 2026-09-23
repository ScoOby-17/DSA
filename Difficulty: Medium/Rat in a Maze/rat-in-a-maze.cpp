class Solution {
  public:
  
    void solve(vector<vector<int>>& maze , int i , int j ,string& path , vector<vector<bool>>& arr , vector<string>&ans){
        int row = maze.size();
        int col = maze[0].size();
        
        if(i==row-1 && j==col-1) { ans.push_back(path); return; } // base case
        
        //down
        if(i<row-1 && arr[i+1][j] && maze[i+1][j]){
            path.push_back('D'); arr[i+1][j] = false;
            solve(maze , i+1 , j , path , arr , ans);
            path.pop_back();
            arr[i+1][j] = true;
        }
         //left
        if(j>0 && arr[i][j-1] && maze[i][j-1]){
            path.push_back('L'); arr[i][j-1] = false;
            solve(maze , i , j-1 , path , arr , ans);
            path.pop_back();
            arr[i][j-1] = true;
        }
        //right
        if(j+1<col && arr[i][j+1] && maze[i][j+1]){
            path.push_back('R'); arr[i][j+1] = false;
            solve(maze , i , j+1 , path , arr , ans);
            path.pop_back();
            arr[i][j+1] = true;
        }
        //up
        if(i>0 && arr[i-1][j] && maze[i-1][j]){
            path.push_back('U'); arr[i-1][j] = false;
            solve(maze , i-1 , j , path , arr , ans);
            path.pop_back();
            arr[i-1][j] = true;
        }
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<vector<bool>>arr;
        int row = maze.size();
        int col = maze[0].size();
        string path = "";
        vector<string>ans;
        if (maze[0][0] == 0 || maze[row-1][col-1] == 0) return ans;
        
        for(int i=0;i<row;i++){
            vector<bool>v;
            for(int j=0;j<col;j++){
                if(maze[i][j]==1) v.push_back(true);
                else v.push_back(false);
            }
            arr.push_back(v);
        }
        
        arr[0][0] = false;
        solve(maze , 0 , 0 , path , arr , ans);
        return ans;
    }
};