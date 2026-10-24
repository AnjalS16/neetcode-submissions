class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = dfs(i, j+1, m, n, dp) + dfs(i+1, j, m, n, dp);
    }

    int uniquePaths(int m, int n) {
        //no of unique paths
        //all boxes are accessible, no conditions
        vector<vector<int>> dp(m, vector<int>(n, -1));
        //int totalpaths = 0;
        return dfs(0, 0, m, n, dp);
        //return dp[m-1][n-1];
    }
};
