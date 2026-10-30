class Solution {
public:
    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, 1, 0, -1};

    void dfs(int r, int c, vector<vector<char>>& board){
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != 'O') {
            return;
        }

        board[r][c] = '#';

        for (int d = 0; d < 4; d++) {
            dfs(r + row[d], c + col[d], board);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][0]=='O') dfs(i, 0, board);
                if(board[i][m-1]=='O') dfs(i, m-1, board);            
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[0][j]=='O') dfs(0, j, board);
                if(board[n-1][j]=='O') dfs(n-1, j, board);
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j]=='O') board[i][j] = 'X';
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j]=='#') board[i][j] = 'O';
            }
        }
    }
};
