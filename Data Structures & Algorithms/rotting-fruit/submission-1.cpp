class Solution {
public:
    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, 1, 0, -1};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==2) q.push({i, j});
                else if(grid[i][j]==1) fresh++;
            }
        }
        int time = 0;

        while(!q.empty() && fresh>0){
            int size = q.size();
            for(int k = 0; k<size; k++){
                auto [r,c] = q.front();
                q.pop();
                for(int i = 0; i<4; i++){
                    int nr = r+row[i];
                    int nc = c+col[i];
                    if(nr<0 || nc<0 || nr>=n || nc>=m || grid[nr][nc]!=1) continue;
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    fresh--;
                }
            }
            time++;
        }
        return fresh==0 ? time : -1;
    }
};
