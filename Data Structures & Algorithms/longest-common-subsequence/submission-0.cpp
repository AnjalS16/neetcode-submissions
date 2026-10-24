class Solution {
public:
    int dfs(int i, int j, string &text1, string &text2, vector<vector<int>> &dp){
        if(i>=text1.size() || j>=text2.size()) return 0;
        if((text1[i]==text2[j]) && (i==text1.size()-1 || j==text2.size()-1)) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i]==text2[j]) dp[i][j] = 1+dfs(i+1, j+1, text1, text2, dp);
        if(text1[i]!=text2[j]) dp[i][j] = max(dfs(i+1, j, text1, text2, dp) , dfs(i, j+1, text1, text2, dp));
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return dfs(0, 0, text1, text2, dp);
    }
};
