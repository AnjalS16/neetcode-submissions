class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &dp, string &word1, string &word2){
        if(i>=word1.size()) return word2.size()-j;
        if(j>=word2.size()) return word1.size()-i;
        if(dp[i][j] != -1) return dp[i][j];
        //int res = 0;
        if(word1[i] == word2[j]) dp[i][j] = dfs(i+1, j+1, dp, word1, word2);
        if(word1[i] != word2[j]) dp[i][j] = min({1+dfs(i, j+1, dp, word1, word2), 1+dfs(i+1, j, dp, word1, word2), 1+dfs(i+1, j+1, dp, word1, word2)});
        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        if(word1 == word2) return 0;
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return dfs(0, 0, dp, word1, word2);
    }
};
