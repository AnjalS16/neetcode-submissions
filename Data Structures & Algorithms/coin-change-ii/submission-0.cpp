class Solution {
public:
    int dfs(int a, int i, vector<int>& coins, vector<vector<int>> &dp){
        if(a==0) return 1;
        if(i>=coins.size()) return 0;
        if(dp[i][a] != -1) return dp[i][a];
        int res = 0;
        if(a>=coins[i]){
            res = dfs(a, i+1, coins, dp) + dfs(a-coins[i], i, coins, dp);
            
        }
        dp[i][a] = res;
        dfs(a, 0, coins, dp);
        return res;
    }

    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        return dfs(amount, 0, coins, dp);
    }
};
