class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> dp;
    int dfs(int i, int j, vector<vector<int>>& matrix, int prevval){
        if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size() || matrix[i][j]<=prevval) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res = 1;
        for(vector<int> d : directions){
            res = max(res, 1 + dfs(i+d[0], j+d[1], matrix, matrix[i][j]));
        }
        dp[i][j] = res;
        return res;

    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp = vector<vector<int>> (matrix.size(), vector<int>(matrix[0].size(), -1));
        int lip = 0;
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                lip = max(lip, dfs(i, j, matrix, INT_MIN));
            }
        }
        return lip;
    }
};
