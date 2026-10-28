class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>> &dp, string &s, string &p){
        if(j==p.size()) return i==s.size();
        if(dp[i][j] != -1) return dp[i][j];
        //if(s[i]==p[j] || p[j]=='.') return dp[i][j] = dfs(i+1, j+1, dp, s, p);
        bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');
        if (j + 1 < p.size() && p[j + 1] == '*') 
            return dp[i][j] = dfs(i, j + 2, dp, s, p) || (match && dfs(i + 1, j, dp, s, p)); 
        return dp[i][j] = match && dfs(i+1, j+1, dp, s, p);
    }

    bool isMatch(string s, string p) {
        if(s==p) return true;
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        return dfs(0, 0, dp, s, p);
    }
};
