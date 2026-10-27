class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &dp, string &s, string &t){
        if(j>=t.size()) return 1;
        if(i>=s.size() && j!=t.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res = dfs(i+1, j, dp, s, t);
        if(s[i]==t[j]) res += dfs(i+1, j+1, dp, s, t);
        return dp[i][j] = res;
    }

    int numDistinct(string s, string t) {
        if(s.size() < t.size()) return 0;
        if(s == t) return 1;
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return dfs(0, 0, dp, s, t);
    }
};
