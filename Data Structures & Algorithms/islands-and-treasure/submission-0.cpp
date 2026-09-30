class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        //set<pair<int, int>> vis;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 0) q.push({i, j});
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            //int level = 0;
            int drow[] = {0, 1, 0, -1};
            int dcol[] = {1, 0, -1, 0};
            for(int i = 0; i<4; i++){
                int row = r + drow[i];
                int col = c + dcol[i];
                if(row<n && row>=0 && col<m && col>=0 && grid[row][col] == INT_MAX){
                    //vis.insert({row, col});
                    grid[row][col] = grid[r][c] + 1;
                    q.push({row, col});

                }
            }
        }
    }
};
