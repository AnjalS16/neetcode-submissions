class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0},
                                         {0, 1}, {0, -1}};
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>> &vis,                  set<pair<int, int>> &st){
        st.insert({r, c});
        vis[r][c] = true;
        for (auto [dr, dc] : directions) {
            int nr = r + dr, nc = c + dc;
        if(nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() && !vis[nr][nc] && heights[nr][nc] >= heights[r][c]){
                    dfs(nr, nc, heights, vis, st);
                }
        }
    }
    

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        set<pair<int, int>> pacific;
        set<pair<int, int>> atlantic;
        vector<vector<int>> res;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                pacific.insert({i, 0});
                pacific.insert({0, j});
                atlantic.insert({i, m-1});
                atlantic.insert({n-1, j});
            }
        }
        vector<vector<bool>> vis1(n, vector<bool>(m, false));
        vector<vector<bool>> vis2(n, vector<bool>(m, false));
        for(auto [r,c] : pacific){
            dfs(r, c, heights, vis1, pacific);
        }
        for(auto [r,c] : atlantic){
            dfs(r, c, heights, vis2, atlantic);
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(pacific.count({i, j}) && atlantic.count({i, j})) res.push_back({i, j});
            }
        }
        return res;
    }
};
