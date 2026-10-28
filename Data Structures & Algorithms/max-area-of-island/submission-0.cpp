class Solution {
public:
    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, 1, 0, -1};
    int dfs(int r, int c, vector<vector<bool>> &vis, vector<vector<int>>& grid){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]==0 || vis[r][c]) return 0;
        int cnt = 1;
        vis[r][c] = true;
        for(int i = 0; i<4; i++){
            cnt += dfs(r+row[i], c+col[i], vis, grid);
        }
        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int maxarea = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==1){
                    int area = dfs(i, j, vis, grid);
                    maxarea = max(maxarea, area);
                }
            }
        }
        return maxarea;
    }
};
