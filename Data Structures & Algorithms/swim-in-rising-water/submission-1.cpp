class Solution {
public:
    
    int row[4] = {0, 1, 0, -1};
    int col[4] = {1, 0, -1, 0};
    void dfs(int i, int j, int time, vector<vector<int>>& grid, vector<vector<int>> &dp){
        int n = grid.size();
        if (time >= dp[i][j]) return;
        dp[i][j] = time;
        if(i==n-1 && j==n-1) return;
        //if(dp[i][j]!=-1) return dp[i][j];
        for(int k = 0; k<4; k++){
            int nr = i+row[k];
            int nc = j+col[k];
            if(nr>=0 && nc>=0 && nr<n && nc<n){
                int newtime  = max(time, grid[nr][nc]);
                //dp[nr][nc] = time;
                dfs(nr, nc, newtime, grid, dp);
                
            }
        }
        //return time;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        int time = 0;
        dfs(0, 0, grid[0][0], grid, dp);
        return dp[n-1][n-1];
    }
};
